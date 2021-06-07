#include <sys/types.h>

#include <libretro.h>
#include <retro_math.h>

#include "libretro_core_options.h"

#include "mednafen/settings.h"
#include "mednafen/git.h"
#include "mednafen/wswan/wswan.h"
#include "mednafen/mempatcher.h"
#include "mednafen/wswan/gfx.h"
#include "mednafen/wswan/interrupt.h"
#include "mednafen/wswan/wswan-memory.h"
#include "mednafen/wswan/start.inc"
#include "mednafen/wswan/sound.h"
#include "mednafen/wswan/v30mz.h"
#include "mednafen/wswan/rtc.h"
#include "mednafen/wswan/eeprom.h"

#define MEDNAFEN_CORE_NAME_MODULE "wswan"
#define MEDNAFEN_CORE_NAME "Beetle WonderSwan"
#define MEDNAFEN_CORE_VERSION "v0.9.35.1"
#define MEDNAFEN_CORE_EXTENSIONS "ws|wsc|pc2"
#define MEDNAFEN_CORE_TIMING_FPS 75.47
#define MEDNAFEN_CORE_GEOMETRY_BASE_W (EmulatedWSwan.nominal_width)
#define MEDNAFEN_CORE_GEOMETRY_BASE_H (EmulatedWSwan.nominal_height)
#define MEDNAFEN_CORE_GEOMETRY_MAX_W 224
#define MEDNAFEN_CORE_GEOMETRY_MAX_H 144
#define MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO (14.0 / 9.0)
#define FB_WIDTH 224
#define FB_HEIGHT 144
#define FB_MAX_HEIGHT FB_HEIGHT

/* Forward declarations */
void MDFN_LoadGameCheats(void *override_ptr);
void MDFN_FlushGameCheats(int nosave);

/* core options */
static int RETRO_SAMPLE_RATE = 44100;

static int RETRO_PIX_BYTES = 2;
static int RETRO_PIX_DEPTH = 15;

struct retro_perf_callback perf_cb;
retro_get_cpu_features_t perf_get_cpu_features_cb = NULL;
retro_log_printf_t log_cb;
static retro_video_refresh_t video_cb;
static retro_audio_sample_t audio_cb;
static retro_audio_sample_batch_t audio_batch_cb;
static retro_environment_t environ_cb;
static retro_input_poll_t input_poll_cb;
static retro_input_state_t input_state_cb;

static bool libretro_supports_bitmasks = false;

static bool overscan;
static double last_sound_rate;

static bool rotate_tall               = false;
static bool rotate_tall_override      = false;
static bool select_pressed_last_frame = false;
static bool hw_rotate_enabled         = false;

static unsigned rotate_joymap = 0;

static MDFN_Surface *surf   = NULL;
static uint16_t *rotate_buf = NULL;

#define ROTATE_PIXEL_BUF(typename_t, src, width, height, dst)                            \
   {                                                                                     \
      typename_t *in_ptr  = (typename_t*)src;                                            \
      typename_t *out_ptr = (typename_t*)dst;                                            \
      size_t x, y;                                                                       \
      for (x = 0; x < width; x++)                                                        \
         for (y = 0; y < height; y++)                                                    \
            *(out_ptr + y + (((width - 1) - x) * height)) = *(in_ptr + x + (y * width)); \
   }

/* Mono palettes */

struct ws_mono_palette
{
   const char *name;
   uint32 start;
   uint32 end;
};

struct ws_mono_palette ws_mono_palettes[] = {
   { "default",                0x000000, 0xFFFFFF },
   { "wonderswan",             0x3E3D20, 0x9B9D66 },
   { "wondeswan_color",        0x1B201E, 0xD7D49D },
   { "swancrystal",            0x151108, 0xFFFCCA },
   { "gb_dmg",                 0x00420C, 0x578200 },
   { "gb_pocket",              0x2A3325, 0xA7B19A },
   { "gb_light",               0x00778D, 0x01CBDF },
   { "blossom_pink",           0x180F0F, 0xF09898 },
   { "bubbles_blue",           0x0D1418, 0x88D0F0 },
   { "buttercup_green",        0x12160D, 0xB8E088 },
   { "digivice",               0x000000, 0x8C8C73 },
   { "game_com",               0x000000, 0xA7BF6B },
   { "gameking",               0x184221, 0x8CCE94 },
   { "game_master",            0x2D2D2B, 0x829FA6 },
   { "golden_wild",            0x120F0A, 0xB99F65 },
   { "greenscale",             0x0C360C, 0x9CBE0C },
   { "hokage_orange",          0x170D08, 0xEA8352 },
   { "labo_fawn",              0x15110B, 0xD7AA73 },
   { "legendary_super_saiyan", 0x101509, 0xA5DB5A },
   { "microvision",            0x303030, 0xA0A0A0 },
   { "million_live_gold",      0x141109, 0xCDB261 },
   { "odyssey_gold",           0x131000, 0xC2A000 },
   { "shiny_sky_blue",         0x0E1216, 0x8CB6DF },
   { "slime_blue",             0x040E14, 0x2F8CCC },
   { "ti_83",                  0x181810, 0x9CA684 },
   { "travel_wood",            0x482810, 0xF8D8B0 },
   { "virtual_boy",            0x000000, 0xE30000 },
   { NULL, 0, 0 },
};

