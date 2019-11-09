#include "mednafen/mednafen.h"
#include <libretro.h>
#include <retro_math.h>
#include <streams/file_stream.h>

#include <vector>

#include "libretro_core_options.h"


// ====================================================


#include "mednafen/mednafen.h"
#include "mednafen/mempatcher.h"
#include "mednafen/git.h"

#include "mednafen/wswan/gfx.h"
#include "mednafen/wswan/memory-wswan.h"


static MDFNGI *game;

static bool overscan;
static double last_sound_rate;

static bool rotate_tall;
static bool select_pressed_last_frame;

static unsigned rotate_joymap;

static MDFN_Surface *surf;


extern void DoSimpleCommand(int cmd);
extern void SetInput(unsigned port, const char *type, uint8 *ptr);
extern void Emulate(EmulateSpecStruct *espec);

extern MDFNGI *MDFNI_LoadGame(const char *force_module, const uint8 *data, size_t size);
extern void MDFNI_CloseGame(void);

extern uint32 SRAMSize;
extern uint32 wsRAMSize;
extern uint8 *wsSRAM;


// ====================================================


struct retro_perf_callback perf_cb;
retro_get_cpu_features_t perf_get_cpu_features_cb = NULL;
retro_log_printf_t log_cb;
static retro_video_refresh_t video_cb;
static retro_audio_sample_t audio_cb;
static retro_audio_sample_batch_t audio_batch_cb;
static retro_environment_t environ_cb;
static retro_input_poll_t input_poll_cb;
static retro_input_state_t input_state_cb;


char retro_base_directory[1024];
std::string retro_base_name;
char retro_save_directory[1024];

static char error_message[1024];


#define MEDNAFEN_CORE_NAME_MODULE "wswan"
#define MEDNAFEN_CORE_NAME "Beetle WonderSwan"
#define MEDNAFEN_CORE_VERSION "v1.23.0.0"
#define MEDNAFEN_CORE_EXTENSIONS "ws|wsc|pc2"
#define MEDNAFEN_CORE_TIMING_FPS 75.47
#define MEDNAFEN_CORE_GEOMETRY_BASE_W (game->nominal_width)
#define MEDNAFEN_CORE_GEOMETRY_BASE_H (game->nominal_height)
#define MEDNAFEN_CORE_GEOMETRY_MAX_W 224
#define MEDNAFEN_CORE_GEOMETRY_MAX_H 144
#define MEDNAFEN_CORE_GEOMETRY_ASPECT_RATIO (14.0 / 9.0)
#define FB_WIDTH 224
#define FB_HEIGHT 144

#define FB_MAX_HEIGHT FB_HEIGHT


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
      std::string retro_base_dir_tmp;

      retro_base_dir_tmp = dir;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_base_dir_tmp.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_base_dir_tmp= retro_base_dir_tmp.substr(0, last);

      strcpy(retro_base_directory, retro_base_dir_tmp.c_str());
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "System directory is not defined. Fallback on using same dir as ROM for system directory later ...\n");
   }

   if (environ_cb(RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY, &dir) && dir)
   {
      std::string retro_save_dir_tmp;

	  // If save directory is defined use it, otherwise use system directory
      retro_save_dir_tmp = *dir ? dir : retro_base_directory;
      // Make sure that we don't have any lingering slashes, etc, as they break Windows.
      size_t last = retro_save_dir_tmp.find_last_not_of("/\\");
      if (last != std::string::npos)
         last++;

      retro_save_dir_tmp = retro_save_dir_tmp.substr(0, last);      

      strcpy(retro_save_directory, retro_save_dir_tmp.c_str());
   }
   else
   {
      /* TODO: Add proper fallback */
      if (log_cb)
         log_cb(RETRO_LOG_WARN, "Save directory is not defined. Fallback on using SYSTEM directory ...\n");
      strcpy(retro_save_directory, retro_base_directory);
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

   var.key = "wswan_rotate_keymap",
   var.value = NULL;

   if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
      if (!strcmp(var.value, "disabled"))
         rotate_joymap = 0;
      else if (!strcmp(var.value, "enabled"))
         rotate_joymap = 1;
      else if (!strcmp(var.value, "auto"))
         rotate_joymap = 2;
   }

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
      { 0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_SELECT, "Rotate screen + active D-Pad" },

      { 0 },
   };

   if (!info)
      return false;

   environ_cb(RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS, desc);

   overscan = false;
   environ_cb(RETRO_ENVIRONMENT_GET_OVERSCAN, &overscan);

   set_basename(info->path);

   game = MDFNI_LoadGame(MEDNAFEN_CORE_NAME_MODULE, (const uint8_t*)info->data, info->size);
   if (!game)
      return false;

   SetInput(0, "gamepad", (uint8*) &input_buf);

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
   
   rotate_tall = false;
   select_pressed_last_frame = false;
   rotate_joymap = 0;

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

