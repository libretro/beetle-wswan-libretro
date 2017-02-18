#include "mednafen/mednafen.h"
#include "mednafen/mempatcher.h"
#include "mednafen/git.h"
#include "mednafen/general.h"
#include "libretro.h"

#include <vector>

static MDFNGI *game;

struct retro_perf_callback perf_cb;
retro_get_cpu_features_t perf_get_cpu_features_cb = NULL;
retro_log_printf_t log_cb;
static retro_video_refresh_t video_cb;
static retro_audio_sample_t audio_cb;
static retro_audio_sample_batch_t audio_batch_cb;
static retro_environment_t environ_cb;
static retro_input_poll_t input_poll_cb;
static retro_input_state_t input_state_cb;

static bool overscan;
static double last_sound_rate;

static MDFN_Surface *surf;

static bool failed_init;

std::string retro_base_directory;
std::string retro_base_name;
std::string retro_save_directory;

static INLINE bool MDFN_DumpToFileReal(const char *filename, int compress, const std::vector<PtrLengthPair> &pearpairs)
{
   FILE *fp = fopen(filename, "wb");

   if (!fp)
      return 0;

   for(unsigned int i = 0; i < pearpairs.size(); i++)
   {
      const void *data = pearpairs[i].GetData();
      const uint64 length = pearpairs[i].GetLength();

      if (fwrite(data, 1, length, fp) != length)
      {
         fclose(fp);
         return 0;
      }
   }

   if (fclose(fp) == EOF)
      return 0;

   return 1;
}

bool MDFN_DumpToFile(const char *filename, int compress, const std::vector<PtrLengthPair> &pearpairs)
{
   return (MDFN_DumpToFileReal(filename, compress, pearpairs));
}

bool MDFN_DumpToFile(const char *filename, int compress, const void *data, uint64 length)
{
   std::vector<PtrLengthPair> tmp_pairs;
   tmp_pairs.push_back(PtrLengthPair(data, length));
   return (MDFN_DumpToFileReal(filename, compress, tmp_pairs));
}