static uint32 mono_pal_start = 0x000000;
static uint32 mono_pal_end   = 0xFFFFFF;

static bool find_mono_palette(const char* name,
      uint32 *start, uint32 *end)
{
   bool palette_found = false;
   unsigned i;

   for (i = 0; ws_mono_palettes[i].name; i++)
   {
      if (!strcmp(ws_mono_palettes[i].name, name))
      {
         *start        = ws_mono_palettes[i].start;
         *end          = ws_mono_palettes[i].end;
         palette_found = true;
         break;
      }
   }

   if (!palette_found)
   {
      *start = 0x000000;
      *end   = 0xFFFFFF;
   }

   return palette_found;
}

/* Frameskipping */

static unsigned frameskip_type             = 0;
static unsigned frameskip_threshold        = 0;
static uint16_t frameskip_counter          = 0;

static bool retro_audio_buff_active        = false;
static unsigned retro_audio_buff_occupancy = 0;
static bool retro_audio_buff_underrun      = false;
/* Maximum number of consecutive frames that
 * can be skipped */
#define FRAMESKIP_MAX 30

static unsigned audio_latency              = 0;
static bool update_audio_latency           = false;

static void retro_audio_buff_status_cb(
      bool active, unsigned occupancy, bool underrun_likely)
{
   retro_audio_buff_active    = active;
   retro_audio_buff_occupancy = occupancy;
   retro_audio_buff_underrun  = underrun_likely;
}

static void init_frameskip(void)
{
   if (frameskip_type > 0)
   {
      struct retro_audio_buffer_status_callback buf_status_cb;

      buf_status_cb.callback = retro_audio_buff_status_cb;
      if (!environ_cb(RETRO_ENVIRONMENT_SET_AUDIO_BUFFER_STATUS_CALLBACK,
            &buf_status_cb))
      {
         if (log_cb)
            log_cb(RETRO_LOG_WARN, "Frameskip disabled - frontend does not support audio buffer status monitoring.\n");

         retro_audio_buff_active    = false;
         retro_audio_buff_occupancy = 0;
         retro_audio_buff_underrun  = false;
         audio_latency              = 0;
      }
      else
      {
         /* Frameskip is enabled - increase frontend
          * audio latency to minimise potential
          * buffer underruns */
         float frame_time_msec = 1000.0f / ((float)MEDNAFEN_CORE_TIMING_FPS);

         /* Set latency to 8x current frame time...
          * (for 60Hz cores we normally use a 6x
          * multiplier - but the WonderSwan runs
          * at an unusually high frame rate, which
          * seems to place greater demands on the
          * frontend. Increasing the multiplier to
          * 8x gives the frontend more room to
          * manoeuvre, and improves the efficacy of
          * the 'Auto' frameskip setting) */
         audio_latency = (unsigned)((8.0f * frame_time_msec) + 0.5f);

         /* ...then round up to nearest multiple of 32 */
         audio_latency = (audio_latency + 0x1F) & ~0x1F;
      }
   }
   else
   {
      environ_cb(RETRO_ENVIRONMENT_SET_AUDIO_BUFFER_STATUS_CALLBACK, NULL);
      audio_latency = 0;
   }

   update_audio_latency = true;
}

/* Cygne
 *
 * Copyright notice for this file:
 *  Copyright (C) 2002 Dox dox@space.pl
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

int 		wsc = 1;			/*color/mono*/
uint32		rom_size;

uint16 WSButtonStatus;

static uint8 WSRCurrentSong;

MDFNGI EmulatedWSwan =
{
 MDFN_MASTERCLOCK_FIXED(3072000),
 0,
 224,   /* lcm_width */
 144,   /* lcm_height */

 224,	  /* Nominal width */
 144,	  /* Nominal height */

 224,	  /* Framebuffer width */
 144,	  /* Framebuffer height */

 2,     /* Number of output sound channels */
};


static void Reset(void)
{
   int		u0;

   v30mz_reset();				/* Reset CPU */
   WSwan_MemoryReset();
   WSwan_GfxReset();
   WSwan_SoundReset();
   WSwan_InterruptReset();
   WSwan_RTCReset();
   WSwan_EEPROMReset();

   for(u0=0;u0<0xc9;u0++)
   {
      if(u0 != 0xC4 && u0 != 0xC5 && u0 != 0xBA && u0 != 0xBB)
         WSwan_writeport(u0,startio[u0]);
   }

   v30mz_set_reg(NEC_SS,0);
   v30mz_set_reg(NEC_SP,0x2000);
}

static uint8 *chee;

