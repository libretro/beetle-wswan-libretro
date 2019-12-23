/******************************************************************************/
/* Mednafen WonderSwan Emulation Module(based on Cygne)                       */
/******************************************************************************/
/* main.cpp:
**  Copyright (C) 2002 Dox dox@space.pl
**  Copyright (C) 2007-2017 Mednafen Team
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License version 2.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "wswan.h"
#include "mednafen/mempatcher.h"
#include "mednafen/file.h"

#include <sys/types.h>

#include "gfx.h"
#include "memory-wswan.h"
#include "start.inc"
#include "sound.h"
#include "v30mz.h"
#include "comm.h"
#include "rtc.h"
#include "eeprom.h"

#include "retro_math.h"


uint32 WS_InDebug = 0;
int wsc = 1;         /*color/mono*/
uint32 rom_size;
uint32 SRAMSize;

uint16 WSButtonStatus;


static bool IsWSR;
static uint8 WSRCurrentSong;
static uint8 WSRLastButtonStatus;

static void Reset(void)
{
   v30mz_reset();            /* Reset CPU */
   WSwan_MemoryReset();
   Comm_Reset();
   WSwan_GfxReset();
   WSwan_SoundReset();
   WSwan_InterruptReset();
   RTC_Reset();
   WSwan_EEPROMReset();

   for(unsigned u0 = 0; u0 < 0xc8; u0++)
   {
      if(u0 != 0xC4 && u0 != 0xC5 && u0 != 0xBA && u0 != 0xBB)
         WSwan_writeport(u0, startio[u0]);
   }

   v30mz_set_reg(NEC_SS, 0);
   v30mz_set_reg(NEC_SP, 0x2000);

   if(IsWSR)
   {
      v30mz_set_reg(NEC_AW, WSRCurrentSong);
   }
}

static uint8* PortDeviceData;
static unsigned PortDeviceType;

void Emulate(EmulateSpecStruct *espec)
{
   espec->DisplayRect.x = 0;
   espec->DisplayRect.y = 0;
   espec->DisplayRect.w = 224;
   espec->DisplayRect.h = 144;

   if(espec->VideoFormatChanged)
      WSwan_SetPixelFormat(espec->surface->pix_depth);

   if(espec->SoundFormatChanged)
      WSwan_SetSoundRate(espec->SoundRate);

   WSButtonStatus = MDFN_de16lsb(PortDeviceData);
 
   MDFNMP_ApplyPeriodicCheats();

   while(!wsExecuteLine(espec->surface, espec->skip))
   {

   }

   espec->SoundBufSize = WSwan_SoundFlush(espec->SoundBuf, espec->SoundBufMaxSize);

   espec->MasterCycles = v30mz_timestamp;
   v30mz_timestamp = 0;

   if(IsWSR)
   {
   }
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
   { 0x18, "Naxat" },   // Mechanic Arms?  Media Entertainment? Argh!
   { 0x19, "Sunrise" },
   { 0x1A, "Cyberfront" },
   { 0x1B, "Megahouse" },
   { 0x1D, "Interbec" },
   { 0x1E, "NAC" },
   { 0x1F, "Emotion" }, // Bandai Visual??
   { 0x20, "Athena" },
   { 0x21, "KID" },
   { 0x22, "HAL" },
   { 0x23, "Yuki-Enterprise" },
   { 0x24, "Omega Micott" },
   { 0x25, "Upstar" },
   { 0x26, "Kadokawa/Megas" },
   { 0x27, "Cocktail Soft" },
   { 0x28, "Squaresoft" },
   { 0x2A, "NTT DoCoMo" },
   { 0x2B, "TomCreate" },
   { 0x2D, "Namco" },
   { 0x2F, "Gust" },
   { 0x31, "Vanguard" },   // or Elorg?
   { 0x32, "Megatron" },
   { 0x33, "WiZ" },
   { 0x36, "Capcom" },
};