static void set_basename(const char *path)
{
   const char *base = strrchr(path, '/');
   if (!base)
      base = strrchr(path, '\\');

   if (base)
      retro_base_name = base + 1;
   else
      retro_base_name = path;

   retro_base_name = retro_base_name.substr(0, retro_base_name.find_last_of('.'));
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

#include "mednafen/wswan/wswan.h"
#include "mednafen/mempatcher.h"

#include <sys/types.h>

#include "mednafen/wswan/gfx.h"
#include "mednafen/wswan/wswan-memory.h"
#include "mednafen/wswan/start.inc"
#include "mednafen/wswan/sound.h"
#include "mednafen/wswan/v30mz.h"
#include "mednafen/wswan/rtc.h"
#include "mednafen/wswan/eeprom.h"
#include "mednafen/wswan/debug.h"

int 		wsc = 1;			/*color/mono*/
uint32		rom_size;

uint16 WSButtonStatus;


static uint8 WSRCurrentSong;

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
static void Emulate(EmulateSpecStruct *espec)
{
 espec->DisplayRect.x = 0;
 espec->DisplayRect.y = 0;
 espec->DisplayRect.w = 224;
 espec->DisplayRect.h = 144;


 if(espec->SoundFormatChanged)
  WSwan_SetSoundRate(espec->SoundRate);

 uint16 butt_data = chee[0] | (chee[1] << 8);

 WSButtonStatus = butt_data;
 

 MDFNMP_ApplyPeriodicCheats();

 while(!wsExecuteLine(espec->surface, espec->skip))
 {

 }


 espec->SoundBufSize = WSwan_SoundFlush(espec->SoundBuf, espec->SoundBufMaxSize);

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
 { 0x06, "Asmik" }, // Asmik Ace?
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
 { 0x18, "Naxat" },	// Mechanic Arms?  Media Entertainment? Argh!
 { 0x19, "Sunrise" },
 { 0x1A, "Cyberfront" },
 { 0x1B, "Megahouse" },
 { 0x1D, "Interbec" },
 { 0x1E, "NAC" },
 { 0x1F, "Emotion" }, // Bandai Visual??
 { 0x20, "Athena" },
 { 0x21, "KID" },
 { 0x24, "Omega Micott" },
 { 0x25, "Upstar" },
 { 0x26, "Kadokawa/Megas" },
 { 0x27, "Cocktail Soft" },
 { 0x28, "Squaresoft" },
 { 0x2B, "TomCreate" },
 { 0x2D, "Namco" },
 { 0x2F, "Gust" },
 { 0x36, "Capcom" },
};

static bool TestMagic(const char *name, MDFNFILE *fp)
{
 if(strcasecmp(GET_FEXTS_PTR(fp), "ws") && strcasecmp(GET_FEXTS_PTR(fp), "wsc") && strcasecmp(GET_FEXTS_PTR(fp), "wsr"))
  return(false);

 if(GET_FSIZE_PTR(fp) < 65536)
  return(false);

 return(true);
}

static int Load(const char *name, MDFNFILE *fp)
{
   uint32 real_rom_size;
   uint8 header[10];

   if(GET_FSIZE_PTR(fp) < 65536)
      return(0);

   real_rom_size = (GET_FSIZE_PTR(fp) + 0xFFFF) & ~0xFFFF;
   rom_size = round_up_pow2(real_rom_size); //fp->size);

   wsCartROM = (uint8 *)calloc(1, rom_size);


   // This real_rom_size vs rom_size funny business is intended primarily for handling
   // WSR files.
   if(real_rom_size < rom_size)
      memset(wsCartROM, 0xFF, rom_size - real_rom_size);

   memcpy(wsCartROM + (rom_size - real_rom_size), GET_FDATA_PTR(fp), GET_FSIZE_PTR(fp));

   memcpy(header, wsCartROM + rom_size - 10, 10);

   {
      const char *developer_name = "???";
      for(unsigned int x = 0; x < sizeof(Developers) / sizeof(DLEntry); x++)
      {
         if(Developers[x].id == header[0])
         {
            developer_name = Developers[x].name;
            break;
         }
      }
      printf(_("Developer: %s (0x%02x)\n"), developer_name, header[0]);
   }

   uint32 SRAMSize = 0;
   eeprom_size = 0;

   switch(header[5])
   {
      case 0x01: SRAMSize = 8*1024; break;
      case 0x02: SRAMSize = 32*1024; break;
      case 0x03: SRAMSize = 16 * 65536; break;
      case 0x04: SRAMSize = 32 * 65536; break; // Dicing Knight!

      case 0x10: eeprom_size = 128; break;
      case 0x20: eeprom_size = 2*1024; break;
      case 0x50: eeprom_size = 1024; break;
   }

   {
      uint16 real_crc = 0;
      for(unsigned int i = 0; i < rom_size - 2; i++)
         real_crc += wsCartROM[i];
      printf(_("Real Checksum:      0x%04x\n"), real_crc);
   }

   if((header[8] | (header[9] << 8)) == 0x8de1 && (header[0]==0x01)&&(header[2]==0x27)) /* Detective Conan */
   {
      //puts("HAX");
      /* WS cpu is using cache/pipeline or there's protected ROM bank where pointing CS */
      wsCartROM[0xfffe8]=0xea;
      wsCartROM[0xfffe9]=0x00;
      wsCartROM[0xfffea]=0x00;
      wsCartROM[0xfffeb]=0x00;
      wsCartROM[0xfffec]=0x20;
   }

   {
      if(header[6] & 0x1)
         MDFNGameInfo->rotated = MDFN_ROTATE90;
   }

   MDFNMP_Init(16384, (1 << 20) / 1024);

   v30mz_init(WSwan_readmem20, WSwan_writemem20, WSwan_readport, WSwan_writeport);
   WSwan_MemoryInit(MDFN_GetSettingB("wswan.language"), wsc, SRAMSize, false); // EEPROM and SRAM are loaded in this func.
   WSwan_GfxInit();
   MDFNGameInfo->fps = (uint32)((uint64)3072000 * 65536 * 256 / (159*256));

   WSwan_SoundInit();

   wsMakeTiles();

   Reset();

   return(1);
}

static void CloseGame(void)
{
   WSwan_MemoryKill(); // saves sram/eeprom

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

   // Call MemoryStateAction before others StateActions...
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
   {
      puts("Oops");
      return(0);
   }

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

static const MDFNSetting_EnumList SexList[] =
{
 { "m", WSWAN_SEX_MALE },
 { "male", WSWAN_SEX_MALE, "Male" },

 { "f", WSWAN_SEX_FEMALE },
 { "female", WSWAN_SEX_FEMALE, "Female" },

 { "3", 3 },

 { NULL, 0 },
};

static const MDFNSetting_EnumList BloodList[] =
{
 { "a", WSWAN_BLOOD_A, "A" },
 { "b", WSWAN_BLOOD_B, "B" },
 { "o", WSWAN_BLOOD_O, "O" },
 { "ab", WSWAN_BLOOD_AB, "AB" },

 { "5", 5 },

 { NULL, 0 },
};

static const MDFNSetting_EnumList LanguageList[] =
{
 { "japanese", 0, "Japanese" },
 { "0", 0 },

 { "english", 1, "English" },
 { "1", 1 },

 { NULL, 0 },
};

static const MDFNSetting WSwanSettings[] =
{
 { "wswan.rotateinput", MDFNSF_NOFLAGS, "Virtually rotate D-pads along with screen.", NULL, MDFNST_BOOL, "0" },
 { "wswan.language", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Language games should display text in.", "The only game this setting is known to affect is \"Digimon Tamers - Battle Spirit\".", MDFNST_ENUM, "english", NULL, NULL, NULL, NULL, LanguageList },
 { "wswan.name", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Name", NULL, MDFNST_STRING, "Mednafen" },
 { "wswan.byear", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Birth Year", NULL, MDFNST_UINT, "1989", "0", "9999" },
 { "wswan.bmonth", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Birth Month", NULL, MDFNST_UINT, "6", "1", "12" },
 { "wswan.bday", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Birth Day", NULL, MDFNST_UINT, "23", "1", "31" },
 { "wswan.sex", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Sex", NULL, MDFNST_ENUM, "F", NULL, NULL, NULL, NULL, SexList },
 { "wswan.blood", MDFNSF_EMU_STATE | MDFNSF_UNTRUSTED_SAFE, "Blood Type", NULL, MDFNST_ENUM, "O", NULL, NULL, NULL, NULL, BloodList },
 { NULL }
};

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

static const FileExtensionSpecStruct KnownExtensions[] =
{
 { ".ws", "WonderSwan ROM Image" },
 { ".wsc", "WonderSwan Color ROM Image" },
 { ".wsr", "WonderSwan Music Rip" },
 { NULL, NULL }
};

MDFNGI EmulatedWSwan =
{
 WSwanSettings,
 MDFN_MASTERCLOCK_FIXED(3072000),
 0,
 false, // Multires possible?

 224,   // lcm_width
 144,   // lcm_height
 NULL,  // Dummy

 224,	// Nominal width
 144,	// Nominal height

 224,	// Framebuffer width
 144,	// Framebuffer height

 2,     // Number of output sound channels
};


#define MEDNAFEN_CORE_NAME_MODULE "wswan"
#define MEDNAFEN_CORE_NAME "Mednafen WonderSwan"
#define MEDNAFEN_CORE_VERSION "v0.9.35.1"
#define MEDNAFEN_CORE_EXTENSIONS "ws|wsc"
#define MEDNAFEN_CORE_TIMING_FPS 75.47
#define MEDNAFEN_CORE_GEOMETRY_BASE_W (game->nominal_width)
#define MEDNAFEN_CORE_GEOMETRY_BASE_H (game->nominal_height)
#define MEDNAFEN_CORE_GEOMETRY_MAX_W 224
#define MEDNAFEN_CORE_GEOMETRY_MAX_H 144
#define MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO (14.0 / 9.0)
#define FB_WIDTH 224
#define FB_HEIGHT 144

#define FB_MAX_HEIGHT FB_HEIGHT

MDFNGI *MDFNGameInfo = &EmulatedWSwan;

static MDFNGI *MDFNI_LoadGame(const char *force_module, const char *name)
{
   MDFNFILE *GameFile = NULL;
	std::vector<FileExtensionSpecStruct> valid_iae;
   MDFNGameInfo = &EmulatedWSwan;

	// Construct a NULL-delimited list of known file extensions for MDFN_fopen()
   const FileExtensionSpecStruct *curexts = KnownExtensions; 

   while(curexts->extension && curexts->description)
   {
      valid_iae.push_back(*curexts);
      curexts++;
   }
   
   GameFile = file_open(name);

	if(!GameFile)
      goto error;

   if(Load(name, GameFile) <= 0)
      goto error;

	MDFN_LoadGameCheats(NULL);
	MDFNMP_InstallReadPatches();

   return(MDFNGameInfo);

error:
   if (GameFile)
      file_close(GameFile);
   MDFNGameInfo = NULL;
   return NULL;
}

static void MDFNI_CloseGame(void)
{
   if(!MDFNGameInfo)
      return;

   MDFN_FlushGameCheats(0);

   CloseGame();

   MDFNMP_Kill();

   MDFNGameInfo = NULL;
}

static void check_system_specs(void)
{
   // TODO - should theoretically be level 4, but apparently
   // doesn't run at fullspeed on PSP (yet)
   unsigned level = 4;
   environ_cb(RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL, &level);
}

void retro_init(void)
{
   struct retro_log_callback log;
   if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log))
      log_cb = log.log;
   else 
      log_cb = NULL;

   const char *dir = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &dir) && dir)
   {
      retro_base_directory = dir;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_base_directory.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_base_directory = retro_base_directory.substr(0, last);
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "System directory is not defined. Fallback on using same dir as ROM for system directory later ...\n");
      failed_init = true;
   }
   
   if (environ_cb(RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY, &dir) && dir)
   {
	  // If save directory is defined use it, otherwise use system directory
      // retro_save_directory = *dir ? dir : retro_base_directory;
	  retro_save_directory = dir;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_save_directory.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_save_directory = retro_save_directory.substr(0, last);      
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "Save directory is not defined. Fallback on using SYSTEM directory ...\n");
	  retro_save_directory = retro_base_directory;
   }      

#if defined(WANT_16BPP) && defined(FRONTEND_SUPPORTS_RGB565)
   enum retro_pixel_format rgb565 = RETRO_PIXEL_FORMAT_RGB565;
   if (environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &rgb565) && log_cb)
      log_cb(RETRO_LOG_INFO, "Frontend supports RGB565 - will use that instead of XRGB1555.\n");
#endif

   if (environ_cb(RETRO_ENVIRONMENT_GET_PERF_INTERFACE, &perf_cb))
      perf_get_cpu_features_cb = perf_cb.get_cpu_features;
   else
      perf_get_cpu_features_cb = NULL;

   check_system_specs();
}