static void Emulate(EmulateSpecStruct *espec, int16_t *sndbuf)
{
   uint16 butt_data;

   espec->DisplayRect.x = 0;
   espec->DisplayRect.y = 0;
   espec->DisplayRect.w = 224;
   espec->DisplayRect.h = 144;

   if(espec->VideoFormatChanged)
      WSwan_SetPixelFormat(espec->surface->depth,
            mono_pal_start, mono_pal_end);

   if(espec->SoundFormatChanged)
      WSwan_SetSoundRate(RETRO_SAMPLE_RATE);

   butt_data = chee[0] | (chee[1] << 8);

   WSButtonStatus = butt_data;

   MDFNMP_ApplyPeriodicCheats();

   while(!wsExecuteLine(espec->surface, espec->skip));

   espec->SoundBufSize = WSwan_SoundFlush(sndbuf, espec->SoundBufMaxSize);

   espec->MasterCycles = v30mz_timestamp;
   v30mz_timestamp = 0;
}

typedef struct
{
 const uint8 id;
 const char *name;
} DLEntry;

static const DLEntry Developers[] =
{
 { 0x01, "Bandai" },
 { 0x02, "Taito" },
 { 0x03, "Tomy" },
 { 0x04, "Koei" },
 { 0x05, "Data East" },
 { 0x06, "Asmik" }, /* Asmik Ace? */
 { 0x07, "Media Entertainment" },
 { 0x08, "Nichibutsu" },
 { 0x0A, "Coconuts Japan" },
 { 0x0B, "Sammy" },
 { 0x0C, "Sunsoft" },
 { 0x0D, "Mebius" },
 { 0x0E, "Banpresto" },
 { 0x10, "Jaleco" },
 { 0x11, "Imagineer" },
 { 0x12, "Konami" },
 { 0x16, "Kobunsha" },
 { 0x17, "Bottom Up" },
 { 0x18, "Kaga Tech" },
 { 0x19, "Sunrise" },
 { 0x1A, "Cyber Front" },
 { 0x1B, "Mega House" },
 { 0x1D, "Interbec" },
 { 0x1E, "Nihon Application" },
 { 0x1F, "Bandai Visual" },
 { 0x20, "Athena" },
 { 0x21, "KID" },
 { 0x22, "HAL Corporation" },
 { 0x23, "Yuki Enterprise" },
 { 0x24, "Omega Micott" },
 { 0x25, "Layup" },
 { 0x26, "Kadokawa Shoten" },
 { 0x27, "Shall Luck" },
 { 0x28, "Squaresoft" },
 { 0x2B, "Tom Create" },
 { 0x2D, "Namco" },
 { 0x2E, "Movic" }, /* ???? */
 { 0x2F, "E3 Staff" }, /* ???? */
 { 0x31, "Vanguard" },
 { 0x32, "Megatron" },
 { 0x33, "Wiz" },
 { 0x36, "Capcom" }
};

static uint32 SRAMSize;

static int Load(const uint8_t *data, size_t size)
{
   uint32 pow_size      = 0;
   uint32 real_rom_size = 0;
   uint8 header[10];

   if(size < 65536)
      return(0);

   real_rom_size = (size + 0xFFFF) & ~0xFFFF;
   pow_size      = next_pow2(real_rom_size);
   rom_size      = pow_size + (pow_size == 0);

   wsCartROM     = (uint8 *)calloc(1, rom_size);

   /* This real_rom_size vs rom_size funny business 
    * is intended primarily for handling
    * WSR files. */
   if(real_rom_size < rom_size)
      memset(wsCartROM, 0xFF, rom_size - real_rom_size);

   memcpy(wsCartROM + (rom_size - real_rom_size), data, size);

   memcpy(header, wsCartROM + rom_size - 10, 10);

   SRAMSize = 0;
   eeprom_size = 0;

   switch(header[5])
   {
      case 0x01: SRAMSize =   8 * 1024; break;
      case 0x02: SRAMSize =  32 * 1024; break;
      case 0x03: SRAMSize = 128 * 1024; break;
      case 0x04: SRAMSize = 256 * 1024; break; /* Dicing Knight!, Judgement Silver */
      case 0x05: SRAMSize = 512 * 1024; break; /* Wonder Gate */

      case 0x10: eeprom_size = 128; break;
      case 0x20: eeprom_size = 2 *1024; break;
      case 0x50: eeprom_size = 1024; break;
   }

   if((header[8] | (header[9] << 8)) == 0x8de1 && (header[0]==0x01)&&(header[2]==0x27)) /* Detective Conan */
   {
      /* WS cpu is using cache/pipeline or there's protected ROM bank where pointing CS */
      wsCartROM[0xfffe8]=0xea;
      wsCartROM[0xfffe9]=0x00;
      wsCartROM[0xfffea]=0x00;
      wsCartROM[0xfffeb]=0x00;
      wsCartROM[0xfffec]=0x20;
   }

   if(header[6] & 0x1)
      EmulatedWSwan.rotated = MDFN_ROTATE90;

   MDFNMP_Init(16384, (1 << 20) / 1024);

   v30mz_init(WSwan_readmem20, WSwan_writemem20, WSwan_readport, WSwan_writeport);
   WSwan_MemoryInit(MDFN_GetSettingB("wswan.language"), wsc, SRAMSize, false); /* EEPROM and SRAM are loaded in this func. */
   WSwan_GfxInit();
   EmulatedWSwan.fps = (uint32)((uint64)3072000 * 65536 * 256 / (159*256));

   WSwan_SoundInit();

   wsMakeTiles();

   Reset();

   return(1);
}