static void update_input(void)
{
   input_buf = 0;

   static unsigned map[2][11] = {
      {
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
      },
      {
         RETRO_DEVICE_ID_JOYPAD_Y, //X Cursor horizontal-layout games
         RETRO_DEVICE_ID_JOYPAD_X, //X Cursor horizontal-layout games
         RETRO_DEVICE_ID_JOYPAD_A, //X Cursor horizontal-layout games
         RETRO_DEVICE_ID_JOYPAD_B, //X Cursor horizontal-layout games
         RETRO_DEVICE_ID_JOYPAD_LEFT, //Y Cursor UP vertical-layout games
         RETRO_DEVICE_ID_JOYPAD_UP, //Y Cursor RIGHT vertical-layout games
         RETRO_DEVICE_ID_JOYPAD_RIGHT, //Y Cursor DOWN vertical-layout games
         RETRO_DEVICE_ID_JOYPAD_DOWN, //Y Cursor LEFT vertical-layout games
         RETRO_DEVICE_ID_JOYPAD_START,
         RETRO_DEVICE_ID_JOYPAD_L,
         RETRO_DEVICE_ID_JOYPAD_R,
      }
   };
   
   bool select_button = input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_SELECT);
   
   if(select_button && !select_pressed_last_frame)
   {
      rotate_tall = !rotate_tall;
      if(rotate_tall)
      {
         struct retro_game_geometry new_geom = {FB_WIDTH, FB_HEIGHT, FB_WIDTH, FB_HEIGHT, (9.0 / 14.0)};
         const unsigned rot_angle = 1;/*90 degrees*/
         
         environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, (void*)&new_geom);
         environ_cb(RETRO_ENVIRONMENT_SET_ROTATION, (void*)&rot_angle);
      }
      else
      {
         struct retro_game_geometry new_geom = {FB_WIDTH, FB_HEIGHT, FB_WIDTH, FB_HEIGHT, (14.0 / 9.0)};
         const unsigned rot_angle = 0;/*0 degrees*/
         
         environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, (void*)&new_geom);
         environ_cb(RETRO_ENVIRONMENT_SET_ROTATION, (void*)&rot_angle);
      }
   }
   
   select_pressed_last_frame = select_button;

   bool joymap = (rotate_joymap == 2) ? rotate_tall : (rotate_joymap ? true : false);

   for (unsigned i = 0; i < MAX_BUTTONS; i++) {
      input_buf |= map[joymap][i] != -1u &&
                   input_state_cb(0, RETRO_DEVICE_JOYPAD, 0, map[joymap][i]) ? (1 << i) : 0;
   }

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
   info->need_fullpath    = false;
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

   libretro_set_core_options(environ_cb);
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

   st.data           = NULL;
   st.loc            = 0;
   st.len            = 0;
   st.malloced       = 0;
   st.initial_malloc = 0;

   if (!MDFNSS_SaveSM(&st, 0, 0, NULL, NULL, NULL))
      return 0;

   free(st.data);

   return serialize_size = st.len;
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
         else
            return NULL;
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
         else
            return 0;
      case RETRO_MEMORY_SYSTEM_RAM:
         return wsRAMSize;
      default:
         break;
   }

   return 0;
}

void retro_cheat_reset(void)
{}

void retro_cheat_set(unsigned, bool, const char *)
{}

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
      log_cb(RETRO_LOG_ERROR, "%s", err);
}

void MDFN_PrintError(char const *format,...)
{
   if (log_cb)
   {
      va_list args;
      va_start (args, format);
      vsnprintf (error_message, 1024-1, format, args);

      log_cb(RETRO_LOG_ERROR, "%s", error_message);

      va_end (args);
   }
}

void MDFN_Error(char const *format,...)
{
   if (log_cb)
   {
      va_list args;
      va_start (args, format);
      vsnprintf (error_message, 1024-1, format, args);

      log_cb(RETRO_LOG_ERROR, "%s", error_message);

      va_end (args);
   }
}

void MDFN_Notify(char const *format,...)
{
   if (log_cb)
   {
      va_list args;
      va_start (args, format);
      vsnprintf (error_message, 1024-1, format, args);

      log_cb(RETRO_LOG_INFO, "%s", error_message);

      va_end (args);
   }
}

void MDFN_printf(char const *format,...)
{
   if (log_cb)
   {
      va_list args;
      va_start (args, format);
      vsnprintf (error_message, 1024-1, format, args);

      log_cb(RETRO_LOG_INFO, "%s", error_message);

      va_end (args);
   }
}

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
         ret = std::string(retro_save_directory) + slash + std::string(retro_base_name) +
            std::string(".") + std::string(cd1);
         break;
      case MDFNMKF_FIRMWARE:
         ret = std::string(retro_base_directory) + slash + std::string(cd1);
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