void retro_reset(void)
{
   DoSimpleCommand(MDFN_MSC_RESET);
}

bool retro_load_game_special(unsigned, const struct retro_game_info *, size_t)
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

static void check_variables(void)
{
   struct retro_variable var = {0};

}

#define MAX_PLAYERS 1
#define MAX_BUTTONS 11
static uint16_t input_buf;


bool retro_load_game(const struct retro_game_info *info)
{
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

      { 0 },
   };

   if (!info || failed_init)
      return false;

   environ_cb(RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS, desc);

   overscan = false;
   environ_cb(RETRO_ENVIRONMENT_GET_OVERSCAN, &overscan);

   set_basename(info->path);

   game = MDFNI_LoadGame(MEDNAFEN_CORE_NAME_MODULE, info->path);
   if (!game)
      return false;

   SetInput(0, "gamepad", &input_buf);

   surf = (MDFN_Surface*)calloc(1, sizeof(*surf));
   
   if (!surf)
      return false;
   
   surf->width  = FB_WIDTH;
   surf->height = FB_HEIGHT;
   surf->pitch  = FB_WIDTH;

   surf->pixels = (uint16_t*)calloc(1, FB_WIDTH * FB_HEIGHT * 2);

   if (!surf->pixels)
   {
      free(surf);
      return false;
   }

   check_variables();

   WSwan_SetPixelFormat();

   return true;
}