static void CloseGame(void)
{
   WSwan_MemoryKill();

   WSwan_SoundKill();

   if(wsCartROM)
   {
      free(wsCartROM);
      wsCartROM = NULL;
   }
}

static void SetInput(int port, const char *type, void *ptr)
{
 if(!port) chee = (uint8 *)ptr;
}

int StateAction(StateMem *sm, int load, int data_only)
{
   if(!v30mz_StateAction(sm, load, data_only))
      return(0);

   /* Call MemoryStateAction before others StateActions... */
   if(!WSwan_MemoryStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_GfxStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_RTCStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_InterruptStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_SoundStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_EEPROMStateAction(sm, load, data_only))
      return(0);

   return(1);
}

static void DoSimpleCommand(int cmd)
{
   switch(cmd)
   {
      case MDFN_MSC_POWER:
      case MDFN_MSC_RESET:
         Reset();
         break;
   }
}

static const InputDeviceInputInfoStruct IDII[] =
{
 { "up-x", "UP ↑, X Cursors", 0, IDIT_BUTTON, "down-x",				{ "right-x", "down-x", "left-x" } },
 { "right-x", "RIGHT →, X Cursors", 3, IDIT_BUTTON, "left-x",			{ "down-x", "left-x", "up-x" } },
 { "down-x", "DOWN ↓, X Cursors", 1, IDIT_BUTTON, "up-x", 			{ "left-x", "up-x", "right-x" } },
 { "left-x", "LEFT ←, X Cursors", 2, IDIT_BUTTON, "right-x",			{ "up-x", "right-x", "down-x" } },

 { "up-y", "UP ↑, Y Cur: MUST NOT = X CURSORS", 4, IDIT_BUTTON, "down-y",	{ "right-y", "down-y", "left-y" } },
 { "right-y", "RIGHT →, Y Cur: MUST NOT = X CURSORS", 7, IDIT_BUTTON, "left-y",	{ "down-y", "left-y", "up-y" } },
 { "down-y", "DOWN ↓, Y Cur: MUST NOT = X CURSORS", 5, IDIT_BUTTON, "up-y",	{ "left-y", "up-y", "right-y" } },
 { "left-y", "LEFT ←, Y Cur: MUST NOT = X CURSORS", 6, IDIT_BUTTON, "right-y",	{ "up-y", "right-y", "down-y" } },

 { "start", "Start", 8, IDIT_BUTTON, NULL },
 { "a", "A", 10, IDIT_BUTTON_CAN_RAPID,  NULL },
 { "b", "B", 9, IDIT_BUTTON_CAN_RAPID, NULL },
};

static InputDeviceInfoStruct InputDeviceInfo[] =
{
 {
  "gamepad",
  "Gamepad",
  NULL,
  NULL,
  sizeof(IDII) / sizeof(InputDeviceInputInfoStruct),
  IDII,
 }
};

static const InputPortInfoStruct PortInfo[] =
{
 { "builtin", "Built-In", sizeof(InputDeviceInfo) / sizeof(InputDeviceInfoStruct), InputDeviceInfo, "gamepad" }
};

static InputInfoStruct InputInfo =
{
 sizeof(PortInfo) / sizeof(InputPortInfoStruct),
 PortInfo
};

static bool update_video, update_audio;

static bool MDFNI_LoadGame(
      const char *force_module, const uint8_t *data,
      size_t size)
{
   if(Load(data, size) <= 0)
      return false;

	MDFN_LoadGameCheats(NULL);
	MDFNMP_InstallReadPatches();

   return true;
}

static void MDFNI_CloseGame(void)
{
   MDFN_FlushGameCheats(0);

   CloseGame();

   MDFNMP_Kill();
}

static void check_system_specs(void)
{
   /* TODO - should theoretically be level 4, but apparently
    * doesn't run at fullspeed on PSP (yet) */
   unsigned level = 4;
   environ_cb(RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL, &level);
}

static void check_depth(void)
{
   if (RETRO_PIX_DEPTH == 24)
   {
      enum retro_pixel_format rgb888 = RETRO_PIXEL_FORMAT_XRGB8888;

      if (!environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &rgb888))
      {
         if (log_cb) log_cb(RETRO_LOG_ERROR, "Pixel format XRGB8888 not supported by platform.\n");

         RETRO_PIX_BYTES = 2;
         RETRO_PIX_DEPTH = 15;
      }
   }