static bool TestMagic(MDFNFILE* gf)
{
   if(gf->ext != "ws" && gf->ext != "wsc" && gf->ext != "wsr")
      return false;

   if(gf->size < 65536)
      return false;

   return true;
}

static void Cleanup(void)
{
   Comm_Kill();
   WSwan_MemoryKill();

   WSwan_SoundKill();

   if(wsCartROM)
   {
      free(wsCartROM);
      wsCartROM = NULL;
   }
}

static void CloseGame(void)
{
   WSwan_MemorySaveNV();   // Must be called before we delete[] wsCartRom.

   Cleanup();
}

static int Load(const uint8_t *data, size_t size)
{
   bool IsWW = false;
   uint32 pow_size;
   uint32 real_rom_size;

   if(size < 65536)
   {
      MDFN_Error(0, "ROM image is too small.");
      return(0);
   }

   real_rom_size = (size + 0xFFFF) & ~0xFFFF;
   pow_size      = next_pow2(real_rom_size);
   rom_size      = pow_size + (pow_size == 0);

   wsCartROM     = (uint8 *)calloc(1, rom_size);
   memcpy(wsCartROM + (rom_size - real_rom_size), data, size);

   // This real_rom_size vs rom_size funny business is intended primarily for handling
   // WSR files.
   if(real_rom_size < rom_size)
      memset(wsCartROM, 0xFF, rom_size - real_rom_size);

   IsWSR = false;

   if(rom_size == 524288 && !memcmp(&wsCartROM[0x70000], "ELISA", 5) /*&& crc32(0, &wsCartROM[0x7FFF0], 0x10) == 0x0d05ed64*/)
   {
      IsWW = true;
	  MDFN_printf("Wonder Witch detected\n");
   }

   MDFN_printf("ROM:       %uKiB\n", real_rom_size / 1024);

   uint8 header[10];
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
      MDFN_printf("Developer: %s (0x%02x)\n", developer_name, header[0]);
   }

   SRAMSize = 0;
   eeprom_size = 0;

   switch(header[5])
   {
      case 0x01: SRAMSize =   8 * 1024; break;
      case 0x02: SRAMSize =  32 * 1024; break;

      case 0x03: SRAMSize = 128 * 1024; break;  // Taikyoku Igo.  Maybe it should only be 65536 bytes?

      case 0x04: SRAMSize = 256 * 1024; break;  // Dicing Knight, Judgement Silversword
      case 0x05: SRAMSize = 512 * 1024; break;  // Wonder Gate

      case 0x10: eeprom_size = 128; break;
      case 0x20: eeprom_size = 2 *1024; break;
      case 0x50: eeprom_size = 1024; break;
   }

   //printf("Header5: %02x\n", header[5]);

   if(eeprom_size)
      MDFN_printf("EEPROM:  %d bytes\n", eeprom_size);

   if(SRAMSize)
      MDFN_printf("Battery-backed RAM:  %d bytes\n", SRAMSize);

   MDFN_printf("Recorded Checksum:  0x%04x\n", header[8] | (header[9] << 8));
   {
      uint16 real_crc = 0;
      for(unsigned int i = 0; i < rom_size - 2; i++)
         real_crc += wsCartROM[i];
      MDFN_printf("Real Checksum:      0x%04x\n", real_crc);
   }

   if(IsWW)
      MDFN_printf("WonderWitch firmware detected.\n");

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

   if(!IsWSR)
   {
      if(header[6] & 0x1)
         MDFNGameInfo->rotated = MDFN_ROTATE90;
   }

   MDFNMP_Init(16384, (1 << 20) / 1024);

   WSwan_MemoryInit(MDFN_GetSettingB("wswan.language"), wsc, SRAMSize, IsWW); // EEPROM and SRAM are loaded in this func.

   if(!IsWSR)
      WSwan_MemoryLoadNV();

   Comm_Init(MDFN_GetSettingB("wswan.excomm") ? MDFN_GetSettingS("wswan.excomm.path") : NULL);

   WSwan_GfxInit();
   MDFNGameInfo->fps = (uint32)((uint64)3072000 * 65536 * 256 / (159*256));

   WSwan_SoundInit();

   RTC_Init();

   wsMakeTiles();

   Reset();

   return(1);
}