void retro_unload_game()
{
   if (!game)
      return;

   MDFNI_CloseGame();
}



// Hardcoded for PSX. No reason to parse lots of structures ...
// See mednafen/psx/input/gamepad.cpp
static void update_input(void)
{
   input_buf = 0;

   static unsigned map[] = {
      RETRO_DEVICE_ID_JOYPAD_UP, //X Cursor horizontal-layout games
      RETRO_DEVICE_ID_JOYPAD_RIGHT, //X Cursor horizontal-layout games
      RETRO_DEVICE_ID_JOYPAD_DOWN, //X Cursor horizontal-layout games
      RETRO_DEVICE_ID_JOYPAD_LEFT, //X Cursor horizontal-layout games
      RETRO_DEVICE_ID_JOYPAD_R2, //Y Cursor UP vertical-layout games
      RETRO_DEVICE_ID_JOYPAD_R, //Y Cursor RIGHT vertical-layout games
      RETRO_DEVICE_ID_JOYPAD_L2, //Y Cursor DOWN vertical-layout games
      RETRO_DEVICE_ID_JOYPAD_L, //Y Cursor LEFT vertical-layout games
      RETRO_DEVICE_ID_JOYPAD_START,
      RETRO_DEVICE_ID_JOYPAD_A,
      RETRO_DEVICE_ID_JOYPAD_B,
   };

   for (unsigned i = 0; i < MAX_BUTTONS; i++)
      input_buf |= map[i] != -1u &&
         input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, map[i]) ? (1 << i) : 0;