#if defined(FRONTEND_SUPPORTS_RGB565)
   if (RETRO_PIX_BYTES == 2)
   {
      enum retro_pixel_format rgb565 = RETRO_PIXEL_FORMAT_RGB565;

      if (environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &rgb565))
      {
         if (log_cb) log_cb(RETRO_LOG_INFO, "Frontend supports RGB565 - will use that instead of XRGB1555.\n");

         RETRO_PIX_DEPTH = 16;
      }
   }
#endif
}

static void rotate_display(void)
{
   if (hw_rotate_enabled)
   {
      struct retro_game_geometry new_geom = {
            FB_WIDTH,
            FB_HEIGHT,
            FB_WIDTH,
            FB_HEIGHT,
            rotate_tall ? (9.0 / 14.0) : (14.0 / 9.0)
      };
      unsigned rot_angle = rotate_tall ?
            1 : /* 90 degrees */
            0;  /* 0 degrees  */

      environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, (void*)&new_geom);
      environ_cb(RETRO_ENVIRONMENT_SET_ROTATION, (void*)&rot_angle);
   }
   else
   {
      struct retro_game_geometry new_geom = {
            rotate_tall ? FB_HEIGHT : FB_WIDTH,
            rotate_tall ? FB_WIDTH  : FB_HEIGHT,
            FB_WIDTH,
            FB_WIDTH,
            rotate_tall ? (9.0 / 14.0) : (14.0 / 9.0)
      };

      environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, (void*)&new_geom);
   }
}

static void check_variables(int startup)
{
   struct retro_variable var = {0};
   uint32 prev_mono_pal_start;
   uint32 prev_mono_pal_end;
   unsigned prev_frameskip_type;

   var.key = "wswan_rotate_display",
   var.value = NULL;

   rotate_tall_override = false;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
      if (!strcmp(var.value, "enabled"))
         rotate_tall_override = true;

   if (rotate_tall_override && !rotate_tall)
   {
      rotate_tall = true;
      rotate_display();
   }

   var.key = "wswan_rotate_keymap",
   var.value = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
   {
      if (!strcmp(var.value, "disabled"))
         rotate_joymap = 0;
      else if (!strcmp(var.value, "enabled"))
         rotate_joymap = 1;
      else if (!strcmp(var.value, "auto"))
         rotate_joymap = 2;
   }

   var.key = "wswan_mono_palette",
   var.value = NULL;

   prev_mono_pal_start = mono_pal_start;
   prev_mono_pal_end   = mono_pal_end;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
      find_mono_palette(var.value, &mono_pal_start, &mono_pal_end);

   if ((mono_pal_start != prev_mono_pal_start) ||
       (mono_pal_end   != prev_mono_pal_end))
      WSwan_SetMonoPalette(RETRO_PIX_DEPTH, mono_pal_start, mono_pal_end);

   var.key = "wswan_frameskip";
   var.value = NULL;

   prev_frameskip_type = frameskip_type;
   frameskip_type      = 0;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
   {
      if (strcmp(var.value, "auto") == 0)
         frameskip_type = 1;
      else if (strcmp(var.value, "manual") == 0)
         frameskip_type = 2;
   }

   var.key = "wswan_frameskip_threshold";
   var.value = NULL;

   frameskip_threshold = 33;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
      frameskip_threshold = strtol(var.value, NULL, 10);

   /* (Re)Initialise frameskipping, if required */
   if (startup || (frameskip_type != prev_frameskip_type))
      init_frameskip();

   var.key = "wswan_sound_sample_rate";
   var.value = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value)
   {
      int old_value = RETRO_SAMPLE_RATE;

      RETRO_SAMPLE_RATE = atoi(var.value);

      if (old_value != RETRO_SAMPLE_RATE)
         update_audio = true;
   }

   var.key = "wswan_gfx_colors";
   var.value = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value && startup)
   {
      unsigned old_value = RETRO_PIX_BYTES;

      if (!strcmp(var.value, "16bit"))
      {
         RETRO_PIX_BYTES = 2;
         RETRO_PIX_DEPTH = 16;
      }
      else if (!strcmp(var.value, "24bit"))
      {
         RETRO_PIX_BYTES = 4;
         RETRO_PIX_DEPTH = 24;
      }

      if (old_value != RETRO_PIX_BYTES)
         update_video = true;
   }
}

void retro_init(void)
{
   struct retro_log_callback log;
   if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log))
      log_cb = log.log;
   else 
      log_cb = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_PERF_INTERFACE, &perf_cb))
      perf_get_cpu_features_cb = perf_cb.get_cpu_features;
   else
      perf_get_cpu_features_cb = NULL;

   frameskip_type             = 0;
   frameskip_threshold        = 0;
   frameskip_counter          = 0;
   retro_audio_buff_active    = false;
   retro_audio_buff_occupancy = 0;
   retro_audio_buff_underrun  = false;
   audio_latency              = 0;
   update_audio_latency       = false;

   check_system_specs();
   check_variables(true);
   check_depth();

   if (environ_cb(RETRO_ENVIRONMENT_GET_INPUT_BITMASKS, NULL))
      libretro_supports_bitmasks = true;
}

void retro_reset(void)
{
   DoSimpleCommand(MDFN_MSC_RESET);
}