void SetInput(unsigned port, const char *type, uint8 *ptr)
{
   if(!port)
   {
      PortDeviceData = (uint8 *)ptr;
      PortDeviceType = strcmp(type, "gamepad");
   }
}

static void TransformInput(void)
{
   if(PortDeviceType)
   {
      uint16 butt_data = MDFN_de16lsb(PortDeviceData);
      unsigned x = (butt_data >> 0) & 0xF;
      unsigned y = (butt_data >> 4) & 0xF;
      unsigned b = (butt_data >> 8) & 0xF;
      const unsigned offs = MDFNGameInfo->rotated;
      x = ((x << offs) | (x >> (4 - offs))) & 0xF;
      y = ((y << offs) | (y >> (4 - offs))) & 0xF;
      b = ((b << offs) | (b >> (4 - offs))) & 0xF;

      if(MDFNGameInfo->rotated == MDFN_ROTATE90)
      {
         std::swap(x, y);
         std::swap(x, b);
      }
      b = ((b & 1) << 1) | ((b & 8) >> 1) | (b & 0x6) | ((butt_data >> 12) & 1);
      butt_data = (x << 0) | (y << 4) | (b << 8);
      //printf("%04x\n", butt_data);
      MDFN_en16lsb(PortDeviceData, butt_data);
   }
}

int StateAction(StateMem *sm, const unsigned load, const bool data_only)
{
   if(IsWSR)
   {
   }

   if(!v30mz_StateAction(sm, load, data_only))
      return(0);

   if(load)
   {
      //printf("%d\n", v30mz_ICount);
      if(v30mz_ICount > 256)
         v30mz_ICount = 256;
   }

   // Call MemoryStateAction before others StateActions...
   if(!WSwan_MemoryStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_GfxStateAction(sm, load, data_only))
      return(0);

   if(!RTC_StateAction(sm, load, data_only))
      return(0);

   if(!WSwan_InterruptStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_SoundStateAction(sm, load, data_only))
      return(0);

   if(!WSwan_EEPROMStateAction(sm, load, data_only))
      return(0);

   if(!Comm_StateAction(sm, load, data_only))
      return(0);
  
   return(1);
}

void DoSimpleCommand(int cmd)
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

 { "wswan.excomm", MDFNSF_EMU_STATE | MDFNSF_SUPPRESS_DOC, "Enable comms to external program.", NULL, MDFNST_BOOL, "0" },
 { "wswan.excomm.path", MDFNSF_EMU_STATE | MDFNSF_SUPPRESS_DOC, "Comms external program path.", NULL, MDFNST_STRING, "wonderfence" },

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
 { ".pc2", "Benesse Pocket Challenge 2" },
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


// ====================================================


MDFNGI *MDFNGameInfo = &EmulatedWSwan;

MDFNGI *MDFNI_LoadGame(const char *force_module, const uint8 *data, size_t size)
{
   MDFNGameInfo = &EmulatedWSwan;

   if(Load(data, size) <= 0)
      goto error;

   WSwan_SetPixelFormat(16);

   MDFN_LoadGameCheats(NULL);
   MDFNMP_InstallReadPatches();

   return(MDFNGameInfo);

error:
   MDFNGameInfo = NULL;
   return NULL;
}

void MDFNI_CloseGame(void)
{
   if(!MDFNGameInfo)
      return;

   MDFN_FlushGameCheats(0);

   CloseGame();

   MDFNMP_Kill();

   MDFNGameInfo = NULL;
}