#ifdef MSB_FIRST
   union {
      uint8_t b[2];
      uint16_t s;
   } u;
   u.s = input_buf;
   input_buf = u.b[0] | u.b[1] << 8;
#endif

}

static uint64_t video_frames, audio_frames;


void retro_run(void)
{
   input_poll_cb();

   update_input();

   static int16_t sound_buf[0x10000];
   static MDFN_Rect rects[FB_MAX_HEIGHT];
   rects[0].w = ~0;

   EmulateSpecStruct spec = {0};
   spec.surface = surf;
   spec.SoundRate = 44100;
   spec.SoundBuf = sound_buf;
   spec.LineWidths = rects;
   spec.SoundBufMaxSize = sizeof(sound_buf) / 2;
   spec.SoundVolume = 1.0;
   spec.soundmultiplier = 1.0;
   spec.SoundBufSize = 0;
   spec.VideoFormatChanged = false;
   spec.SoundFormatChanged = false;

   if (spec.SoundRate != last_sound_rate)
   {
      spec.SoundFormatChanged = true;
      last_sound_rate = spec.SoundRate;
   }

   Emulate(&spec);

   int16 *const SoundBuf = spec.SoundBuf + spec.SoundBufSizeALMS * 2;
   int32 SoundBufSize = spec.SoundBufSize - spec.SoundBufSizeALMS;
   const int32 SoundBufMaxSize = spec.SoundBufMaxSize - spec.SoundBufSizeALMS;

   spec.SoundBufSize = spec.SoundBufSizeALMS + SoundBufSize;

   unsigned width  = spec.DisplayRect.w;
   unsigned height = spec.DisplayRect.h;

   video_cb(surf->pixels, width, height, FB_WIDTH << 1);

   video_frames++;
   audio_frames += spec.SoundBufSize;

   audio_batch_cb(spec.SoundBuf, spec.SoundBufSize);

   bool updated = false;
   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE, &updated) && updated)
      check_variables();
}

void retro_get_system_info(struct retro_system_info *info)
{
   memset(info, 0, sizeof(*info));
   info->library_name     = MEDNAFEN_CORE_NAME;
#ifndef GIT_VERSION
#define GIT_VERSION ""
#endif
   info->library_version  = MEDNAFEN_CORE_VERSION GIT_VERSION;
   info->need_fullpath    = true;
   info->valid_extensions = MEDNAFEN_CORE_EXTENSIONS;
   info->block_extract    = false;
}