bool retro_load_game_special(unsigned a, const struct retro_game_info *b, size_t c)
{
   return false;
}

static void set_volume (uint32_t *ptr, unsigned number)
{
   switch(number)
   {
      default:
         *ptr = number;
         break;
   }
}

#define MAX_PLAYERS 1
#define MAX_BUTTONS 11
static uint16_t input_buf;

bool retro_load_game(const struct retro_game_info *info)
{
   const unsigned rot_angle = 0;

   struct retro_input_descriptor desc[] = {
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_LEFT, "X Cursor Left" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_UP, "X Cursor Up" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_DOWN, "X Cursor Down" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_RIGHT, "X Cursor Right" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_L, "Y Cursor Left" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_R2, "Y Cursor Up" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_L2, "Y Cursor Down" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_R, "Y Cursor Right" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_A, "A" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_B, "B" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_START, "Start" },
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_SELECT, "Rotate screen + active D-Pad" },

      { 0 },
   };

   if (!info)
      return false;

   environ_cb(RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS, desc);

   overscan = false;
   environ_cb(RETRO_ENVIRONMENT_GET_OVERSCAN, &overscan);

   if (!MDFNI_LoadGame(MEDNAFEN_CORE_NAME_MODULE,
         (const uint8_t*)info->data, info->size))
      return false;

   SetInput(0, "gamepad", &input_buf);

   surf = (MDFN_Surface*)calloc(1, sizeof(*surf));
   
   if (!surf)
      return false;
   
   surf->width  = FB_WIDTH;
   surf->height = FB_HEIGHT;
   surf->pitch  = FB_WIDTH;
   surf->depth  = RETRO_PIX_DEPTH;

   surf->pixels = (uint16_t*)calloc(1, FB_WIDTH * FB_HEIGHT * sizeof(uint32_t));

   if (!surf->pixels)
   {
      free(surf);
      surf = NULL;
      return false;
   }

   /* Check whether 'hardware' rotation (via frontend
    * gfx driver) is supported */
   hw_rotate_enabled = environ_cb(RETRO_ENVIRONMENT_SET_ROTATION, (void*)&rot_angle);

   if (!hw_rotate_enabled && !rotate_buf)
   {
      rotate_buf = (uint16_t*)calloc(1, FB_WIDTH * FB_HEIGHT * sizeof(uint32_t));
      if (!rotate_buf)
      {
         free(surf->pixels);
         free(surf);
         surf = NULL;
         return false;
      }
   }

   rotate_tall = false;
   select_pressed_last_frame = false;
   rotate_joymap = 0;

   check_variables(false);

   WSwan_SetPixelFormat(RETRO_PIX_DEPTH,
         mono_pal_start, mono_pal_end);

   update_video = false;
   update_audio = true;

   return true;
}

void retro_unload_game(void)
{
   MDFNI_CloseGame();

   if (surf)
   {
      if (surf->pixels)
         free(surf->pixels);
      free(surf);
   }
   surf = NULL;

   if (rotate_buf)
      free(rotate_buf);
   rotate_buf = NULL;
}

static void update_input(void)
{
   static unsigned map[2][11] = {
      {
         RETRO_DEVICE_ID_JOYPAD_UP,    /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_RIGHT, /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_DOWN,  /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_LEFT,  /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_R2,    /* Y Cursor UP vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_R,     /* Y Cursor RIGHT vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_L2,    /* Y Cursor DOWN vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_L,     /* Y Cursor LEFT vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_START,
         RETRO_DEVICE_ID_JOYPAD_A,
         RETRO_DEVICE_ID_JOYPAD_B,
      },
      {
         RETRO_DEVICE_ID_JOYPAD_Y,     /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_X,     /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_A,     /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_B,     /* X Cursor horizontal-layout games */
         RETRO_DEVICE_ID_JOYPAD_LEFT,  /* Y Cursor UP vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_UP,    /* Y Cursor RIGHT vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_RIGHT, /* Y Cursor DOWN vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_DOWN,  /* Y Cursor LEFT vertical-layout games */
         RETRO_DEVICE_ID_JOYPAD_START,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
      }
   };
   unsigned i;
   int16_t bitmask = 0;
   bool select_button;
   bool joymap;
#ifdef MSB_FIRST
   union {
      uint8_t b[2];
      uint16_t s;
   } u;
#endif

   input_buf = 0;

   if (libretro_supports_bitmasks)
      bitmask = input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_MASK);
   else
   {
      for (i = 0; i < (RETRO_DEVICE_ID_JOYPAD_R3+1); i++)
         bitmask |= input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, i) ? 1 << i : 0;
   }

   select_button = bitmask & (1 << RETRO_DEVICE_ID_JOYPAD_SELECT);
   if (!rotate_tall_override &&
       select_button &&
       !select_pressed_last_frame)
   {
      rotate_tall = !rotate_tall;
      rotate_display();
   }
   select_pressed_last_frame = select_button;

   joymap = (rotate_joymap == 2) ? rotate_tall : (rotate_joymap ? true : false);

   for (i = 0; i < MAX_BUTTONS; i++)
      input_buf |= map[joymap][i] != -1u && ((1 << map[joymap][i]) & bitmask) ? (1 << i) : 0;