void retro_get_system_av_info(struct retro_system_av_info *info)
{
   memset(info, 0, sizeof(*info));
   info->timing.fps            = MEDNAFEN_CORE_TIMING_FPS;
   info->timing.sample_rate    = 44100;
   info->geometry.base_width   = MEDNAFEN_CORE_GEOMETRY_BASE_W;
   info->geometry.base_height  = MEDNAFEN_CORE_GEOMETRY_BASE_H;
   info->geometry.max_width    = MEDNAFEN_CORE_GEOMETRY_MAX_W;
   info->geometry.max_height   = MEDNAFEN_CORE_GEOMETRY_MAX_H;
   info->geometry.aspect_ratio = MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO;
}

void retro_deinit(void)
{
   if (surf)
      free(surf);
   surf = NULL;

   if (log_cb)
   {
      log_cb(RETRO_LOG_INFO, "[%s]: Samples / Frame: %.5f\n",
            MEDNAFEN_CORE_NAME, (double)audio_frames / video_frames);
      log_cb(RETRO_LOG_INFO, "[%s]: Estimated FPS: %.5f\n",
            MEDNAFEN_CORE_NAME, (double)video_frames * 44100 / audio_frames);
   }
}

unsigned retro_get_region(void)
{
   return RETRO_REGION_NTSC; // FIXME: Regions for other cores.
}

unsigned retro_api_version(void)
{
   return RETRO_API_VERSION;
}

void retro_set_controller_port_device(unsigned in_port, unsigned device)
{
}

void retro_set_environment(retro_environment_t cb)
{
   environ_cb = cb;
}

void retro_set_audio_sample(retro_audio_sample_t cb)
{
   audio_cb = cb;
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

static size_t serialize_size;

size_t retro_serialize_size(void)
{
   StateMem st;
   memset(&st, 0, sizeof(st));

   if (!MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL))
      return 0;

   free(st.data);
   return serialize_size = st.len;
}

bool retro_serialize(void *data, size_t size)
{
   StateMem st;
   memset(&st, 0, sizeof(st));
   st.data     = (uint8_t*)data;
   st.malloced = size;

   return MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL);
}

bool retro_unserialize(const void *data, size_t size)
{
   StateMem st;
   memset(&st, 0, sizeof(st));
   st.data = (uint8_t*)data;
   st.len  = size;

   return MDFNSS_LoadSM(&st, 0, 0);
}

void *retro_get_memory_data(unsigned)
{
   return NULL;
}

size_t retro_get_memory_size(unsigned)
{
   return 0;
}

void retro_cheat_reset(void)
{}

void retro_cheat_set(unsigned, bool, const char *)
{}

#ifdef _WIN32
static void sanitize_path(std::string &path)
{
   size_t size = path.size();
   for (size_t i = 0; i < size; i++)
      if (path[i] == '/')
         path[i] = '\\';
}
#endif

// Use a simpler approach to make sure that things go right for libretro.
std::string MDFN_MakeFName(MakeFName_Type type, int id1, const char *cd1)
{
   char slash;
#ifdef _WIN32
   slash = '\\';
#else
   slash = '/';
#endif
   std::string ret;
   switch (type)
   {
      case MDFNMKF_SAV:
         ret = retro_save_directory +slash + retro_base_name +
            std::string(".") + std::string(cd1);
         break;
      case MDFNMKF_FIRMWARE:
         ret = retro_base_directory + slash + std::string(cd1);
#ifdef _WIN32
   sanitize_path(ret); // Because Windows path handling is mongoloid.
#endif
         break;
      default:	  
         break;
   }

   if (log_cb)
      log_cb(RETRO_LOG_INFO, "MDFN_MakeFName: %s\n", ret.c_str());
   return ret;
}

void MDFND_DispMessage(unsigned char *str)
{
   if (log_cb)
      log_cb(RETRO_LOG_INFO, "%s\n", str);
}

void MDFND_Message(const char *str)
{
   if (log_cb)
      log_cb(RETRO_LOG_INFO, "%s\n", str);
}

void MDFND_MidSync(const EmulateSpecStruct *)
{}

void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y)
{
 //MDFND_MidLineUpdate(espec, y);
}

void MDFND_PrintError(const char* err)
{
   if (log_cb)
      log_cb(RETRO_LOG_ERROR, "%s\n", err);
}