#ifdef MSB_FIRST
   u.s = input_buf;
   input_buf = u.b[0] | u.b[1] << 8;
#endif
}

static uint64_t video_frames, audio_frames;

void retro_run(void)
{
   int total;
   unsigned width, height;
   static MDFN_Rect rects[FB_MAX_HEIGHT];
   static int16_t sound_buf[0x10000];
   int32 SoundBufSize;
   EmulateSpecStruct spec;
   bool updated   = false;
   int skip_frame = 0;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE, &updated) && updated)
      check_variables(false);

   input_poll_cb();

   update_input();

   /* Check whether current frame should
    * be skipped */
   if ((frameskip_type > 0) && retro_audio_buff_active)
   {
      switch (frameskip_type)
      {
         case 1: /* auto */
            skip_frame = retro_audio_buff_underrun ? 1 : 0;
            break;
         case 2: /* manual */
            skip_frame = (retro_audio_buff_occupancy < frameskip_threshold) ? 1 : 0;
            break;
         default:
            skip_frame = 0;
            break;
      }

      if (!skip_frame ||
          (frameskip_counter >= FRAMESKIP_MAX))
      {
         skip_frame        = 0;
         frameskip_counter = 0;
      }
      else
         frameskip_counter++;
   }

   /* If frameskip settings have changed, update
    * frontend audio latency */
   if (update_audio_latency)
   {
      environ_cb(RETRO_ENVIRONMENT_SET_MINIMUM_AUDIO_LATENCY,
            &audio_latency);
      update_audio_latency = false;
   }

   rects[0].w = ~0;

   spec.surface            = surf;
   spec.VideoFormatChanged = update_video;
   spec.DisplayRect.x      = 0;
   spec.DisplayRect.y      = 0;
   spec.DisplayRect.w      = 0;
   spec.DisplayRect.h      = 0;
   spec.LineWidths         = rects;
   spec.skip               = skip_frame;
   spec.SoundFormatChanged = update_audio;
   spec.SoundBufMaxSize    = sizeof(sound_buf) >> 1;
   spec.SoundBufSize       = 0;
   spec.SoundBufSizeALMS   = 0;
   spec.MasterCycles       = 0;
   spec.MasterCyclesALMS   = 0;

   if (update_video || update_audio)
   {
      struct retro_system_av_info system_av_info;

      if (update_video)
      {
         memset(&system_av_info, 0, sizeof(system_av_info));
         environ_cb(RETRO_ENVIRONMENT_SET_SYSTEM_AV_INFO, &system_av_info);
      }

      retro_get_system_av_info(&system_av_info);
      environ_cb(RETRO_ENVIRONMENT_SET_SYSTEM_AV_INFO, &system_av_info);

      if (update_video)
	     rotate_display();

      surf->depth = RETRO_PIX_DEPTH;

      update_video = false;
      update_audio = false;
   }

   Emulate(&spec, sound_buf);

   SoundBufSize      = spec.SoundBufSize - spec.SoundBufSizeALMS;
   spec.SoundBufSize = spec.SoundBufSizeALMS + SoundBufSize;

   width             = spec.DisplayRect.w;
   height            = spec.DisplayRect.h;

   if (hw_rotate_enabled || !rotate_tall)
   {
      if (!skip_frame)
         video_cb(surf->pixels, width, height, FB_WIDTH * RETRO_PIX_BYTES);
      else
         video_cb(NULL, width, height, FB_WIDTH * RETRO_PIX_BYTES);
   }
   else
   {
      if (!skip_frame)
      {
         /* Perform software-based display rotation */
         if (RETRO_PIX_BYTES == 4)
            ROTATE_PIXEL_BUF(
                  uint32_t, surf->pixels, width, height, rotate_buf)
         else
            ROTATE_PIXEL_BUF(
                  uint16_t, surf->pixels, width, height, rotate_buf)

         video_cb(rotate_buf, height, width, FB_HEIGHT * RETRO_PIX_BYTES);
      }
      else
         video_cb(NULL, height, width, FB_HEIGHT * RETRO_PIX_BYTES);
   }

   video_frames++;
   audio_frames += spec.SoundBufSize;

   for (total = 0; total < spec.SoundBufSize; )
      total += audio_batch_cb(sound_buf + total*2,
            spec.SoundBufSize - total);
}

void retro_get_system_info(struct retro_system_info *info)
{
   memset(info, 0, sizeof(*info));
   info->library_name     = MEDNAFEN_CORE_NAME;
#ifndef GIT_VERSION
#define GIT_VERSION ""
#endif
   info->library_version  = MEDNAFEN_CORE_VERSION GIT_VERSION;
   info->need_fullpath    = false;
   info->valid_extensions = MEDNAFEN_CORE_EXTENSIONS;
   info->block_extract    = false;
}

void retro_get_system_av_info(struct retro_system_av_info *info)
{
   memset(info, 0, sizeof(*info));

   info->timing.fps               = MEDNAFEN_CORE_TIMING_FPS;
   info->timing.sample_rate       = RETRO_SAMPLE_RATE;

   if (hw_rotate_enabled || !rotate_tall)
   {
      info->geometry.base_width   = MEDNAFEN_CORE_GEOMETRY_BASE_W;
      info->geometry.base_height  = MEDNAFEN_CORE_GEOMETRY_BASE_H;
   }
   else
   {
      info->geometry.base_width   = MEDNAFEN_CORE_GEOMETRY_BASE_H;
      info->geometry.base_height  = MEDNAFEN_CORE_GEOMETRY_BASE_W;
   }

   info->geometry.max_width       = MEDNAFEN_CORE_GEOMETRY_MAX_W;
   if (hw_rotate_enabled)
      info->geometry.max_height   = MEDNAFEN_CORE_GEOMETRY_MAX_H;
   else
      info->geometry.max_height   = MEDNAFEN_CORE_GEOMETRY_MAX_W;

   if (rotate_tall)
      info->geometry.aspect_ratio = 1.0f / MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO;
   else
      info->geometry.aspect_ratio = MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO;

   check_depth();
}

void retro_deinit(void)
{
   if (surf)
   {
      if (surf->pixels)
         free(surf->pixels);
      free(surf);
   }
   surf = NULL;

   if (rotate_buf)
      free(rotate_buf);
   rotate_buf = NULL;

   if (log_cb)
   {
      log_cb(RETRO_LOG_INFO, "[%s]: Samples / Frame: %.5f\n",
            MEDNAFEN_CORE_NAME, (double)audio_frames / video_frames);
      log_cb(RETRO_LOG_INFO, "[%s]: Estimated FPS: %.5f\n",
            MEDNAFEN_CORE_NAME, (double)video_frames * 44100 / audio_frames);
   }

   libretro_supports_bitmasks = false;
}

unsigned retro_get_region(void)
{
   return RETRO_REGION_NTSC; /* FIXME: Regions for other cores. */
}

unsigned retro_api_version(void)
{
   return RETRO_API_VERSION;
}

void retro_set_controller_port_device(unsigned in_port, unsigned device) { }

void retro_set_environment(retro_environment_t cb)
{
   environ_cb = cb;

   libretro_set_core_options(environ_cb);
}

void retro_set_audio_sample(retro_audio_sample_t cb)
{
}

void retro_set_audio_sample_batch(retro_audio_sample_batch_t cb)
{
   audio_batch_cb = cb;
}

void retro_set_input_poll(retro_input_poll_t cb)
{
   input_poll_cb = cb;
}

void retro_set_input_state(retro_input_state_t cb)
{
   input_state_cb = cb;
}

void retro_set_video_refresh(retro_video_refresh_t cb)
{
   video_cb = cb;
}

size_t retro_serialize_size(void)
{
   StateMem st;

   st.data           = NULL;
   st.loc            = 0;
   st.len            = 0;
   st.malloced       = 0;
   st.initial_malloc = 0;

   if (!MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL))
      return 0;

   free(st.data);

   return st.len;
}

bool retro_serialize(void *data, size_t size)
{
   StateMem st;
   bool ret          = false;
   uint8_t *_dat     = (uint8_t*)malloc(size);

   if (!_dat)
      return false;

   /* Mednafen can realloc the buffer so we need to ensure this is safe. */
   st.data           = _dat;
   st.loc            = 0;
   st.len            = 0;
   st.malloced       = size;
   st.initial_malloc = 0;

   ret = MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL);

   memcpy(data, st.data, size);
   free(st.data);

   return ret;
}

bool retro_unserialize(const void *data, size_t size)
{
   StateMem st;

   st.data           = (uint8_t*)data;
   st.loc            = 0;
   st.len            = size;
   st.malloced       = 0;
   st.initial_malloc = 0;

   return MDFNSS_LoadSM(&st, 0, 0);
}

void *retro_get_memory_data(unsigned type)
{
   switch (type)
   {
      case RETRO_MEMORY_SAVE_RAM:
         if (eeprom_size)
            return (uint8_t*)wsEEPROM;
         else if (SRAMSize)
            return wsSRAM;
         break;
      case RETRO_MEMORY_SYSTEM_RAM:
         return (uint8_t*)wsRAM;
      default:
         break;
   }

   return NULL;
}

size_t retro_get_memory_size(unsigned type)
{
   switch (type)
   {
      case RETRO_MEMORY_SAVE_RAM:
         if (eeprom_size)
            return eeprom_size;
         else if (SRAMSize)
            return SRAMSize;
         break;
      case RETRO_MEMORY_SYSTEM_RAM:
         return wsRAMSize;
      default:
         break;
   }

   return 0;
}

void retro_cheat_reset(void) { }
void retro_cheat_set(unsigned a, bool b, const char *c) { }

void MDFND_MidSync(const EmulateSpecStruct *a) { }
void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y) { }
