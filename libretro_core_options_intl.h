#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/
/* RETRO_LANGUAGE_AR */

#define WSWAN_ROTATE_DISPLAY_LABEL_AR NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_AR NULL
#define OPTION_VAL_MANUAL_AR NULL
#define OPTION_VAL_LANDSCAPE_AR NULL
#define OPTION_VAL_PORTRAIT_AR NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_AR NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_AR NULL
#define OPTION_VAL_AUTO_AR NULL
#define WSWAN_MONO_PALETTE_LABEL_AR NULL
#define WSWAN_MONO_PALETTE_INFO_0_AR NULL
#define OPTION_VAL_DEFAULT_AR NULL
#define OPTION_VAL_WONDERSWAN_AR NULL
#define OPTION_VAL_WONDESWAN_COLOR_AR NULL
#define OPTION_VAL_SWANCRYSTAL_AR NULL
#define OPTION_VAL_GB_DMG_AR NULL
#define OPTION_VAL_GB_POCKET_AR NULL
#define OPTION_VAL_GB_LIGHT_AR NULL
#define OPTION_VAL_BLOSSOM_PINK_AR NULL
#define OPTION_VAL_BUBBLES_BLUE_AR NULL
#define OPTION_VAL_BUTTERCUP_GREEN_AR NULL
#define OPTION_VAL_DIGIVICE_AR NULL
#define OPTION_VAL_GAME_COM_AR NULL
#define OPTION_VAL_GAMEKING_AR NULL
#define OPTION_VAL_GAME_MASTER_AR NULL
#define OPTION_VAL_GOLDEN_WILD_AR NULL
#define OPTION_VAL_GREENSCALE_AR NULL
#define OPTION_VAL_HOKAGE_ORANGE_AR NULL
#define OPTION_VAL_LABO_FAWN_AR NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_AR NULL
#define OPTION_VAL_MICROVISION_AR NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_AR NULL
#define OPTION_VAL_ODYSSEY_GOLD_AR NULL
#define OPTION_VAL_SHINY_SKY_BLUE_AR NULL
#define OPTION_VAL_SLIME_BLUE_AR NULL
#define OPTION_VAL_TI_83_AR NULL
#define OPTION_VAL_TRAVEL_WOOD_AR NULL
#define OPTION_VAL_VIRTUAL_BOY_AR NULL
#define WSWAN_GFX_COLORS_LABEL_AR NULL
#define WSWAN_GFX_COLORS_INFO_0_AR NULL
#define OPTION_VAL_16BIT_AR NULL
#define OPTION_VAL_24BIT_AR NULL
#define WSWAN_FRAMESKIP_LABEL_AR NULL
#define WSWAN_FRAMESKIP_INFO_0_AR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_AR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_AR NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_AR NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_AR NULL

struct retro_core_option_v2_category option_cats_ar[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ar[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_AR,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_AR,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_AR },
         { "landscape", OPTION_VAL_LANDSCAPE_AR },
         { "portrait",  OPTION_VAL_PORTRAIT_AR },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_AR,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_AR,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_AR },
         { "disabled", OPTION_VAL_LANDSCAPE_AR },
         { "enabled",  OPTION_VAL_PORTRAIT_AR },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_AR,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_AR,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_AR },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_AR },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_AR },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_AR },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_AR },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_AR },
         { "gb_light",               OPTION_VAL_GB_LIGHT_AR },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_AR },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_AR },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_AR },
         { "digivice",               OPTION_VAL_DIGIVICE_AR },
         { "game_com",               OPTION_VAL_GAME_COM_AR },
         { "gameking",               OPTION_VAL_GAMEKING_AR },
         { "game_master",            OPTION_VAL_GAME_MASTER_AR },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_AR },
         { "greenscale",             OPTION_VAL_GREENSCALE_AR },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_AR },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_AR },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_AR },
         { "microvision",            OPTION_VAL_MICROVISION_AR },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_AR },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_AR },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_AR },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_AR },
         { "ti_83",                  OPTION_VAL_TI_83_AR },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_AR },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_AR },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_AR,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_AR,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_AR },
         { "24bit", OPTION_VAL_24BIT_AR },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_AR,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_AR,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_AR },
         { "manual",   OPTION_VAL_MANUAL_AR },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_AR,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_AR,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_AR,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_AR,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ar = {
   option_cats_ar,
   option_defs_ar
};

/* RETRO_LANGUAGE_AST */

#define WSWAN_ROTATE_DISPLAY_LABEL_AST NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_AST NULL
#define OPTION_VAL_MANUAL_AST NULL
#define OPTION_VAL_LANDSCAPE_AST NULL
#define OPTION_VAL_PORTRAIT_AST NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_AST NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_AST NULL
#define OPTION_VAL_AUTO_AST NULL
#define WSWAN_MONO_PALETTE_LABEL_AST NULL
#define WSWAN_MONO_PALETTE_INFO_0_AST NULL
#define OPTION_VAL_DEFAULT_AST NULL
#define OPTION_VAL_WONDERSWAN_AST NULL
#define OPTION_VAL_WONDESWAN_COLOR_AST NULL
#define OPTION_VAL_SWANCRYSTAL_AST NULL
#define OPTION_VAL_GB_DMG_AST NULL
#define OPTION_VAL_GB_POCKET_AST NULL
#define OPTION_VAL_GB_LIGHT_AST NULL
#define OPTION_VAL_BLOSSOM_PINK_AST NULL
#define OPTION_VAL_BUBBLES_BLUE_AST NULL
#define OPTION_VAL_BUTTERCUP_GREEN_AST NULL
#define OPTION_VAL_DIGIVICE_AST NULL
#define OPTION_VAL_GAME_COM_AST NULL
#define OPTION_VAL_GAMEKING_AST NULL
#define OPTION_VAL_GAME_MASTER_AST NULL
#define OPTION_VAL_GOLDEN_WILD_AST NULL
#define OPTION_VAL_GREENSCALE_AST NULL
#define OPTION_VAL_HOKAGE_ORANGE_AST NULL
#define OPTION_VAL_LABO_FAWN_AST NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_AST NULL
#define OPTION_VAL_MICROVISION_AST NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_AST NULL
#define OPTION_VAL_ODYSSEY_GOLD_AST NULL
#define OPTION_VAL_SHINY_SKY_BLUE_AST NULL
#define OPTION_VAL_SLIME_BLUE_AST NULL
#define OPTION_VAL_TI_83_AST NULL
#define OPTION_VAL_TRAVEL_WOOD_AST NULL
#define OPTION_VAL_VIRTUAL_BOY_AST NULL
#define WSWAN_GFX_COLORS_LABEL_AST NULL
#define WSWAN_GFX_COLORS_INFO_0_AST NULL
#define OPTION_VAL_16BIT_AST NULL
#define OPTION_VAL_24BIT_AST NULL
#define WSWAN_FRAMESKIP_LABEL_AST NULL
#define WSWAN_FRAMESKIP_INFO_0_AST NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_AST NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_AST NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_AST NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_AST NULL

struct retro_core_option_v2_category option_cats_ast[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ast[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_AST,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_AST,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_AST },
         { "landscape", OPTION_VAL_LANDSCAPE_AST },
         { "portrait",  OPTION_VAL_PORTRAIT_AST },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_AST,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_AST,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_AST },
         { "disabled", OPTION_VAL_LANDSCAPE_AST },
         { "enabled",  OPTION_VAL_PORTRAIT_AST },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_AST,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_AST,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_AST },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_AST },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_AST },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_AST },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_AST },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_AST },
         { "gb_light",               OPTION_VAL_GB_LIGHT_AST },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_AST },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_AST },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_AST },
         { "digivice",               OPTION_VAL_DIGIVICE_AST },
         { "game_com",               OPTION_VAL_GAME_COM_AST },
         { "gameking",               OPTION_VAL_GAMEKING_AST },
         { "game_master",            OPTION_VAL_GAME_MASTER_AST },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_AST },
         { "greenscale",             OPTION_VAL_GREENSCALE_AST },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_AST },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_AST },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_AST },
         { "microvision",            OPTION_VAL_MICROVISION_AST },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_AST },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_AST },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_AST },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_AST },
         { "ti_83",                  OPTION_VAL_TI_83_AST },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_AST },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_AST },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_AST,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_AST,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_AST },
         { "24bit", OPTION_VAL_24BIT_AST },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_AST,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_AST,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_AST },
         { "manual",   OPTION_VAL_MANUAL_AST },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_AST,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_AST,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_AST,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_AST,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ast = {
   option_cats_ast,
   option_defs_ast
};

/* RETRO_LANGUAGE_CA */

#define WSWAN_ROTATE_DISPLAY_LABEL_CA NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_CA NULL
#define OPTION_VAL_MANUAL_CA NULL
#define OPTION_VAL_LANDSCAPE_CA NULL
#define OPTION_VAL_PORTRAIT_CA NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_CA NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_CA NULL
#define OPTION_VAL_AUTO_CA NULL
#define WSWAN_MONO_PALETTE_LABEL_CA NULL
#define WSWAN_MONO_PALETTE_INFO_0_CA NULL
#define OPTION_VAL_DEFAULT_CA NULL
#define OPTION_VAL_WONDERSWAN_CA NULL
#define OPTION_VAL_WONDESWAN_COLOR_CA NULL
#define OPTION_VAL_SWANCRYSTAL_CA NULL
#define OPTION_VAL_GB_DMG_CA NULL
#define OPTION_VAL_GB_POCKET_CA NULL
#define OPTION_VAL_GB_LIGHT_CA NULL
#define OPTION_VAL_BLOSSOM_PINK_CA NULL
#define OPTION_VAL_BUBBLES_BLUE_CA NULL
#define OPTION_VAL_BUTTERCUP_GREEN_CA NULL
#define OPTION_VAL_DIGIVICE_CA NULL
#define OPTION_VAL_GAME_COM_CA NULL
#define OPTION_VAL_GAMEKING_CA NULL
#define OPTION_VAL_GAME_MASTER_CA NULL
#define OPTION_VAL_GOLDEN_WILD_CA NULL
#define OPTION_VAL_GREENSCALE_CA NULL
#define OPTION_VAL_HOKAGE_ORANGE_CA NULL
#define OPTION_VAL_LABO_FAWN_CA NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CA NULL
#define OPTION_VAL_MICROVISION_CA NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_CA NULL
#define OPTION_VAL_ODYSSEY_GOLD_CA NULL
#define OPTION_VAL_SHINY_SKY_BLUE_CA NULL
#define OPTION_VAL_SLIME_BLUE_CA NULL
#define OPTION_VAL_TI_83_CA NULL
#define OPTION_VAL_TRAVEL_WOOD_CA NULL
#define OPTION_VAL_VIRTUAL_BOY_CA NULL
#define WSWAN_GFX_COLORS_LABEL_CA NULL
#define WSWAN_GFX_COLORS_INFO_0_CA NULL
#define OPTION_VAL_16BIT_CA NULL
#define OPTION_VAL_24BIT_CA NULL
#define WSWAN_FRAMESKIP_LABEL_CA NULL
#define WSWAN_FRAMESKIP_INFO_0_CA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_CA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CA NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_CA NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_CA NULL

struct retro_core_option_v2_category option_cats_ca[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ca[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_CA,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_CA,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_CA },
         { "landscape", OPTION_VAL_LANDSCAPE_CA },
         { "portrait",  OPTION_VAL_PORTRAIT_CA },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_CA,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_CA,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_CA },
         { "disabled", OPTION_VAL_LANDSCAPE_CA },
         { "enabled",  OPTION_VAL_PORTRAIT_CA },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_CA,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_CA,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_CA },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_CA },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_CA },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_CA },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_CA },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_CA },
         { "gb_light",               OPTION_VAL_GB_LIGHT_CA },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_CA },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_CA },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_CA },
         { "digivice",               OPTION_VAL_DIGIVICE_CA },
         { "game_com",               OPTION_VAL_GAME_COM_CA },
         { "gameking",               OPTION_VAL_GAMEKING_CA },
         { "game_master",            OPTION_VAL_GAME_MASTER_CA },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_CA },
         { "greenscale",             OPTION_VAL_GREENSCALE_CA },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_CA },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_CA },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CA },
         { "microvision",            OPTION_VAL_MICROVISION_CA },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_CA },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_CA },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_CA },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_CA },
         { "ti_83",                  OPTION_VAL_TI_83_CA },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_CA },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_CA },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_CA,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_CA,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_CA },
         { "24bit", OPTION_VAL_24BIT_CA },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_CA,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_CA,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_CA },
         { "manual",   OPTION_VAL_MANUAL_CA },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_CA,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CA,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_CA,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_CA,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ca = {
   option_cats_ca,
   option_defs_ca
};

/* RETRO_LANGUAGE_CHS */

#define WSWAN_ROTATE_DISPLAY_LABEL_CHS NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_CHS NULL
#define OPTION_VAL_MANUAL_CHS NULL
#define OPTION_VAL_LANDSCAPE_CHS NULL
#define OPTION_VAL_PORTRAIT_CHS NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_CHS NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_CHS NULL
#define OPTION_VAL_AUTO_CHS NULL
#define WSWAN_MONO_PALETTE_LABEL_CHS NULL
#define WSWAN_MONO_PALETTE_INFO_0_CHS NULL
#define OPTION_VAL_DEFAULT_CHS NULL
#define OPTION_VAL_WONDERSWAN_CHS NULL
#define OPTION_VAL_WONDESWAN_COLOR_CHS NULL
#define OPTION_VAL_SWANCRYSTAL_CHS NULL
#define OPTION_VAL_GB_DMG_CHS NULL
#define OPTION_VAL_GB_POCKET_CHS NULL
#define OPTION_VAL_GB_LIGHT_CHS NULL
#define OPTION_VAL_BLOSSOM_PINK_CHS NULL
#define OPTION_VAL_BUBBLES_BLUE_CHS NULL
#define OPTION_VAL_BUTTERCUP_GREEN_CHS NULL
#define OPTION_VAL_DIGIVICE_CHS NULL
#define OPTION_VAL_GAME_COM_CHS NULL
#define OPTION_VAL_GAMEKING_CHS NULL
#define OPTION_VAL_GAME_MASTER_CHS NULL
#define OPTION_VAL_GOLDEN_WILD_CHS NULL
#define OPTION_VAL_GREENSCALE_CHS NULL
#define OPTION_VAL_HOKAGE_ORANGE_CHS NULL
#define OPTION_VAL_LABO_FAWN_CHS NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CHS NULL
#define OPTION_VAL_MICROVISION_CHS NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_CHS NULL
#define OPTION_VAL_ODYSSEY_GOLD_CHS NULL
#define OPTION_VAL_SHINY_SKY_BLUE_CHS NULL
#define OPTION_VAL_SLIME_BLUE_CHS NULL
#define OPTION_VAL_TI_83_CHS NULL
#define OPTION_VAL_TRAVEL_WOOD_CHS NULL
#define OPTION_VAL_VIRTUAL_BOY_CHS NULL
#define WSWAN_GFX_COLORS_LABEL_CHS NULL
#define WSWAN_GFX_COLORS_INFO_0_CHS NULL
#define OPTION_VAL_16BIT_CHS NULL
#define OPTION_VAL_24BIT_CHS NULL
#define WSWAN_FRAMESKIP_LABEL_CHS NULL
#define WSWAN_FRAMESKIP_INFO_0_CHS NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_CHS NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CHS NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_CHS NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_CHS NULL

struct retro_core_option_v2_category option_cats_chs[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_chs[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_CHS,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_CHS },
         { "landscape", OPTION_VAL_LANDSCAPE_CHS },
         { "portrait",  OPTION_VAL_PORTRAIT_CHS },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_CHS,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_CHS },
         { "disabled", OPTION_VAL_LANDSCAPE_CHS },
         { "enabled",  OPTION_VAL_PORTRAIT_CHS },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_CHS,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_CHS },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_CHS },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_CHS },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_CHS },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_CHS },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_CHS },
         { "gb_light",               OPTION_VAL_GB_LIGHT_CHS },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_CHS },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_CHS },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_CHS },
         { "digivice",               OPTION_VAL_DIGIVICE_CHS },
         { "game_com",               OPTION_VAL_GAME_COM_CHS },
         { "gameking",               OPTION_VAL_GAMEKING_CHS },
         { "game_master",            OPTION_VAL_GAME_MASTER_CHS },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_CHS },
         { "greenscale",             OPTION_VAL_GREENSCALE_CHS },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_CHS },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_CHS },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CHS },
         { "microvision",            OPTION_VAL_MICROVISION_CHS },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_CHS },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_CHS },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_CHS },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_CHS },
         { "ti_83",                  OPTION_VAL_TI_83_CHS },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_CHS },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_CHS },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_CHS,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_CHS },
         { "24bit", OPTION_VAL_24BIT_CHS },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_CHS,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_CHS },
         { "manual",   OPTION_VAL_MANUAL_CHS },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_CHS,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_CHS,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_CHS,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_chs = {
   option_cats_chs,
   option_defs_chs
};

/* RETRO_LANGUAGE_CHT */

#define WSWAN_ROTATE_DISPLAY_LABEL_CHT NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_CHT NULL
#define OPTION_VAL_MANUAL_CHT NULL
#define OPTION_VAL_LANDSCAPE_CHT NULL
#define OPTION_VAL_PORTRAIT_CHT NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_CHT NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_CHT NULL
#define OPTION_VAL_AUTO_CHT NULL
#define WSWAN_MONO_PALETTE_LABEL_CHT NULL
#define WSWAN_MONO_PALETTE_INFO_0_CHT NULL
#define OPTION_VAL_DEFAULT_CHT NULL
#define OPTION_VAL_WONDERSWAN_CHT NULL
#define OPTION_VAL_WONDESWAN_COLOR_CHT NULL
#define OPTION_VAL_SWANCRYSTAL_CHT NULL
#define OPTION_VAL_GB_DMG_CHT NULL
#define OPTION_VAL_GB_POCKET_CHT NULL
#define OPTION_VAL_GB_LIGHT_CHT NULL
#define OPTION_VAL_BLOSSOM_PINK_CHT NULL
#define OPTION_VAL_BUBBLES_BLUE_CHT NULL
#define OPTION_VAL_BUTTERCUP_GREEN_CHT NULL
#define OPTION_VAL_DIGIVICE_CHT NULL
#define OPTION_VAL_GAME_COM_CHT NULL
#define OPTION_VAL_GAMEKING_CHT NULL
#define OPTION_VAL_GAME_MASTER_CHT NULL
#define OPTION_VAL_GOLDEN_WILD_CHT NULL
#define OPTION_VAL_GREENSCALE_CHT NULL
#define OPTION_VAL_HOKAGE_ORANGE_CHT NULL
#define OPTION_VAL_LABO_FAWN_CHT NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CHT NULL
#define OPTION_VAL_MICROVISION_CHT NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_CHT NULL
#define OPTION_VAL_ODYSSEY_GOLD_CHT NULL
#define OPTION_VAL_SHINY_SKY_BLUE_CHT NULL
#define OPTION_VAL_SLIME_BLUE_CHT NULL
#define OPTION_VAL_TI_83_CHT NULL
#define OPTION_VAL_TRAVEL_WOOD_CHT NULL
#define OPTION_VAL_VIRTUAL_BOY_CHT NULL
#define WSWAN_GFX_COLORS_LABEL_CHT NULL
#define WSWAN_GFX_COLORS_INFO_0_CHT NULL
#define OPTION_VAL_16BIT_CHT NULL
#define OPTION_VAL_24BIT_CHT NULL
#define WSWAN_FRAMESKIP_LABEL_CHT NULL
#define WSWAN_FRAMESKIP_INFO_0_CHT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_CHT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CHT NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_CHT NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_CHT NULL

struct retro_core_option_v2_category option_cats_cht[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cht[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_CHT,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_CHT },
         { "landscape", OPTION_VAL_LANDSCAPE_CHT },
         { "portrait",  OPTION_VAL_PORTRAIT_CHT },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_CHT,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_CHT },
         { "disabled", OPTION_VAL_LANDSCAPE_CHT },
         { "enabled",  OPTION_VAL_PORTRAIT_CHT },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_CHT,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_CHT },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_CHT },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_CHT },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_CHT },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_CHT },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_CHT },
         { "gb_light",               OPTION_VAL_GB_LIGHT_CHT },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_CHT },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_CHT },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_CHT },
         { "digivice",               OPTION_VAL_DIGIVICE_CHT },
         { "game_com",               OPTION_VAL_GAME_COM_CHT },
         { "gameking",               OPTION_VAL_GAMEKING_CHT },
         { "game_master",            OPTION_VAL_GAME_MASTER_CHT },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_CHT },
         { "greenscale",             OPTION_VAL_GREENSCALE_CHT },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_CHT },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_CHT },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CHT },
         { "microvision",            OPTION_VAL_MICROVISION_CHT },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_CHT },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_CHT },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_CHT },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_CHT },
         { "ti_83",                  OPTION_VAL_TI_83_CHT },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_CHT },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_CHT },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_CHT,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_CHT },
         { "24bit", OPTION_VAL_24BIT_CHT },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_CHT,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_CHT },
         { "manual",   OPTION_VAL_MANUAL_CHT },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_CHT,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_CHT,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_CHT,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cht = {
   option_cats_cht,
   option_defs_cht
};

/* RETRO_LANGUAGE_CS */

#define WSWAN_ROTATE_DISPLAY_LABEL_CS NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_CS NULL
#define OPTION_VAL_MANUAL_CS NULL
#define OPTION_VAL_LANDSCAPE_CS NULL
#define OPTION_VAL_PORTRAIT_CS NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_CS NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_CS NULL
#define OPTION_VAL_AUTO_CS NULL
#define WSWAN_MONO_PALETTE_LABEL_CS NULL
#define WSWAN_MONO_PALETTE_INFO_0_CS NULL
#define OPTION_VAL_DEFAULT_CS NULL
#define OPTION_VAL_WONDERSWAN_CS NULL
#define OPTION_VAL_WONDESWAN_COLOR_CS NULL
#define OPTION_VAL_SWANCRYSTAL_CS NULL
#define OPTION_VAL_GB_DMG_CS NULL
#define OPTION_VAL_GB_POCKET_CS NULL
#define OPTION_VAL_GB_LIGHT_CS NULL
#define OPTION_VAL_BLOSSOM_PINK_CS NULL
#define OPTION_VAL_BUBBLES_BLUE_CS NULL
#define OPTION_VAL_BUTTERCUP_GREEN_CS NULL
#define OPTION_VAL_DIGIVICE_CS NULL
#define OPTION_VAL_GAME_COM_CS NULL
#define OPTION_VAL_GAMEKING_CS NULL
#define OPTION_VAL_GAME_MASTER_CS NULL
#define OPTION_VAL_GOLDEN_WILD_CS NULL
#define OPTION_VAL_GREENSCALE_CS NULL
#define OPTION_VAL_HOKAGE_ORANGE_CS NULL
#define OPTION_VAL_LABO_FAWN_CS NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CS NULL
#define OPTION_VAL_MICROVISION_CS NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_CS NULL
#define OPTION_VAL_ODYSSEY_GOLD_CS NULL
#define OPTION_VAL_SHINY_SKY_BLUE_CS NULL
#define OPTION_VAL_SLIME_BLUE_CS NULL
#define OPTION_VAL_TI_83_CS NULL
#define OPTION_VAL_TRAVEL_WOOD_CS NULL
#define OPTION_VAL_VIRTUAL_BOY_CS NULL
#define WSWAN_GFX_COLORS_LABEL_CS NULL
#define WSWAN_GFX_COLORS_INFO_0_CS NULL
#define OPTION_VAL_16BIT_CS NULL
#define OPTION_VAL_24BIT_CS NULL
#define WSWAN_FRAMESKIP_LABEL_CS NULL
#define WSWAN_FRAMESKIP_INFO_0_CS NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_CS NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CS NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_CS NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_CS NULL

struct retro_core_option_v2_category option_cats_cs[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cs[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_CS,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_CS,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_CS },
         { "landscape", OPTION_VAL_LANDSCAPE_CS },
         { "portrait",  OPTION_VAL_PORTRAIT_CS },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_CS,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_CS,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_CS },
         { "disabled", OPTION_VAL_LANDSCAPE_CS },
         { "enabled",  OPTION_VAL_PORTRAIT_CS },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_CS,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_CS,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_CS },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_CS },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_CS },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_CS },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_CS },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_CS },
         { "gb_light",               OPTION_VAL_GB_LIGHT_CS },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_CS },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_CS },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_CS },
         { "digivice",               OPTION_VAL_DIGIVICE_CS },
         { "game_com",               OPTION_VAL_GAME_COM_CS },
         { "gameking",               OPTION_VAL_GAMEKING_CS },
         { "game_master",            OPTION_VAL_GAME_MASTER_CS },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_CS },
         { "greenscale",             OPTION_VAL_GREENSCALE_CS },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_CS },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_CS },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CS },
         { "microvision",            OPTION_VAL_MICROVISION_CS },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_CS },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_CS },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_CS },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_CS },
         { "ti_83",                  OPTION_VAL_TI_83_CS },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_CS },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_CS },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_CS,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_CS,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_CS },
         { "24bit", OPTION_VAL_24BIT_CS },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_CS,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_CS,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_CS },
         { "manual",   OPTION_VAL_MANUAL_CS },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_CS,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CS,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_CS,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_CS,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cs = {
   option_cats_cs,
   option_defs_cs
};

/* RETRO_LANGUAGE_CY */

#define WSWAN_ROTATE_DISPLAY_LABEL_CY NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_CY NULL
#define OPTION_VAL_MANUAL_CY NULL
#define OPTION_VAL_LANDSCAPE_CY NULL
#define OPTION_VAL_PORTRAIT_CY NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_CY NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_CY NULL
#define OPTION_VAL_AUTO_CY NULL
#define WSWAN_MONO_PALETTE_LABEL_CY NULL
#define WSWAN_MONO_PALETTE_INFO_0_CY NULL
#define OPTION_VAL_DEFAULT_CY NULL
#define OPTION_VAL_WONDERSWAN_CY NULL
#define OPTION_VAL_WONDESWAN_COLOR_CY NULL
#define OPTION_VAL_SWANCRYSTAL_CY NULL
#define OPTION_VAL_GB_DMG_CY NULL
#define OPTION_VAL_GB_POCKET_CY NULL
#define OPTION_VAL_GB_LIGHT_CY NULL
#define OPTION_VAL_BLOSSOM_PINK_CY NULL
#define OPTION_VAL_BUBBLES_BLUE_CY NULL
#define OPTION_VAL_BUTTERCUP_GREEN_CY NULL
#define OPTION_VAL_DIGIVICE_CY NULL
#define OPTION_VAL_GAME_COM_CY NULL
#define OPTION_VAL_GAMEKING_CY NULL
#define OPTION_VAL_GAME_MASTER_CY NULL
#define OPTION_VAL_GOLDEN_WILD_CY NULL
#define OPTION_VAL_GREENSCALE_CY NULL
#define OPTION_VAL_HOKAGE_ORANGE_CY NULL
#define OPTION_VAL_LABO_FAWN_CY NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CY NULL
#define OPTION_VAL_MICROVISION_CY NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_CY NULL
#define OPTION_VAL_ODYSSEY_GOLD_CY NULL
#define OPTION_VAL_SHINY_SKY_BLUE_CY NULL
#define OPTION_VAL_SLIME_BLUE_CY NULL
#define OPTION_VAL_TI_83_CY NULL
#define OPTION_VAL_TRAVEL_WOOD_CY NULL
#define OPTION_VAL_VIRTUAL_BOY_CY NULL
#define WSWAN_GFX_COLORS_LABEL_CY NULL
#define WSWAN_GFX_COLORS_INFO_0_CY NULL
#define OPTION_VAL_16BIT_CY NULL
#define OPTION_VAL_24BIT_CY NULL
#define WSWAN_FRAMESKIP_LABEL_CY NULL
#define WSWAN_FRAMESKIP_INFO_0_CY NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_CY NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CY NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_CY NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_CY NULL

struct retro_core_option_v2_category option_cats_cy[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cy[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_CY,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_CY,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_CY },
         { "landscape", OPTION_VAL_LANDSCAPE_CY },
         { "portrait",  OPTION_VAL_PORTRAIT_CY },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_CY,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_CY,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_CY },
         { "disabled", OPTION_VAL_LANDSCAPE_CY },
         { "enabled",  OPTION_VAL_PORTRAIT_CY },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_CY,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_CY,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_CY },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_CY },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_CY },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_CY },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_CY },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_CY },
         { "gb_light",               OPTION_VAL_GB_LIGHT_CY },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_CY },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_CY },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_CY },
         { "digivice",               OPTION_VAL_DIGIVICE_CY },
         { "game_com",               OPTION_VAL_GAME_COM_CY },
         { "gameking",               OPTION_VAL_GAMEKING_CY },
         { "game_master",            OPTION_VAL_GAME_MASTER_CY },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_CY },
         { "greenscale",             OPTION_VAL_GREENSCALE_CY },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_CY },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_CY },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_CY },
         { "microvision",            OPTION_VAL_MICROVISION_CY },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_CY },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_CY },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_CY },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_CY },
         { "ti_83",                  OPTION_VAL_TI_83_CY },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_CY },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_CY },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_CY,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_CY,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_CY },
         { "24bit", OPTION_VAL_24BIT_CY },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_CY,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_CY,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_CY },
         { "manual",   OPTION_VAL_MANUAL_CY },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_CY,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_CY,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_CY,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_CY,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_cy = {
   option_cats_cy,
   option_defs_cy
};

/* RETRO_LANGUAGE_DA */

#define WSWAN_ROTATE_DISPLAY_LABEL_DA NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_DA NULL
#define OPTION_VAL_MANUAL_DA NULL
#define OPTION_VAL_LANDSCAPE_DA NULL
#define OPTION_VAL_PORTRAIT_DA NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_DA NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_DA NULL
#define OPTION_VAL_AUTO_DA NULL
#define WSWAN_MONO_PALETTE_LABEL_DA NULL
#define WSWAN_MONO_PALETTE_INFO_0_DA NULL
#define OPTION_VAL_DEFAULT_DA NULL
#define OPTION_VAL_WONDERSWAN_DA NULL
#define OPTION_VAL_WONDESWAN_COLOR_DA NULL
#define OPTION_VAL_SWANCRYSTAL_DA NULL
#define OPTION_VAL_GB_DMG_DA NULL
#define OPTION_VAL_GB_POCKET_DA NULL
#define OPTION_VAL_GB_LIGHT_DA NULL
#define OPTION_VAL_BLOSSOM_PINK_DA NULL
#define OPTION_VAL_BUBBLES_BLUE_DA NULL
#define OPTION_VAL_BUTTERCUP_GREEN_DA NULL
#define OPTION_VAL_DIGIVICE_DA NULL
#define OPTION_VAL_GAME_COM_DA NULL
#define OPTION_VAL_GAMEKING_DA NULL
#define OPTION_VAL_GAME_MASTER_DA NULL
#define OPTION_VAL_GOLDEN_WILD_DA NULL
#define OPTION_VAL_GREENSCALE_DA NULL
#define OPTION_VAL_HOKAGE_ORANGE_DA NULL
#define OPTION_VAL_LABO_FAWN_DA NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_DA NULL
#define OPTION_VAL_MICROVISION_DA NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_DA NULL
#define OPTION_VAL_ODYSSEY_GOLD_DA NULL
#define OPTION_VAL_SHINY_SKY_BLUE_DA NULL
#define OPTION_VAL_SLIME_BLUE_DA NULL
#define OPTION_VAL_TI_83_DA NULL
#define OPTION_VAL_TRAVEL_WOOD_DA NULL
#define OPTION_VAL_VIRTUAL_BOY_DA NULL
#define WSWAN_GFX_COLORS_LABEL_DA NULL
#define WSWAN_GFX_COLORS_INFO_0_DA NULL
#define OPTION_VAL_16BIT_DA NULL
#define OPTION_VAL_24BIT_DA NULL
#define WSWAN_FRAMESKIP_LABEL_DA NULL
#define WSWAN_FRAMESKIP_INFO_0_DA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_DA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_DA NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_DA NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_DA NULL

struct retro_core_option_v2_category option_cats_da[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_da[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_DA,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_DA,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_DA },
         { "landscape", OPTION_VAL_LANDSCAPE_DA },
         { "portrait",  OPTION_VAL_PORTRAIT_DA },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_DA,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_DA,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_DA },
         { "disabled", OPTION_VAL_LANDSCAPE_DA },
         { "enabled",  OPTION_VAL_PORTRAIT_DA },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_DA,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_DA,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_DA },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_DA },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_DA },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_DA },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_DA },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_DA },
         { "gb_light",               OPTION_VAL_GB_LIGHT_DA },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_DA },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_DA },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_DA },
         { "digivice",               OPTION_VAL_DIGIVICE_DA },
         { "game_com",               OPTION_VAL_GAME_COM_DA },
         { "gameking",               OPTION_VAL_GAMEKING_DA },
         { "game_master",            OPTION_VAL_GAME_MASTER_DA },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_DA },
         { "greenscale",             OPTION_VAL_GREENSCALE_DA },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_DA },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_DA },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_DA },
         { "microvision",            OPTION_VAL_MICROVISION_DA },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_DA },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_DA },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_DA },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_DA },
         { "ti_83",                  OPTION_VAL_TI_83_DA },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_DA },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_DA },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_DA,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_DA,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_DA },
         { "24bit", OPTION_VAL_24BIT_DA },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_DA,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_DA,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_DA },
         { "manual",   OPTION_VAL_MANUAL_DA },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_DA,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_DA,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_DA,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_DA,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_da = {
   option_cats_da,
   option_defs_da
};

/* RETRO_LANGUAGE_DE */

#define WSWAN_ROTATE_DISPLAY_LABEL_DE NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_DE NULL
#define OPTION_VAL_MANUAL_DE NULL
#define OPTION_VAL_LANDSCAPE_DE NULL
#define OPTION_VAL_PORTRAIT_DE NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_DE NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_DE NULL
#define OPTION_VAL_AUTO_DE NULL
#define WSWAN_MONO_PALETTE_LABEL_DE NULL
#define WSWAN_MONO_PALETTE_INFO_0_DE NULL
#define OPTION_VAL_DEFAULT_DE NULL
#define OPTION_VAL_WONDERSWAN_DE NULL
#define OPTION_VAL_WONDESWAN_COLOR_DE NULL
#define OPTION_VAL_SWANCRYSTAL_DE NULL
#define OPTION_VAL_GB_DMG_DE NULL
#define OPTION_VAL_GB_POCKET_DE NULL
#define OPTION_VAL_GB_LIGHT_DE NULL
#define OPTION_VAL_BLOSSOM_PINK_DE NULL
#define OPTION_VAL_BUBBLES_BLUE_DE NULL
#define OPTION_VAL_BUTTERCUP_GREEN_DE NULL
#define OPTION_VAL_DIGIVICE_DE NULL
#define OPTION_VAL_GAME_COM_DE NULL
#define OPTION_VAL_GAMEKING_DE NULL
#define OPTION_VAL_GAME_MASTER_DE NULL
#define OPTION_VAL_GOLDEN_WILD_DE NULL
#define OPTION_VAL_GREENSCALE_DE NULL
#define OPTION_VAL_HOKAGE_ORANGE_DE NULL
#define OPTION_VAL_LABO_FAWN_DE NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_DE NULL
#define OPTION_VAL_MICROVISION_DE NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_DE NULL
#define OPTION_VAL_ODYSSEY_GOLD_DE NULL
#define OPTION_VAL_SHINY_SKY_BLUE_DE NULL
#define OPTION_VAL_SLIME_BLUE_DE NULL
#define OPTION_VAL_TI_83_DE NULL
#define OPTION_VAL_TRAVEL_WOOD_DE NULL
#define OPTION_VAL_VIRTUAL_BOY_DE NULL
#define WSWAN_GFX_COLORS_LABEL_DE NULL
#define WSWAN_GFX_COLORS_INFO_0_DE NULL
#define OPTION_VAL_16BIT_DE NULL
#define OPTION_VAL_24BIT_DE NULL
#define WSWAN_FRAMESKIP_LABEL_DE NULL
#define WSWAN_FRAMESKIP_INFO_0_DE NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_DE NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_DE NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_DE NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_DE NULL

struct retro_core_option_v2_category option_cats_de[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_de[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_DE,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_DE,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_DE },
         { "landscape", OPTION_VAL_LANDSCAPE_DE },
         { "portrait",  OPTION_VAL_PORTRAIT_DE },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_DE,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_DE,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_DE },
         { "disabled", OPTION_VAL_LANDSCAPE_DE },
         { "enabled",  OPTION_VAL_PORTRAIT_DE },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_DE,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_DE,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_DE },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_DE },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_DE },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_DE },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_DE },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_DE },
         { "gb_light",               OPTION_VAL_GB_LIGHT_DE },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_DE },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_DE },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_DE },
         { "digivice",               OPTION_VAL_DIGIVICE_DE },
         { "game_com",               OPTION_VAL_GAME_COM_DE },
         { "gameking",               OPTION_VAL_GAMEKING_DE },
         { "game_master",            OPTION_VAL_GAME_MASTER_DE },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_DE },
         { "greenscale",             OPTION_VAL_GREENSCALE_DE },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_DE },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_DE },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_DE },
         { "microvision",            OPTION_VAL_MICROVISION_DE },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_DE },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_DE },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_DE },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_DE },
         { "ti_83",                  OPTION_VAL_TI_83_DE },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_DE },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_DE },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_DE,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_DE,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_DE },
         { "24bit", OPTION_VAL_24BIT_DE },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_DE,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_DE,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_DE },
         { "manual",   OPTION_VAL_MANUAL_DE },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_DE,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_DE,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_DE,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_DE,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_de = {
   option_cats_de,
   option_defs_de
};

/* RETRO_LANGUAGE_EL */

#define WSWAN_ROTATE_DISPLAY_LABEL_EL NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_EL NULL
#define OPTION_VAL_MANUAL_EL NULL
#define OPTION_VAL_LANDSCAPE_EL NULL
#define OPTION_VAL_PORTRAIT_EL NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_EL NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_EL NULL
#define OPTION_VAL_AUTO_EL NULL
#define WSWAN_MONO_PALETTE_LABEL_EL NULL
#define WSWAN_MONO_PALETTE_INFO_0_EL NULL
#define OPTION_VAL_DEFAULT_EL NULL
#define OPTION_VAL_WONDERSWAN_EL NULL
#define OPTION_VAL_WONDESWAN_COLOR_EL NULL
#define OPTION_VAL_SWANCRYSTAL_EL NULL
#define OPTION_VAL_GB_DMG_EL NULL
#define OPTION_VAL_GB_POCKET_EL NULL
#define OPTION_VAL_GB_LIGHT_EL NULL
#define OPTION_VAL_BLOSSOM_PINK_EL NULL
#define OPTION_VAL_BUBBLES_BLUE_EL NULL
#define OPTION_VAL_BUTTERCUP_GREEN_EL NULL
#define OPTION_VAL_DIGIVICE_EL NULL
#define OPTION_VAL_GAME_COM_EL NULL
#define OPTION_VAL_GAMEKING_EL NULL
#define OPTION_VAL_GAME_MASTER_EL NULL
#define OPTION_VAL_GOLDEN_WILD_EL NULL
#define OPTION_VAL_GREENSCALE_EL NULL
#define OPTION_VAL_HOKAGE_ORANGE_EL NULL
#define OPTION_VAL_LABO_FAWN_EL NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_EL NULL
#define OPTION_VAL_MICROVISION_EL NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_EL NULL
#define OPTION_VAL_ODYSSEY_GOLD_EL NULL
#define OPTION_VAL_SHINY_SKY_BLUE_EL NULL
#define OPTION_VAL_SLIME_BLUE_EL NULL
#define OPTION_VAL_TI_83_EL NULL
#define OPTION_VAL_TRAVEL_WOOD_EL NULL
#define OPTION_VAL_VIRTUAL_BOY_EL NULL
#define WSWAN_GFX_COLORS_LABEL_EL NULL
#define WSWAN_GFX_COLORS_INFO_0_EL NULL
#define OPTION_VAL_16BIT_EL NULL
#define OPTION_VAL_24BIT_EL NULL
#define WSWAN_FRAMESKIP_LABEL_EL NULL
#define WSWAN_FRAMESKIP_INFO_0_EL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_EL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_EL NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_EL NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_EL NULL

struct retro_core_option_v2_category option_cats_el[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_el[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_EL,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_EL,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_EL },
         { "landscape", OPTION_VAL_LANDSCAPE_EL },
         { "portrait",  OPTION_VAL_PORTRAIT_EL },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_EL,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_EL,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_EL },
         { "disabled", OPTION_VAL_LANDSCAPE_EL },
         { "enabled",  OPTION_VAL_PORTRAIT_EL },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_EL,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_EL,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_EL },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_EL },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_EL },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_EL },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_EL },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_EL },
         { "gb_light",               OPTION_VAL_GB_LIGHT_EL },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_EL },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_EL },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_EL },
         { "digivice",               OPTION_VAL_DIGIVICE_EL },
         { "game_com",               OPTION_VAL_GAME_COM_EL },
         { "gameking",               OPTION_VAL_GAMEKING_EL },
         { "game_master",            OPTION_VAL_GAME_MASTER_EL },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_EL },
         { "greenscale",             OPTION_VAL_GREENSCALE_EL },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_EL },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_EL },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_EL },
         { "microvision",            OPTION_VAL_MICROVISION_EL },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_EL },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_EL },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_EL },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_EL },
         { "ti_83",                  OPTION_VAL_TI_83_EL },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_EL },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_EL },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_EL,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_EL,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_EL },
         { "24bit", OPTION_VAL_24BIT_EL },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_EL,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_EL,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_EL },
         { "manual",   OPTION_VAL_MANUAL_EL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_EL,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_EL,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_EL,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_EL,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_el = {
   option_cats_el,
   option_defs_el
};

/* RETRO_LANGUAGE_EO */

#define WSWAN_ROTATE_DISPLAY_LABEL_EO NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_EO NULL
#define OPTION_VAL_MANUAL_EO NULL
#define OPTION_VAL_LANDSCAPE_EO NULL
#define OPTION_VAL_PORTRAIT_EO NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_EO NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_EO NULL
#define OPTION_VAL_AUTO_EO NULL
#define WSWAN_MONO_PALETTE_LABEL_EO NULL
#define WSWAN_MONO_PALETTE_INFO_0_EO NULL
#define OPTION_VAL_DEFAULT_EO NULL
#define OPTION_VAL_WONDERSWAN_EO NULL
#define OPTION_VAL_WONDESWAN_COLOR_EO NULL
#define OPTION_VAL_SWANCRYSTAL_EO NULL
#define OPTION_VAL_GB_DMG_EO NULL
#define OPTION_VAL_GB_POCKET_EO NULL
#define OPTION_VAL_GB_LIGHT_EO NULL
#define OPTION_VAL_BLOSSOM_PINK_EO NULL
#define OPTION_VAL_BUBBLES_BLUE_EO NULL
#define OPTION_VAL_BUTTERCUP_GREEN_EO NULL
#define OPTION_VAL_DIGIVICE_EO NULL
#define OPTION_VAL_GAME_COM_EO NULL
#define OPTION_VAL_GAMEKING_EO NULL
#define OPTION_VAL_GAME_MASTER_EO NULL
#define OPTION_VAL_GOLDEN_WILD_EO NULL
#define OPTION_VAL_GREENSCALE_EO NULL
#define OPTION_VAL_HOKAGE_ORANGE_EO NULL
#define OPTION_VAL_LABO_FAWN_EO NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_EO NULL
#define OPTION_VAL_MICROVISION_EO NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_EO NULL
#define OPTION_VAL_ODYSSEY_GOLD_EO NULL
#define OPTION_VAL_SHINY_SKY_BLUE_EO NULL
#define OPTION_VAL_SLIME_BLUE_EO NULL
#define OPTION_VAL_TI_83_EO NULL
#define OPTION_VAL_TRAVEL_WOOD_EO NULL
#define OPTION_VAL_VIRTUAL_BOY_EO NULL
#define WSWAN_GFX_COLORS_LABEL_EO NULL
#define WSWAN_GFX_COLORS_INFO_0_EO NULL
#define OPTION_VAL_16BIT_EO NULL
#define OPTION_VAL_24BIT_EO NULL
#define WSWAN_FRAMESKIP_LABEL_EO NULL
#define WSWAN_FRAMESKIP_INFO_0_EO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_EO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_EO NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_EO NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_EO NULL

struct retro_core_option_v2_category option_cats_eo[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_eo[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_EO,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_EO,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_EO },
         { "landscape", OPTION_VAL_LANDSCAPE_EO },
         { "portrait",  OPTION_VAL_PORTRAIT_EO },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_EO,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_EO,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_EO },
         { "disabled", OPTION_VAL_LANDSCAPE_EO },
         { "enabled",  OPTION_VAL_PORTRAIT_EO },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_EO,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_EO,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_EO },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_EO },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_EO },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_EO },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_EO },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_EO },
         { "gb_light",               OPTION_VAL_GB_LIGHT_EO },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_EO },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_EO },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_EO },
         { "digivice",               OPTION_VAL_DIGIVICE_EO },
         { "game_com",               OPTION_VAL_GAME_COM_EO },
         { "gameking",               OPTION_VAL_GAMEKING_EO },
         { "game_master",            OPTION_VAL_GAME_MASTER_EO },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_EO },
         { "greenscale",             OPTION_VAL_GREENSCALE_EO },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_EO },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_EO },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_EO },
         { "microvision",            OPTION_VAL_MICROVISION_EO },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_EO },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_EO },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_EO },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_EO },
         { "ti_83",                  OPTION_VAL_TI_83_EO },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_EO },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_EO },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_EO,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_EO,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_EO },
         { "24bit", OPTION_VAL_24BIT_EO },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_EO,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_EO,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_EO },
         { "manual",   OPTION_VAL_MANUAL_EO },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_EO,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_EO,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_EO,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_EO,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_eo = {
   option_cats_eo,
   option_defs_eo
};

/* RETRO_LANGUAGE_ES */

#define WSWAN_ROTATE_DISPLAY_LABEL_ES NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_ES NULL
#define OPTION_VAL_MANUAL_ES NULL
#define OPTION_VAL_LANDSCAPE_ES NULL
#define OPTION_VAL_PORTRAIT_ES NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_ES NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_ES NULL
#define OPTION_VAL_AUTO_ES NULL
#define WSWAN_MONO_PALETTE_LABEL_ES NULL
#define WSWAN_MONO_PALETTE_INFO_0_ES NULL
#define OPTION_VAL_DEFAULT_ES NULL
#define OPTION_VAL_WONDERSWAN_ES NULL
#define OPTION_VAL_WONDESWAN_COLOR_ES NULL
#define OPTION_VAL_SWANCRYSTAL_ES NULL
#define OPTION_VAL_GB_DMG_ES NULL
#define OPTION_VAL_GB_POCKET_ES NULL
#define OPTION_VAL_GB_LIGHT_ES NULL
#define OPTION_VAL_BLOSSOM_PINK_ES NULL
#define OPTION_VAL_BUBBLES_BLUE_ES NULL
#define OPTION_VAL_BUTTERCUP_GREEN_ES NULL
#define OPTION_VAL_DIGIVICE_ES NULL
#define OPTION_VAL_GAME_COM_ES NULL
#define OPTION_VAL_GAMEKING_ES NULL
#define OPTION_VAL_GAME_MASTER_ES NULL
#define OPTION_VAL_GOLDEN_WILD_ES NULL
#define OPTION_VAL_GREENSCALE_ES NULL
#define OPTION_VAL_HOKAGE_ORANGE_ES NULL
#define OPTION_VAL_LABO_FAWN_ES NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_ES NULL
#define OPTION_VAL_MICROVISION_ES NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_ES NULL
#define OPTION_VAL_ODYSSEY_GOLD_ES NULL
#define OPTION_VAL_SHINY_SKY_BLUE_ES NULL
#define OPTION_VAL_SLIME_BLUE_ES NULL
#define OPTION_VAL_TI_83_ES NULL
#define OPTION_VAL_TRAVEL_WOOD_ES NULL
#define OPTION_VAL_VIRTUAL_BOY_ES NULL
#define WSWAN_GFX_COLORS_LABEL_ES NULL
#define WSWAN_GFX_COLORS_INFO_0_ES NULL
#define OPTION_VAL_16BIT_ES NULL
#define OPTION_VAL_24BIT_ES NULL
#define WSWAN_FRAMESKIP_LABEL_ES NULL
#define WSWAN_FRAMESKIP_INFO_0_ES NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_ES NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_ES NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_ES NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_ES NULL

struct retro_core_option_v2_category option_cats_es[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_es[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_ES,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_ES,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_ES },
         { "landscape", OPTION_VAL_LANDSCAPE_ES },
         { "portrait",  OPTION_VAL_PORTRAIT_ES },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_ES,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_ES,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_ES },
         { "disabled", OPTION_VAL_LANDSCAPE_ES },
         { "enabled",  OPTION_VAL_PORTRAIT_ES },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_ES,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_ES,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_ES },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_ES },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_ES },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_ES },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_ES },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_ES },
         { "gb_light",               OPTION_VAL_GB_LIGHT_ES },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_ES },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_ES },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_ES },
         { "digivice",               OPTION_VAL_DIGIVICE_ES },
         { "game_com",               OPTION_VAL_GAME_COM_ES },
         { "gameking",               OPTION_VAL_GAMEKING_ES },
         { "game_master",            OPTION_VAL_GAME_MASTER_ES },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_ES },
         { "greenscale",             OPTION_VAL_GREENSCALE_ES },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_ES },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_ES },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_ES },
         { "microvision",            OPTION_VAL_MICROVISION_ES },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_ES },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_ES },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_ES },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_ES },
         { "ti_83",                  OPTION_VAL_TI_83_ES },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_ES },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_ES },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_ES,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_ES,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_ES },
         { "24bit", OPTION_VAL_24BIT_ES },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_ES,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_ES,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_ES },
         { "manual",   OPTION_VAL_MANUAL_ES },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_ES,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_ES,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_ES,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_ES,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_es = {
   option_cats_es,
   option_defs_es
};

/* RETRO_LANGUAGE_FA */

#define WSWAN_ROTATE_DISPLAY_LABEL_FA NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_FA NULL
#define OPTION_VAL_MANUAL_FA NULL
#define OPTION_VAL_LANDSCAPE_FA NULL
#define OPTION_VAL_PORTRAIT_FA NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_FA NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_FA NULL
#define OPTION_VAL_AUTO_FA NULL
#define WSWAN_MONO_PALETTE_LABEL_FA NULL
#define WSWAN_MONO_PALETTE_INFO_0_FA NULL
#define OPTION_VAL_DEFAULT_FA NULL
#define OPTION_VAL_WONDERSWAN_FA NULL
#define OPTION_VAL_WONDESWAN_COLOR_FA NULL
#define OPTION_VAL_SWANCRYSTAL_FA NULL
#define OPTION_VAL_GB_DMG_FA NULL
#define OPTION_VAL_GB_POCKET_FA NULL
#define OPTION_VAL_GB_LIGHT_FA NULL
#define OPTION_VAL_BLOSSOM_PINK_FA NULL
#define OPTION_VAL_BUBBLES_BLUE_FA NULL
#define OPTION_VAL_BUTTERCUP_GREEN_FA NULL
#define OPTION_VAL_DIGIVICE_FA NULL
#define OPTION_VAL_GAME_COM_FA NULL
#define OPTION_VAL_GAMEKING_FA NULL
#define OPTION_VAL_GAME_MASTER_FA NULL
#define OPTION_VAL_GOLDEN_WILD_FA NULL
#define OPTION_VAL_GREENSCALE_FA NULL
#define OPTION_VAL_HOKAGE_ORANGE_FA NULL
#define OPTION_VAL_LABO_FAWN_FA NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FA NULL
#define OPTION_VAL_MICROVISION_FA NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_FA NULL
#define OPTION_VAL_ODYSSEY_GOLD_FA NULL
#define OPTION_VAL_SHINY_SKY_BLUE_FA NULL
#define OPTION_VAL_SLIME_BLUE_FA NULL
#define OPTION_VAL_TI_83_FA NULL
#define OPTION_VAL_TRAVEL_WOOD_FA NULL
#define OPTION_VAL_VIRTUAL_BOY_FA NULL
#define WSWAN_GFX_COLORS_LABEL_FA NULL
#define WSWAN_GFX_COLORS_INFO_0_FA NULL
#define OPTION_VAL_16BIT_FA NULL
#define OPTION_VAL_24BIT_FA NULL
#define WSWAN_FRAMESKIP_LABEL_FA NULL
#define WSWAN_FRAMESKIP_INFO_0_FA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_FA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FA NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_FA NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_FA NULL

struct retro_core_option_v2_category option_cats_fa[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fa[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_FA,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_FA,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_FA },
         { "landscape", OPTION_VAL_LANDSCAPE_FA },
         { "portrait",  OPTION_VAL_PORTRAIT_FA },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_FA,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_FA,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_FA },
         { "disabled", OPTION_VAL_LANDSCAPE_FA },
         { "enabled",  OPTION_VAL_PORTRAIT_FA },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_FA,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_FA,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_FA },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_FA },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_FA },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_FA },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_FA },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_FA },
         { "gb_light",               OPTION_VAL_GB_LIGHT_FA },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_FA },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_FA },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_FA },
         { "digivice",               OPTION_VAL_DIGIVICE_FA },
         { "game_com",               OPTION_VAL_GAME_COM_FA },
         { "gameking",               OPTION_VAL_GAMEKING_FA },
         { "game_master",            OPTION_VAL_GAME_MASTER_FA },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_FA },
         { "greenscale",             OPTION_VAL_GREENSCALE_FA },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_FA },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_FA },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FA },
         { "microvision",            OPTION_VAL_MICROVISION_FA },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_FA },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_FA },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_FA },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_FA },
         { "ti_83",                  OPTION_VAL_TI_83_FA },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_FA },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_FA },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_FA,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_FA,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_FA },
         { "24bit", OPTION_VAL_24BIT_FA },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_FA,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_FA,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_FA },
         { "manual",   OPTION_VAL_MANUAL_FA },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_FA,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FA,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_FA,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_FA,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fa = {
   option_cats_fa,
   option_defs_fa
};

/* RETRO_LANGUAGE_FI */

#define WSWAN_ROTATE_DISPLAY_LABEL_FI NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_FI NULL
#define OPTION_VAL_MANUAL_FI NULL
#define OPTION_VAL_LANDSCAPE_FI NULL
#define OPTION_VAL_PORTRAIT_FI NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_FI NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_FI NULL
#define OPTION_VAL_AUTO_FI NULL
#define WSWAN_MONO_PALETTE_LABEL_FI NULL
#define WSWAN_MONO_PALETTE_INFO_0_FI NULL
#define OPTION_VAL_DEFAULT_FI NULL
#define OPTION_VAL_WONDERSWAN_FI NULL
#define OPTION_VAL_WONDESWAN_COLOR_FI NULL
#define OPTION_VAL_SWANCRYSTAL_FI NULL
#define OPTION_VAL_GB_DMG_FI NULL
#define OPTION_VAL_GB_POCKET_FI NULL
#define OPTION_VAL_GB_LIGHT_FI NULL
#define OPTION_VAL_BLOSSOM_PINK_FI NULL
#define OPTION_VAL_BUBBLES_BLUE_FI NULL
#define OPTION_VAL_BUTTERCUP_GREEN_FI NULL
#define OPTION_VAL_DIGIVICE_FI NULL
#define OPTION_VAL_GAME_COM_FI NULL
#define OPTION_VAL_GAMEKING_FI NULL
#define OPTION_VAL_GAME_MASTER_FI NULL
#define OPTION_VAL_GOLDEN_WILD_FI NULL
#define OPTION_VAL_GREENSCALE_FI NULL
#define OPTION_VAL_HOKAGE_ORANGE_FI NULL
#define OPTION_VAL_LABO_FAWN_FI NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FI NULL
#define OPTION_VAL_MICROVISION_FI NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_FI NULL
#define OPTION_VAL_ODYSSEY_GOLD_FI NULL
#define OPTION_VAL_SHINY_SKY_BLUE_FI NULL
#define OPTION_VAL_SLIME_BLUE_FI NULL
#define OPTION_VAL_TI_83_FI NULL
#define OPTION_VAL_TRAVEL_WOOD_FI NULL
#define OPTION_VAL_VIRTUAL_BOY_FI NULL
#define WSWAN_GFX_COLORS_LABEL_FI NULL
#define WSWAN_GFX_COLORS_INFO_0_FI NULL
#define OPTION_VAL_16BIT_FI NULL
#define OPTION_VAL_24BIT_FI NULL
#define WSWAN_FRAMESKIP_LABEL_FI NULL
#define WSWAN_FRAMESKIP_INFO_0_FI NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_FI NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FI NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_FI NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_FI NULL

struct retro_core_option_v2_category option_cats_fi[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fi[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_FI,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_FI,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_FI },
         { "landscape", OPTION_VAL_LANDSCAPE_FI },
         { "portrait",  OPTION_VAL_PORTRAIT_FI },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_FI,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_FI,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_FI },
         { "disabled", OPTION_VAL_LANDSCAPE_FI },
         { "enabled",  OPTION_VAL_PORTRAIT_FI },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_FI,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_FI,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_FI },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_FI },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_FI },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_FI },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_FI },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_FI },
         { "gb_light",               OPTION_VAL_GB_LIGHT_FI },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_FI },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_FI },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_FI },
         { "digivice",               OPTION_VAL_DIGIVICE_FI },
         { "game_com",               OPTION_VAL_GAME_COM_FI },
         { "gameking",               OPTION_VAL_GAMEKING_FI },
         { "game_master",            OPTION_VAL_GAME_MASTER_FI },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_FI },
         { "greenscale",             OPTION_VAL_GREENSCALE_FI },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_FI },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_FI },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FI },
         { "microvision",            OPTION_VAL_MICROVISION_FI },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_FI },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_FI },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_FI },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_FI },
         { "ti_83",                  OPTION_VAL_TI_83_FI },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_FI },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_FI },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_FI,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_FI,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_FI },
         { "24bit", OPTION_VAL_24BIT_FI },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_FI,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_FI,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_FI },
         { "manual",   OPTION_VAL_MANUAL_FI },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_FI,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FI,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_FI,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_FI,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fi = {
   option_cats_fi,
   option_defs_fi
};

/* RETRO_LANGUAGE_FR */

#define WSWAN_ROTATE_DISPLAY_LABEL_FR NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_FR NULL
#define OPTION_VAL_MANUAL_FR NULL
#define OPTION_VAL_LANDSCAPE_FR NULL
#define OPTION_VAL_PORTRAIT_FR NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_FR NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_FR NULL
#define OPTION_VAL_AUTO_FR NULL
#define WSWAN_MONO_PALETTE_LABEL_FR NULL
#define WSWAN_MONO_PALETTE_INFO_0_FR NULL
#define OPTION_VAL_DEFAULT_FR NULL
#define OPTION_VAL_WONDERSWAN_FR NULL
#define OPTION_VAL_WONDESWAN_COLOR_FR NULL
#define OPTION_VAL_SWANCRYSTAL_FR NULL
#define OPTION_VAL_GB_DMG_FR NULL
#define OPTION_VAL_GB_POCKET_FR NULL
#define OPTION_VAL_GB_LIGHT_FR NULL
#define OPTION_VAL_BLOSSOM_PINK_FR NULL
#define OPTION_VAL_BUBBLES_BLUE_FR NULL
#define OPTION_VAL_BUTTERCUP_GREEN_FR NULL
#define OPTION_VAL_DIGIVICE_FR NULL
#define OPTION_VAL_GAME_COM_FR NULL
#define OPTION_VAL_GAMEKING_FR NULL
#define OPTION_VAL_GAME_MASTER_FR NULL
#define OPTION_VAL_GOLDEN_WILD_FR NULL
#define OPTION_VAL_GREENSCALE_FR NULL
#define OPTION_VAL_HOKAGE_ORANGE_FR NULL
#define OPTION_VAL_LABO_FAWN_FR NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FR NULL
#define OPTION_VAL_MICROVISION_FR NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_FR NULL
#define OPTION_VAL_ODYSSEY_GOLD_FR NULL
#define OPTION_VAL_SHINY_SKY_BLUE_FR NULL
#define OPTION_VAL_SLIME_BLUE_FR NULL
#define OPTION_VAL_TI_83_FR NULL
#define OPTION_VAL_TRAVEL_WOOD_FR NULL
#define OPTION_VAL_VIRTUAL_BOY_FR NULL
#define WSWAN_GFX_COLORS_LABEL_FR NULL
#define WSWAN_GFX_COLORS_INFO_0_FR NULL
#define OPTION_VAL_16BIT_FR NULL
#define OPTION_VAL_24BIT_FR NULL
#define WSWAN_FRAMESKIP_LABEL_FR NULL
#define WSWAN_FRAMESKIP_INFO_0_FR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_FR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FR NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_FR NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_FR NULL

struct retro_core_option_v2_category option_cats_fr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fr[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_FR,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_FR,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_FR },
         { "landscape", OPTION_VAL_LANDSCAPE_FR },
         { "portrait",  OPTION_VAL_PORTRAIT_FR },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_FR,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_FR,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_FR },
         { "disabled", OPTION_VAL_LANDSCAPE_FR },
         { "enabled",  OPTION_VAL_PORTRAIT_FR },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_FR,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_FR,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_FR },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_FR },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_FR },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_FR },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_FR },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_FR },
         { "gb_light",               OPTION_VAL_GB_LIGHT_FR },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_FR },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_FR },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_FR },
         { "digivice",               OPTION_VAL_DIGIVICE_FR },
         { "game_com",               OPTION_VAL_GAME_COM_FR },
         { "gameking",               OPTION_VAL_GAMEKING_FR },
         { "game_master",            OPTION_VAL_GAME_MASTER_FR },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_FR },
         { "greenscale",             OPTION_VAL_GREENSCALE_FR },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_FR },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_FR },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_FR },
         { "microvision",            OPTION_VAL_MICROVISION_FR },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_FR },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_FR },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_FR },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_FR },
         { "ti_83",                  OPTION_VAL_TI_83_FR },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_FR },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_FR },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_FR,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_FR,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_FR },
         { "24bit", OPTION_VAL_24BIT_FR },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_FR,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_FR,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_FR },
         { "manual",   OPTION_VAL_MANUAL_FR },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_FR,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_FR,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_FR,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_FR,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_fr = {
   option_cats_fr,
   option_defs_fr
};

/* RETRO_LANGUAGE_GL */

#define WSWAN_ROTATE_DISPLAY_LABEL_GL NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_GL NULL
#define OPTION_VAL_MANUAL_GL NULL
#define OPTION_VAL_LANDSCAPE_GL NULL
#define OPTION_VAL_PORTRAIT_GL NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_GL NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_GL NULL
#define OPTION_VAL_AUTO_GL NULL
#define WSWAN_MONO_PALETTE_LABEL_GL NULL
#define WSWAN_MONO_PALETTE_INFO_0_GL NULL
#define OPTION_VAL_DEFAULT_GL NULL
#define OPTION_VAL_WONDERSWAN_GL NULL
#define OPTION_VAL_WONDESWAN_COLOR_GL NULL
#define OPTION_VAL_SWANCRYSTAL_GL NULL
#define OPTION_VAL_GB_DMG_GL NULL
#define OPTION_VAL_GB_POCKET_GL NULL
#define OPTION_VAL_GB_LIGHT_GL NULL
#define OPTION_VAL_BLOSSOM_PINK_GL NULL
#define OPTION_VAL_BUBBLES_BLUE_GL NULL
#define OPTION_VAL_BUTTERCUP_GREEN_GL NULL
#define OPTION_VAL_DIGIVICE_GL NULL
#define OPTION_VAL_GAME_COM_GL NULL
#define OPTION_VAL_GAMEKING_GL NULL
#define OPTION_VAL_GAME_MASTER_GL NULL
#define OPTION_VAL_GOLDEN_WILD_GL NULL
#define OPTION_VAL_GREENSCALE_GL NULL
#define OPTION_VAL_HOKAGE_ORANGE_GL NULL
#define OPTION_VAL_LABO_FAWN_GL NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_GL NULL
#define OPTION_VAL_MICROVISION_GL NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_GL NULL
#define OPTION_VAL_ODYSSEY_GOLD_GL NULL
#define OPTION_VAL_SHINY_SKY_BLUE_GL NULL
#define OPTION_VAL_SLIME_BLUE_GL NULL
#define OPTION_VAL_TI_83_GL NULL
#define OPTION_VAL_TRAVEL_WOOD_GL NULL
#define OPTION_VAL_VIRTUAL_BOY_GL NULL
#define WSWAN_GFX_COLORS_LABEL_GL NULL
#define WSWAN_GFX_COLORS_INFO_0_GL NULL
#define OPTION_VAL_16BIT_GL NULL
#define OPTION_VAL_24BIT_GL NULL
#define WSWAN_FRAMESKIP_LABEL_GL NULL
#define WSWAN_FRAMESKIP_INFO_0_GL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_GL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_GL NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_GL NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_GL NULL

struct retro_core_option_v2_category option_cats_gl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_gl[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_GL,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_GL,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_GL },
         { "landscape", OPTION_VAL_LANDSCAPE_GL },
         { "portrait",  OPTION_VAL_PORTRAIT_GL },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_GL,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_GL,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_GL },
         { "disabled", OPTION_VAL_LANDSCAPE_GL },
         { "enabled",  OPTION_VAL_PORTRAIT_GL },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_GL,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_GL,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_GL },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_GL },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_GL },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_GL },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_GL },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_GL },
         { "gb_light",               OPTION_VAL_GB_LIGHT_GL },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_GL },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_GL },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_GL },
         { "digivice",               OPTION_VAL_DIGIVICE_GL },
         { "game_com",               OPTION_VAL_GAME_COM_GL },
         { "gameking",               OPTION_VAL_GAMEKING_GL },
         { "game_master",            OPTION_VAL_GAME_MASTER_GL },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_GL },
         { "greenscale",             OPTION_VAL_GREENSCALE_GL },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_GL },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_GL },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_GL },
         { "microvision",            OPTION_VAL_MICROVISION_GL },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_GL },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_GL },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_GL },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_GL },
         { "ti_83",                  OPTION_VAL_TI_83_GL },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_GL },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_GL },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_GL,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_GL,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_GL },
         { "24bit", OPTION_VAL_24BIT_GL },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_GL,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_GL,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_GL },
         { "manual",   OPTION_VAL_MANUAL_GL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_GL,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_GL,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_GL,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_GL,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_gl = {
   option_cats_gl,
   option_defs_gl
};

/* RETRO_LANGUAGE_HE */

#define WSWAN_ROTATE_DISPLAY_LABEL_HE NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_HE NULL
#define OPTION_VAL_MANUAL_HE NULL
#define OPTION_VAL_LANDSCAPE_HE NULL
#define OPTION_VAL_PORTRAIT_HE NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_HE NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_HE NULL
#define OPTION_VAL_AUTO_HE NULL
#define WSWAN_MONO_PALETTE_LABEL_HE NULL
#define WSWAN_MONO_PALETTE_INFO_0_HE NULL
#define OPTION_VAL_DEFAULT_HE NULL
#define OPTION_VAL_WONDERSWAN_HE NULL
#define OPTION_VAL_WONDESWAN_COLOR_HE NULL
#define OPTION_VAL_SWANCRYSTAL_HE NULL
#define OPTION_VAL_GB_DMG_HE NULL
#define OPTION_VAL_GB_POCKET_HE NULL
#define OPTION_VAL_GB_LIGHT_HE NULL
#define OPTION_VAL_BLOSSOM_PINK_HE NULL
#define OPTION_VAL_BUBBLES_BLUE_HE NULL
#define OPTION_VAL_BUTTERCUP_GREEN_HE NULL
#define OPTION_VAL_DIGIVICE_HE NULL
#define OPTION_VAL_GAME_COM_HE NULL
#define OPTION_VAL_GAMEKING_HE NULL
#define OPTION_VAL_GAME_MASTER_HE NULL
#define OPTION_VAL_GOLDEN_WILD_HE NULL
#define OPTION_VAL_GREENSCALE_HE NULL
#define OPTION_VAL_HOKAGE_ORANGE_HE NULL
#define OPTION_VAL_LABO_FAWN_HE NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_HE NULL
#define OPTION_VAL_MICROVISION_HE NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_HE NULL
#define OPTION_VAL_ODYSSEY_GOLD_HE NULL
#define OPTION_VAL_SHINY_SKY_BLUE_HE NULL
#define OPTION_VAL_SLIME_BLUE_HE NULL
#define OPTION_VAL_TI_83_HE NULL
#define OPTION_VAL_TRAVEL_WOOD_HE NULL
#define OPTION_VAL_VIRTUAL_BOY_HE NULL
#define WSWAN_GFX_COLORS_LABEL_HE NULL
#define WSWAN_GFX_COLORS_INFO_0_HE NULL
#define OPTION_VAL_16BIT_HE NULL
#define OPTION_VAL_24BIT_HE NULL
#define WSWAN_FRAMESKIP_LABEL_HE NULL
#define WSWAN_FRAMESKIP_INFO_0_HE NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_HE NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_HE NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_HE NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_HE NULL

struct retro_core_option_v2_category option_cats_he[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_he[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_HE,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_HE,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_HE },
         { "landscape", OPTION_VAL_LANDSCAPE_HE },
         { "portrait",  OPTION_VAL_PORTRAIT_HE },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_HE,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_HE,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_HE },
         { "disabled", OPTION_VAL_LANDSCAPE_HE },
         { "enabled",  OPTION_VAL_PORTRAIT_HE },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_HE,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_HE,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_HE },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_HE },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_HE },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_HE },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_HE },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_HE },
         { "gb_light",               OPTION_VAL_GB_LIGHT_HE },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_HE },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_HE },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_HE },
         { "digivice",               OPTION_VAL_DIGIVICE_HE },
         { "game_com",               OPTION_VAL_GAME_COM_HE },
         { "gameking",               OPTION_VAL_GAMEKING_HE },
         { "game_master",            OPTION_VAL_GAME_MASTER_HE },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_HE },
         { "greenscale",             OPTION_VAL_GREENSCALE_HE },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_HE },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_HE },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_HE },
         { "microvision",            OPTION_VAL_MICROVISION_HE },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_HE },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_HE },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_HE },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_HE },
         { "ti_83",                  OPTION_VAL_TI_83_HE },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_HE },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_HE },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_HE,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_HE,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_HE },
         { "24bit", OPTION_VAL_24BIT_HE },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_HE,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_HE,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_HE },
         { "manual",   OPTION_VAL_MANUAL_HE },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_HE,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_HE,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_HE,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_HE,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_he = {
   option_cats_he,
   option_defs_he
};

/* RETRO_LANGUAGE_HU */

#define WSWAN_ROTATE_DISPLAY_LABEL_HU NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_HU NULL
#define OPTION_VAL_MANUAL_HU NULL
#define OPTION_VAL_LANDSCAPE_HU NULL
#define OPTION_VAL_PORTRAIT_HU NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_HU NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_HU NULL
#define OPTION_VAL_AUTO_HU NULL
#define WSWAN_MONO_PALETTE_LABEL_HU NULL
#define WSWAN_MONO_PALETTE_INFO_0_HU NULL
#define OPTION_VAL_DEFAULT_HU NULL
#define OPTION_VAL_WONDERSWAN_HU NULL
#define OPTION_VAL_WONDESWAN_COLOR_HU NULL
#define OPTION_VAL_SWANCRYSTAL_HU NULL
#define OPTION_VAL_GB_DMG_HU NULL
#define OPTION_VAL_GB_POCKET_HU NULL
#define OPTION_VAL_GB_LIGHT_HU NULL
#define OPTION_VAL_BLOSSOM_PINK_HU NULL
#define OPTION_VAL_BUBBLES_BLUE_HU NULL
#define OPTION_VAL_BUTTERCUP_GREEN_HU NULL
#define OPTION_VAL_DIGIVICE_HU NULL
#define OPTION_VAL_GAME_COM_HU NULL
#define OPTION_VAL_GAMEKING_HU NULL
#define OPTION_VAL_GAME_MASTER_HU NULL
#define OPTION_VAL_GOLDEN_WILD_HU NULL
#define OPTION_VAL_GREENSCALE_HU NULL
#define OPTION_VAL_HOKAGE_ORANGE_HU NULL
#define OPTION_VAL_LABO_FAWN_HU NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_HU NULL
#define OPTION_VAL_MICROVISION_HU NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_HU NULL
#define OPTION_VAL_ODYSSEY_GOLD_HU NULL
#define OPTION_VAL_SHINY_SKY_BLUE_HU NULL
#define OPTION_VAL_SLIME_BLUE_HU NULL
#define OPTION_VAL_TI_83_HU NULL
#define OPTION_VAL_TRAVEL_WOOD_HU NULL
#define OPTION_VAL_VIRTUAL_BOY_HU NULL
#define WSWAN_GFX_COLORS_LABEL_HU NULL
#define WSWAN_GFX_COLORS_INFO_0_HU NULL
#define OPTION_VAL_16BIT_HU NULL
#define OPTION_VAL_24BIT_HU NULL
#define WSWAN_FRAMESKIP_LABEL_HU NULL
#define WSWAN_FRAMESKIP_INFO_0_HU NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_HU NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_HU NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_HU NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_HU NULL

struct retro_core_option_v2_category option_cats_hu[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hu[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_HU,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_HU,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_HU },
         { "landscape", OPTION_VAL_LANDSCAPE_HU },
         { "portrait",  OPTION_VAL_PORTRAIT_HU },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_HU,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_HU,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_HU },
         { "disabled", OPTION_VAL_LANDSCAPE_HU },
         { "enabled",  OPTION_VAL_PORTRAIT_HU },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_HU,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_HU,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_HU },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_HU },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_HU },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_HU },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_HU },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_HU },
         { "gb_light",               OPTION_VAL_GB_LIGHT_HU },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_HU },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_HU },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_HU },
         { "digivice",               OPTION_VAL_DIGIVICE_HU },
         { "game_com",               OPTION_VAL_GAME_COM_HU },
         { "gameking",               OPTION_VAL_GAMEKING_HU },
         { "game_master",            OPTION_VAL_GAME_MASTER_HU },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_HU },
         { "greenscale",             OPTION_VAL_GREENSCALE_HU },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_HU },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_HU },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_HU },
         { "microvision",            OPTION_VAL_MICROVISION_HU },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_HU },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_HU },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_HU },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_HU },
         { "ti_83",                  OPTION_VAL_TI_83_HU },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_HU },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_HU },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_HU,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_HU,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_HU },
         { "24bit", OPTION_VAL_24BIT_HU },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_HU,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_HU,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_HU },
         { "manual",   OPTION_VAL_MANUAL_HU },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_HU,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_HU,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_HU,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_HU,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_hu = {
   option_cats_hu,
   option_defs_hu
};

/* RETRO_LANGUAGE_ID */

#define WSWAN_ROTATE_DISPLAY_LABEL_ID NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_ID NULL
#define OPTION_VAL_MANUAL_ID NULL
#define OPTION_VAL_LANDSCAPE_ID NULL
#define OPTION_VAL_PORTRAIT_ID NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_ID NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_ID NULL
#define OPTION_VAL_AUTO_ID NULL
#define WSWAN_MONO_PALETTE_LABEL_ID NULL
#define WSWAN_MONO_PALETTE_INFO_0_ID NULL
#define OPTION_VAL_DEFAULT_ID NULL
#define OPTION_VAL_WONDERSWAN_ID NULL
#define OPTION_VAL_WONDESWAN_COLOR_ID NULL
#define OPTION_VAL_SWANCRYSTAL_ID NULL
#define OPTION_VAL_GB_DMG_ID NULL
#define OPTION_VAL_GB_POCKET_ID NULL
#define OPTION_VAL_GB_LIGHT_ID NULL
#define OPTION_VAL_BLOSSOM_PINK_ID NULL
#define OPTION_VAL_BUBBLES_BLUE_ID NULL
#define OPTION_VAL_BUTTERCUP_GREEN_ID NULL
#define OPTION_VAL_DIGIVICE_ID NULL
#define OPTION_VAL_GAME_COM_ID NULL
#define OPTION_VAL_GAMEKING_ID NULL
#define OPTION_VAL_GAME_MASTER_ID NULL
#define OPTION_VAL_GOLDEN_WILD_ID NULL
#define OPTION_VAL_GREENSCALE_ID NULL
#define OPTION_VAL_HOKAGE_ORANGE_ID NULL
#define OPTION_VAL_LABO_FAWN_ID NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_ID NULL
#define OPTION_VAL_MICROVISION_ID NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_ID NULL
#define OPTION_VAL_ODYSSEY_GOLD_ID NULL
#define OPTION_VAL_SHINY_SKY_BLUE_ID NULL
#define OPTION_VAL_SLIME_BLUE_ID NULL
#define OPTION_VAL_TI_83_ID NULL
#define OPTION_VAL_TRAVEL_WOOD_ID NULL
#define OPTION_VAL_VIRTUAL_BOY_ID NULL
#define WSWAN_GFX_COLORS_LABEL_ID NULL
#define WSWAN_GFX_COLORS_INFO_0_ID NULL
#define OPTION_VAL_16BIT_ID NULL
#define OPTION_VAL_24BIT_ID NULL
#define WSWAN_FRAMESKIP_LABEL_ID NULL
#define WSWAN_FRAMESKIP_INFO_0_ID NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_ID NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_ID NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_ID NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_ID NULL

struct retro_core_option_v2_category option_cats_id[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_id[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_ID,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_ID,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_ID },
         { "landscape", OPTION_VAL_LANDSCAPE_ID },
         { "portrait",  OPTION_VAL_PORTRAIT_ID },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_ID,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_ID,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_ID },
         { "disabled", OPTION_VAL_LANDSCAPE_ID },
         { "enabled",  OPTION_VAL_PORTRAIT_ID },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_ID,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_ID,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_ID },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_ID },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_ID },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_ID },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_ID },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_ID },
         { "gb_light",               OPTION_VAL_GB_LIGHT_ID },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_ID },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_ID },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_ID },
         { "digivice",               OPTION_VAL_DIGIVICE_ID },
         { "game_com",               OPTION_VAL_GAME_COM_ID },
         { "gameking",               OPTION_VAL_GAMEKING_ID },
         { "game_master",            OPTION_VAL_GAME_MASTER_ID },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_ID },
         { "greenscale",             OPTION_VAL_GREENSCALE_ID },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_ID },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_ID },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_ID },
         { "microvision",            OPTION_VAL_MICROVISION_ID },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_ID },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_ID },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_ID },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_ID },
         { "ti_83",                  OPTION_VAL_TI_83_ID },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_ID },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_ID },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_ID,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_ID,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_ID },
         { "24bit", OPTION_VAL_24BIT_ID },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_ID,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_ID,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_ID },
         { "manual",   OPTION_VAL_MANUAL_ID },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_ID,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_ID,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_ID,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_ID,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_id = {
   option_cats_id,
   option_defs_id
};

/* RETRO_LANGUAGE_IT */

#define WSWAN_ROTATE_DISPLAY_LABEL_IT NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_IT NULL
#define OPTION_VAL_MANUAL_IT NULL
#define OPTION_VAL_LANDSCAPE_IT NULL
#define OPTION_VAL_PORTRAIT_IT NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_IT NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_IT NULL
#define OPTION_VAL_AUTO_IT NULL
#define WSWAN_MONO_PALETTE_LABEL_IT NULL
#define WSWAN_MONO_PALETTE_INFO_0_IT NULL
#define OPTION_VAL_DEFAULT_IT NULL
#define OPTION_VAL_WONDERSWAN_IT NULL
#define OPTION_VAL_WONDESWAN_COLOR_IT NULL
#define OPTION_VAL_SWANCRYSTAL_IT NULL
#define OPTION_VAL_GB_DMG_IT NULL
#define OPTION_VAL_GB_POCKET_IT NULL
#define OPTION_VAL_GB_LIGHT_IT NULL
#define OPTION_VAL_BLOSSOM_PINK_IT NULL
#define OPTION_VAL_BUBBLES_BLUE_IT NULL
#define OPTION_VAL_BUTTERCUP_GREEN_IT NULL
#define OPTION_VAL_DIGIVICE_IT NULL
#define OPTION_VAL_GAME_COM_IT NULL
#define OPTION_VAL_GAMEKING_IT NULL
#define OPTION_VAL_GAME_MASTER_IT NULL
#define OPTION_VAL_GOLDEN_WILD_IT NULL
#define OPTION_VAL_GREENSCALE_IT NULL
#define OPTION_VAL_HOKAGE_ORANGE_IT NULL
#define OPTION_VAL_LABO_FAWN_IT NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_IT NULL
#define OPTION_VAL_MICROVISION_IT NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_IT NULL
#define OPTION_VAL_ODYSSEY_GOLD_IT NULL
#define OPTION_VAL_SHINY_SKY_BLUE_IT NULL
#define OPTION_VAL_SLIME_BLUE_IT NULL
#define OPTION_VAL_TI_83_IT NULL
#define OPTION_VAL_TRAVEL_WOOD_IT NULL
#define OPTION_VAL_VIRTUAL_BOY_IT NULL
#define WSWAN_GFX_COLORS_LABEL_IT NULL
#define WSWAN_GFX_COLORS_INFO_0_IT NULL
#define OPTION_VAL_16BIT_IT NULL
#define OPTION_VAL_24BIT_IT NULL
#define WSWAN_FRAMESKIP_LABEL_IT NULL
#define WSWAN_FRAMESKIP_INFO_0_IT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_IT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_IT NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_IT NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_IT NULL

struct retro_core_option_v2_category option_cats_it[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_it[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_IT,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_IT,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_IT },
         { "landscape", OPTION_VAL_LANDSCAPE_IT },
         { "portrait",  OPTION_VAL_PORTRAIT_IT },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_IT,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_IT,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_IT },
         { "disabled", OPTION_VAL_LANDSCAPE_IT },
         { "enabled",  OPTION_VAL_PORTRAIT_IT },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_IT,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_IT,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_IT },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_IT },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_IT },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_IT },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_IT },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_IT },
         { "gb_light",               OPTION_VAL_GB_LIGHT_IT },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_IT },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_IT },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_IT },
         { "digivice",               OPTION_VAL_DIGIVICE_IT },
         { "game_com",               OPTION_VAL_GAME_COM_IT },
         { "gameking",               OPTION_VAL_GAMEKING_IT },
         { "game_master",            OPTION_VAL_GAME_MASTER_IT },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_IT },
         { "greenscale",             OPTION_VAL_GREENSCALE_IT },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_IT },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_IT },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_IT },
         { "microvision",            OPTION_VAL_MICROVISION_IT },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_IT },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_IT },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_IT },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_IT },
         { "ti_83",                  OPTION_VAL_TI_83_IT },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_IT },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_IT },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_IT,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_IT,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_IT },
         { "24bit", OPTION_VAL_24BIT_IT },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_IT,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_IT,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_IT },
         { "manual",   OPTION_VAL_MANUAL_IT },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_IT,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_IT,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_IT,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_IT,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_it = {
   option_cats_it,
   option_defs_it
};

/* RETRO_LANGUAGE_JA */

#define WSWAN_ROTATE_DISPLAY_LABEL_JA NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_JA NULL
#define OPTION_VAL_MANUAL_JA NULL
#define OPTION_VAL_LANDSCAPE_JA NULL
#define OPTION_VAL_PORTRAIT_JA NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_JA NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_JA NULL
#define OPTION_VAL_AUTO_JA NULL
#define WSWAN_MONO_PALETTE_LABEL_JA NULL
#define WSWAN_MONO_PALETTE_INFO_0_JA NULL
#define OPTION_VAL_DEFAULT_JA NULL
#define OPTION_VAL_WONDERSWAN_JA NULL
#define OPTION_VAL_WONDESWAN_COLOR_JA NULL
#define OPTION_VAL_SWANCRYSTAL_JA NULL
#define OPTION_VAL_GB_DMG_JA NULL
#define OPTION_VAL_GB_POCKET_JA NULL
#define OPTION_VAL_GB_LIGHT_JA NULL
#define OPTION_VAL_BLOSSOM_PINK_JA NULL
#define OPTION_VAL_BUBBLES_BLUE_JA NULL
#define OPTION_VAL_BUTTERCUP_GREEN_JA NULL
#define OPTION_VAL_DIGIVICE_JA NULL
#define OPTION_VAL_GAME_COM_JA NULL
#define OPTION_VAL_GAMEKING_JA NULL
#define OPTION_VAL_GAME_MASTER_JA NULL
#define OPTION_VAL_GOLDEN_WILD_JA NULL
#define OPTION_VAL_GREENSCALE_JA NULL
#define OPTION_VAL_HOKAGE_ORANGE_JA NULL
#define OPTION_VAL_LABO_FAWN_JA NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_JA NULL
#define OPTION_VAL_MICROVISION_JA NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_JA NULL
#define OPTION_VAL_ODYSSEY_GOLD_JA NULL
#define OPTION_VAL_SHINY_SKY_BLUE_JA NULL
#define OPTION_VAL_SLIME_BLUE_JA NULL
#define OPTION_VAL_TI_83_JA NULL
#define OPTION_VAL_TRAVEL_WOOD_JA NULL
#define OPTION_VAL_VIRTUAL_BOY_JA NULL
#define WSWAN_GFX_COLORS_LABEL_JA NULL
#define WSWAN_GFX_COLORS_INFO_0_JA NULL
#define OPTION_VAL_16BIT_JA NULL
#define OPTION_VAL_24BIT_JA NULL
#define WSWAN_FRAMESKIP_LABEL_JA NULL
#define WSWAN_FRAMESKIP_INFO_0_JA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_JA NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_JA NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_JA NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_JA NULL

struct retro_core_option_v2_category option_cats_ja[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ja[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_JA,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_JA,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_JA },
         { "landscape", OPTION_VAL_LANDSCAPE_JA },
         { "portrait",  OPTION_VAL_PORTRAIT_JA },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_JA,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_JA,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_JA },
         { "disabled", OPTION_VAL_LANDSCAPE_JA },
         { "enabled",  OPTION_VAL_PORTRAIT_JA },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_JA,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_JA,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_JA },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_JA },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_JA },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_JA },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_JA },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_JA },
         { "gb_light",               OPTION_VAL_GB_LIGHT_JA },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_JA },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_JA },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_JA },
         { "digivice",               OPTION_VAL_DIGIVICE_JA },
         { "game_com",               OPTION_VAL_GAME_COM_JA },
         { "gameking",               OPTION_VAL_GAMEKING_JA },
         { "game_master",            OPTION_VAL_GAME_MASTER_JA },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_JA },
         { "greenscale",             OPTION_VAL_GREENSCALE_JA },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_JA },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_JA },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_JA },
         { "microvision",            OPTION_VAL_MICROVISION_JA },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_JA },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_JA },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_JA },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_JA },
         { "ti_83",                  OPTION_VAL_TI_83_JA },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_JA },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_JA },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_JA,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_JA,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_JA },
         { "24bit", OPTION_VAL_24BIT_JA },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_JA,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_JA,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_JA },
         { "manual",   OPTION_VAL_MANUAL_JA },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_JA,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_JA,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_JA,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_JA,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ja = {
   option_cats_ja,
   option_defs_ja
};

/* RETRO_LANGUAGE_KO */

#define WSWAN_ROTATE_DISPLAY_LABEL_KO NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_KO NULL
#define OPTION_VAL_MANUAL_KO NULL
#define OPTION_VAL_LANDSCAPE_KO NULL
#define OPTION_VAL_PORTRAIT_KO NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_KO NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_KO NULL
#define OPTION_VAL_AUTO_KO NULL
#define WSWAN_MONO_PALETTE_LABEL_KO NULL
#define WSWAN_MONO_PALETTE_INFO_0_KO NULL
#define OPTION_VAL_DEFAULT_KO NULL
#define OPTION_VAL_WONDERSWAN_KO NULL
#define OPTION_VAL_WONDESWAN_COLOR_KO NULL
#define OPTION_VAL_SWANCRYSTAL_KO NULL
#define OPTION_VAL_GB_DMG_KO NULL
#define OPTION_VAL_GB_POCKET_KO NULL
#define OPTION_VAL_GB_LIGHT_KO NULL
#define OPTION_VAL_BLOSSOM_PINK_KO NULL
#define OPTION_VAL_BUBBLES_BLUE_KO NULL
#define OPTION_VAL_BUTTERCUP_GREEN_KO NULL
#define OPTION_VAL_DIGIVICE_KO NULL
#define OPTION_VAL_GAME_COM_KO NULL
#define OPTION_VAL_GAMEKING_KO NULL
#define OPTION_VAL_GAME_MASTER_KO NULL
#define OPTION_VAL_GOLDEN_WILD_KO NULL
#define OPTION_VAL_GREENSCALE_KO NULL
#define OPTION_VAL_HOKAGE_ORANGE_KO NULL
#define OPTION_VAL_LABO_FAWN_KO NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_KO NULL
#define OPTION_VAL_MICROVISION_KO NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_KO NULL
#define OPTION_VAL_ODYSSEY_GOLD_KO NULL
#define OPTION_VAL_SHINY_SKY_BLUE_KO NULL
#define OPTION_VAL_SLIME_BLUE_KO NULL
#define OPTION_VAL_TI_83_KO NULL
#define OPTION_VAL_TRAVEL_WOOD_KO NULL
#define OPTION_VAL_VIRTUAL_BOY_KO NULL
#define WSWAN_GFX_COLORS_LABEL_KO NULL
#define WSWAN_GFX_COLORS_INFO_0_KO NULL
#define OPTION_VAL_16BIT_KO NULL
#define OPTION_VAL_24BIT_KO NULL
#define WSWAN_FRAMESKIP_LABEL_KO NULL
#define WSWAN_FRAMESKIP_INFO_0_KO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_KO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_KO NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_KO NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_KO NULL

struct retro_core_option_v2_category option_cats_ko[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ko[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_KO,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_KO,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_KO },
         { "landscape", OPTION_VAL_LANDSCAPE_KO },
         { "portrait",  OPTION_VAL_PORTRAIT_KO },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_KO,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_KO,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_KO },
         { "disabled", OPTION_VAL_LANDSCAPE_KO },
         { "enabled",  OPTION_VAL_PORTRAIT_KO },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_KO,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_KO,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_KO },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_KO },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_KO },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_KO },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_KO },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_KO },
         { "gb_light",               OPTION_VAL_GB_LIGHT_KO },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_KO },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_KO },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_KO },
         { "digivice",               OPTION_VAL_DIGIVICE_KO },
         { "game_com",               OPTION_VAL_GAME_COM_KO },
         { "gameking",               OPTION_VAL_GAMEKING_KO },
         { "game_master",            OPTION_VAL_GAME_MASTER_KO },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_KO },
         { "greenscale",             OPTION_VAL_GREENSCALE_KO },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_KO },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_KO },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_KO },
         { "microvision",            OPTION_VAL_MICROVISION_KO },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_KO },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_KO },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_KO },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_KO },
         { "ti_83",                  OPTION_VAL_TI_83_KO },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_KO },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_KO },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_KO,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_KO,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_KO },
         { "24bit", OPTION_VAL_24BIT_KO },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_KO,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_KO,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_KO },
         { "manual",   OPTION_VAL_MANUAL_KO },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_KO,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_KO,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_KO,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_KO,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ko = {
   option_cats_ko,
   option_defs_ko
};

/* RETRO_LANGUAGE_MT */

#define WSWAN_ROTATE_DISPLAY_LABEL_MT NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_MT NULL
#define OPTION_VAL_MANUAL_MT NULL
#define OPTION_VAL_LANDSCAPE_MT NULL
#define OPTION_VAL_PORTRAIT_MT NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_MT NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_MT NULL
#define OPTION_VAL_AUTO_MT NULL
#define WSWAN_MONO_PALETTE_LABEL_MT NULL
#define WSWAN_MONO_PALETTE_INFO_0_MT NULL
#define OPTION_VAL_DEFAULT_MT NULL
#define OPTION_VAL_WONDERSWAN_MT NULL
#define OPTION_VAL_WONDESWAN_COLOR_MT NULL
#define OPTION_VAL_SWANCRYSTAL_MT NULL
#define OPTION_VAL_GB_DMG_MT NULL
#define OPTION_VAL_GB_POCKET_MT NULL
#define OPTION_VAL_GB_LIGHT_MT NULL
#define OPTION_VAL_BLOSSOM_PINK_MT NULL
#define OPTION_VAL_BUBBLES_BLUE_MT NULL
#define OPTION_VAL_BUTTERCUP_GREEN_MT NULL
#define OPTION_VAL_DIGIVICE_MT NULL
#define OPTION_VAL_GAME_COM_MT NULL
#define OPTION_VAL_GAMEKING_MT NULL
#define OPTION_VAL_GAME_MASTER_MT NULL
#define OPTION_VAL_GOLDEN_WILD_MT NULL
#define OPTION_VAL_GREENSCALE_MT NULL
#define OPTION_VAL_HOKAGE_ORANGE_MT NULL
#define OPTION_VAL_LABO_FAWN_MT NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_MT NULL
#define OPTION_VAL_MICROVISION_MT NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_MT NULL
#define OPTION_VAL_ODYSSEY_GOLD_MT NULL
#define OPTION_VAL_SHINY_SKY_BLUE_MT NULL
#define OPTION_VAL_SLIME_BLUE_MT NULL
#define OPTION_VAL_TI_83_MT NULL
#define OPTION_VAL_TRAVEL_WOOD_MT NULL
#define OPTION_VAL_VIRTUAL_BOY_MT NULL
#define WSWAN_GFX_COLORS_LABEL_MT NULL
#define WSWAN_GFX_COLORS_INFO_0_MT NULL
#define OPTION_VAL_16BIT_MT NULL
#define OPTION_VAL_24BIT_MT NULL
#define WSWAN_FRAMESKIP_LABEL_MT NULL
#define WSWAN_FRAMESKIP_INFO_0_MT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_MT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_MT NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_MT NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_MT NULL

struct retro_core_option_v2_category option_cats_mt[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_mt[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_MT,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_MT,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_MT },
         { "landscape", OPTION_VAL_LANDSCAPE_MT },
         { "portrait",  OPTION_VAL_PORTRAIT_MT },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_MT,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_MT,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_MT },
         { "disabled", OPTION_VAL_LANDSCAPE_MT },
         { "enabled",  OPTION_VAL_PORTRAIT_MT },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_MT,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_MT,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_MT },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_MT },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_MT },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_MT },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_MT },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_MT },
         { "gb_light",               OPTION_VAL_GB_LIGHT_MT },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_MT },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_MT },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_MT },
         { "digivice",               OPTION_VAL_DIGIVICE_MT },
         { "game_com",               OPTION_VAL_GAME_COM_MT },
         { "gameking",               OPTION_VAL_GAMEKING_MT },
         { "game_master",            OPTION_VAL_GAME_MASTER_MT },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_MT },
         { "greenscale",             OPTION_VAL_GREENSCALE_MT },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_MT },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_MT },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_MT },
         { "microvision",            OPTION_VAL_MICROVISION_MT },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_MT },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_MT },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_MT },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_MT },
         { "ti_83",                  OPTION_VAL_TI_83_MT },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_MT },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_MT },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_MT,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_MT,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_MT },
         { "24bit", OPTION_VAL_24BIT_MT },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_MT,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_MT,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_MT },
         { "manual",   OPTION_VAL_MANUAL_MT },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_MT,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_MT,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_MT,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_MT,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_mt = {
   option_cats_mt,
   option_defs_mt
};

/* RETRO_LANGUAGE_NL */

#define WSWAN_ROTATE_DISPLAY_LABEL_NL NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_NL NULL
#define OPTION_VAL_MANUAL_NL NULL
#define OPTION_VAL_LANDSCAPE_NL NULL
#define OPTION_VAL_PORTRAIT_NL NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_NL NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_NL NULL
#define OPTION_VAL_AUTO_NL NULL
#define WSWAN_MONO_PALETTE_LABEL_NL NULL
#define WSWAN_MONO_PALETTE_INFO_0_NL NULL
#define OPTION_VAL_DEFAULT_NL NULL
#define OPTION_VAL_WONDERSWAN_NL NULL
#define OPTION_VAL_WONDESWAN_COLOR_NL NULL
#define OPTION_VAL_SWANCRYSTAL_NL NULL
#define OPTION_VAL_GB_DMG_NL NULL
#define OPTION_VAL_GB_POCKET_NL NULL
#define OPTION_VAL_GB_LIGHT_NL NULL
#define OPTION_VAL_BLOSSOM_PINK_NL NULL
#define OPTION_VAL_BUBBLES_BLUE_NL NULL
#define OPTION_VAL_BUTTERCUP_GREEN_NL NULL
#define OPTION_VAL_DIGIVICE_NL NULL
#define OPTION_VAL_GAME_COM_NL NULL
#define OPTION_VAL_GAMEKING_NL NULL
#define OPTION_VAL_GAME_MASTER_NL NULL
#define OPTION_VAL_GOLDEN_WILD_NL NULL
#define OPTION_VAL_GREENSCALE_NL NULL
#define OPTION_VAL_HOKAGE_ORANGE_NL NULL
#define OPTION_VAL_LABO_FAWN_NL NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_NL NULL
#define OPTION_VAL_MICROVISION_NL NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_NL NULL
#define OPTION_VAL_ODYSSEY_GOLD_NL NULL
#define OPTION_VAL_SHINY_SKY_BLUE_NL NULL
#define OPTION_VAL_SLIME_BLUE_NL NULL
#define OPTION_VAL_TI_83_NL NULL
#define OPTION_VAL_TRAVEL_WOOD_NL NULL
#define OPTION_VAL_VIRTUAL_BOY_NL NULL
#define WSWAN_GFX_COLORS_LABEL_NL NULL
#define WSWAN_GFX_COLORS_INFO_0_NL NULL
#define OPTION_VAL_16BIT_NL NULL
#define OPTION_VAL_24BIT_NL NULL
#define WSWAN_FRAMESKIP_LABEL_NL NULL
#define WSWAN_FRAMESKIP_INFO_0_NL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_NL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_NL NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_NL NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_NL NULL

struct retro_core_option_v2_category option_cats_nl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_nl[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_NL,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_NL,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_NL },
         { "landscape", OPTION_VAL_LANDSCAPE_NL },
         { "portrait",  OPTION_VAL_PORTRAIT_NL },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_NL,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_NL,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_NL },
         { "disabled", OPTION_VAL_LANDSCAPE_NL },
         { "enabled",  OPTION_VAL_PORTRAIT_NL },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_NL,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_NL,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_NL },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_NL },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_NL },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_NL },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_NL },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_NL },
         { "gb_light",               OPTION_VAL_GB_LIGHT_NL },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_NL },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_NL },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_NL },
         { "digivice",               OPTION_VAL_DIGIVICE_NL },
         { "game_com",               OPTION_VAL_GAME_COM_NL },
         { "gameking",               OPTION_VAL_GAMEKING_NL },
         { "game_master",            OPTION_VAL_GAME_MASTER_NL },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_NL },
         { "greenscale",             OPTION_VAL_GREENSCALE_NL },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_NL },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_NL },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_NL },
         { "microvision",            OPTION_VAL_MICROVISION_NL },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_NL },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_NL },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_NL },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_NL },
         { "ti_83",                  OPTION_VAL_TI_83_NL },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_NL },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_NL },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_NL,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_NL,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_NL },
         { "24bit", OPTION_VAL_24BIT_NL },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_NL,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_NL,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_NL },
         { "manual",   OPTION_VAL_MANUAL_NL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_NL,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_NL,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_NL,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_NL,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_nl = {
   option_cats_nl,
   option_defs_nl
};

/* RETRO_LANGUAGE_OC */

#define WSWAN_ROTATE_DISPLAY_LABEL_OC NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_OC NULL
#define OPTION_VAL_MANUAL_OC NULL
#define OPTION_VAL_LANDSCAPE_OC NULL
#define OPTION_VAL_PORTRAIT_OC NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_OC NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_OC NULL
#define OPTION_VAL_AUTO_OC NULL
#define WSWAN_MONO_PALETTE_LABEL_OC NULL
#define WSWAN_MONO_PALETTE_INFO_0_OC NULL
#define OPTION_VAL_DEFAULT_OC NULL
#define OPTION_VAL_WONDERSWAN_OC NULL
#define OPTION_VAL_WONDESWAN_COLOR_OC NULL
#define OPTION_VAL_SWANCRYSTAL_OC NULL
#define OPTION_VAL_GB_DMG_OC NULL
#define OPTION_VAL_GB_POCKET_OC NULL
#define OPTION_VAL_GB_LIGHT_OC NULL
#define OPTION_VAL_BLOSSOM_PINK_OC NULL
#define OPTION_VAL_BUBBLES_BLUE_OC NULL
#define OPTION_VAL_BUTTERCUP_GREEN_OC NULL
#define OPTION_VAL_DIGIVICE_OC NULL
#define OPTION_VAL_GAME_COM_OC NULL
#define OPTION_VAL_GAMEKING_OC NULL
#define OPTION_VAL_GAME_MASTER_OC NULL
#define OPTION_VAL_GOLDEN_WILD_OC NULL
#define OPTION_VAL_GREENSCALE_OC NULL
#define OPTION_VAL_HOKAGE_ORANGE_OC NULL
#define OPTION_VAL_LABO_FAWN_OC NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_OC NULL
#define OPTION_VAL_MICROVISION_OC NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_OC NULL
#define OPTION_VAL_ODYSSEY_GOLD_OC NULL
#define OPTION_VAL_SHINY_SKY_BLUE_OC NULL
#define OPTION_VAL_SLIME_BLUE_OC NULL
#define OPTION_VAL_TI_83_OC NULL
#define OPTION_VAL_TRAVEL_WOOD_OC NULL
#define OPTION_VAL_VIRTUAL_BOY_OC NULL
#define WSWAN_GFX_COLORS_LABEL_OC NULL
#define WSWAN_GFX_COLORS_INFO_0_OC NULL
#define OPTION_VAL_16BIT_OC NULL
#define OPTION_VAL_24BIT_OC NULL
#define WSWAN_FRAMESKIP_LABEL_OC NULL
#define WSWAN_FRAMESKIP_INFO_0_OC NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_OC NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_OC NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_OC NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_OC NULL

struct retro_core_option_v2_category option_cats_oc[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_oc[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_OC,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_OC,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_OC },
         { "landscape", OPTION_VAL_LANDSCAPE_OC },
         { "portrait",  OPTION_VAL_PORTRAIT_OC },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_OC,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_OC,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_OC },
         { "disabled", OPTION_VAL_LANDSCAPE_OC },
         { "enabled",  OPTION_VAL_PORTRAIT_OC },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_OC,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_OC,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_OC },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_OC },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_OC },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_OC },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_OC },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_OC },
         { "gb_light",               OPTION_VAL_GB_LIGHT_OC },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_OC },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_OC },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_OC },
         { "digivice",               OPTION_VAL_DIGIVICE_OC },
         { "game_com",               OPTION_VAL_GAME_COM_OC },
         { "gameking",               OPTION_VAL_GAMEKING_OC },
         { "game_master",            OPTION_VAL_GAME_MASTER_OC },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_OC },
         { "greenscale",             OPTION_VAL_GREENSCALE_OC },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_OC },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_OC },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_OC },
         { "microvision",            OPTION_VAL_MICROVISION_OC },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_OC },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_OC },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_OC },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_OC },
         { "ti_83",                  OPTION_VAL_TI_83_OC },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_OC },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_OC },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_OC,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_OC,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_OC },
         { "24bit", OPTION_VAL_24BIT_OC },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_OC,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_OC,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_OC },
         { "manual",   OPTION_VAL_MANUAL_OC },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_OC,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_OC,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_OC,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_OC,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_oc = {
   option_cats_oc,
   option_defs_oc
};

/* RETRO_LANGUAGE_PL */

#define WSWAN_ROTATE_DISPLAY_LABEL_PL NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_PL NULL
#define OPTION_VAL_MANUAL_PL NULL
#define OPTION_VAL_LANDSCAPE_PL NULL
#define OPTION_VAL_PORTRAIT_PL NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_PL NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_PL NULL
#define OPTION_VAL_AUTO_PL NULL
#define WSWAN_MONO_PALETTE_LABEL_PL NULL
#define WSWAN_MONO_PALETTE_INFO_0_PL NULL
#define OPTION_VAL_DEFAULT_PL NULL
#define OPTION_VAL_WONDERSWAN_PL NULL
#define OPTION_VAL_WONDESWAN_COLOR_PL NULL
#define OPTION_VAL_SWANCRYSTAL_PL NULL
#define OPTION_VAL_GB_DMG_PL NULL
#define OPTION_VAL_GB_POCKET_PL NULL
#define OPTION_VAL_GB_LIGHT_PL NULL
#define OPTION_VAL_BLOSSOM_PINK_PL NULL
#define OPTION_VAL_BUBBLES_BLUE_PL NULL
#define OPTION_VAL_BUTTERCUP_GREEN_PL NULL
#define OPTION_VAL_DIGIVICE_PL NULL
#define OPTION_VAL_GAME_COM_PL NULL
#define OPTION_VAL_GAMEKING_PL NULL
#define OPTION_VAL_GAME_MASTER_PL NULL
#define OPTION_VAL_GOLDEN_WILD_PL NULL
#define OPTION_VAL_GREENSCALE_PL NULL
#define OPTION_VAL_HOKAGE_ORANGE_PL NULL
#define OPTION_VAL_LABO_FAWN_PL NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PL NULL
#define OPTION_VAL_MICROVISION_PL NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_PL NULL
#define OPTION_VAL_ODYSSEY_GOLD_PL NULL
#define OPTION_VAL_SHINY_SKY_BLUE_PL NULL
#define OPTION_VAL_SLIME_BLUE_PL NULL
#define OPTION_VAL_TI_83_PL NULL
#define OPTION_VAL_TRAVEL_WOOD_PL NULL
#define OPTION_VAL_VIRTUAL_BOY_PL NULL
#define WSWAN_GFX_COLORS_LABEL_PL NULL
#define WSWAN_GFX_COLORS_INFO_0_PL NULL
#define OPTION_VAL_16BIT_PL NULL
#define OPTION_VAL_24BIT_PL NULL
#define WSWAN_FRAMESKIP_LABEL_PL NULL
#define WSWAN_FRAMESKIP_INFO_0_PL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_PL NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PL NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_PL NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_PL NULL

struct retro_core_option_v2_category option_cats_pl[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pl[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_PL,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_PL,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_PL },
         { "landscape", OPTION_VAL_LANDSCAPE_PL },
         { "portrait",  OPTION_VAL_PORTRAIT_PL },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_PL,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_PL,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_PL },
         { "disabled", OPTION_VAL_LANDSCAPE_PL },
         { "enabled",  OPTION_VAL_PORTRAIT_PL },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_PL,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_PL,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_PL },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_PL },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_PL },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_PL },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_PL },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_PL },
         { "gb_light",               OPTION_VAL_GB_LIGHT_PL },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_PL },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_PL },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_PL },
         { "digivice",               OPTION_VAL_DIGIVICE_PL },
         { "game_com",               OPTION_VAL_GAME_COM_PL },
         { "gameking",               OPTION_VAL_GAMEKING_PL },
         { "game_master",            OPTION_VAL_GAME_MASTER_PL },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_PL },
         { "greenscale",             OPTION_VAL_GREENSCALE_PL },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_PL },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_PL },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PL },
         { "microvision",            OPTION_VAL_MICROVISION_PL },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_PL },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_PL },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_PL },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_PL },
         { "ti_83",                  OPTION_VAL_TI_83_PL },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_PL },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_PL },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_PL,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_PL,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_PL },
         { "24bit", OPTION_VAL_24BIT_PL },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_PL,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_PL,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_PL },
         { "manual",   OPTION_VAL_MANUAL_PL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_PL,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PL,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_PL,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_PL,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pl = {
   option_cats_pl,
   option_defs_pl
};

/* RETRO_LANGUAGE_PT_BR */

#define WSWAN_ROTATE_DISPLAY_LABEL_PT_BR NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_PT_BR NULL
#define OPTION_VAL_MANUAL_PT_BR NULL
#define OPTION_VAL_LANDSCAPE_PT_BR NULL
#define OPTION_VAL_PORTRAIT_PT_BR NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_PT_BR NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_PT_BR NULL
#define OPTION_VAL_AUTO_PT_BR NULL
#define WSWAN_MONO_PALETTE_LABEL_PT_BR NULL
#define WSWAN_MONO_PALETTE_INFO_0_PT_BR NULL
#define OPTION_VAL_DEFAULT_PT_BR NULL
#define OPTION_VAL_WONDERSWAN_PT_BR NULL
#define OPTION_VAL_WONDESWAN_COLOR_PT_BR NULL
#define OPTION_VAL_SWANCRYSTAL_PT_BR NULL
#define OPTION_VAL_GB_DMG_PT_BR NULL
#define OPTION_VAL_GB_POCKET_PT_BR NULL
#define OPTION_VAL_GB_LIGHT_PT_BR NULL
#define OPTION_VAL_BLOSSOM_PINK_PT_BR NULL
#define OPTION_VAL_BUBBLES_BLUE_PT_BR NULL
#define OPTION_VAL_BUTTERCUP_GREEN_PT_BR NULL
#define OPTION_VAL_DIGIVICE_PT_BR NULL
#define OPTION_VAL_GAME_COM_PT_BR NULL
#define OPTION_VAL_GAMEKING_PT_BR NULL
#define OPTION_VAL_GAME_MASTER_PT_BR NULL
#define OPTION_VAL_GOLDEN_WILD_PT_BR NULL
#define OPTION_VAL_GREENSCALE_PT_BR NULL
#define OPTION_VAL_HOKAGE_ORANGE_PT_BR NULL
#define OPTION_VAL_LABO_FAWN_PT_BR NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PT_BR NULL
#define OPTION_VAL_MICROVISION_PT_BR NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_PT_BR NULL
#define OPTION_VAL_ODYSSEY_GOLD_PT_BR NULL
#define OPTION_VAL_SHINY_SKY_BLUE_PT_BR NULL
#define OPTION_VAL_SLIME_BLUE_PT_BR NULL
#define OPTION_VAL_TI_83_PT_BR NULL
#define OPTION_VAL_TRAVEL_WOOD_PT_BR NULL
#define OPTION_VAL_VIRTUAL_BOY_PT_BR NULL
#define WSWAN_GFX_COLORS_LABEL_PT_BR NULL
#define WSWAN_GFX_COLORS_INFO_0_PT_BR NULL
#define OPTION_VAL_16BIT_PT_BR NULL
#define OPTION_VAL_24BIT_PT_BR NULL
#define WSWAN_FRAMESKIP_LABEL_PT_BR NULL
#define WSWAN_FRAMESKIP_INFO_0_PT_BR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_PT_BR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PT_BR NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_PT_BR NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_PT_BR NULL

struct retro_core_option_v2_category option_cats_pt_br[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_br[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_PT_BR,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_PT_BR },
         { "landscape", OPTION_VAL_LANDSCAPE_PT_BR },
         { "portrait",  OPTION_VAL_PORTRAIT_PT_BR },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_PT_BR,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_PT_BR },
         { "disabled", OPTION_VAL_LANDSCAPE_PT_BR },
         { "enabled",  OPTION_VAL_PORTRAIT_PT_BR },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_PT_BR,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_PT_BR },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_PT_BR },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_PT_BR },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_PT_BR },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_PT_BR },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_PT_BR },
         { "gb_light",               OPTION_VAL_GB_LIGHT_PT_BR },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_PT_BR },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_PT_BR },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_PT_BR },
         { "digivice",               OPTION_VAL_DIGIVICE_PT_BR },
         { "game_com",               OPTION_VAL_GAME_COM_PT_BR },
         { "gameking",               OPTION_VAL_GAMEKING_PT_BR },
         { "game_master",            OPTION_VAL_GAME_MASTER_PT_BR },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_PT_BR },
         { "greenscale",             OPTION_VAL_GREENSCALE_PT_BR },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_PT_BR },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_PT_BR },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PT_BR },
         { "microvision",            OPTION_VAL_MICROVISION_PT_BR },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_PT_BR },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_PT_BR },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_PT_BR },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_PT_BR },
         { "ti_83",                  OPTION_VAL_TI_83_PT_BR },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_PT_BR },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_PT_BR },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_PT_BR,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_PT_BR },
         { "24bit", OPTION_VAL_24BIT_PT_BR },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_PT_BR,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_PT_BR },
         { "manual",   OPTION_VAL_MANUAL_PT_BR },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_PT_BR,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_PT_BR,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_PT_BR,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pt_br = {
   option_cats_pt_br,
   option_defs_pt_br
};

/* RETRO_LANGUAGE_PT_PT */

#define WSWAN_ROTATE_DISPLAY_LABEL_PT_PT NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_PT_PT NULL
#define OPTION_VAL_MANUAL_PT_PT NULL
#define OPTION_VAL_LANDSCAPE_PT_PT NULL
#define OPTION_VAL_PORTRAIT_PT_PT NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_PT_PT NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_PT_PT NULL
#define OPTION_VAL_AUTO_PT_PT NULL
#define WSWAN_MONO_PALETTE_LABEL_PT_PT NULL
#define WSWAN_MONO_PALETTE_INFO_0_PT_PT NULL
#define OPTION_VAL_DEFAULT_PT_PT NULL
#define OPTION_VAL_WONDERSWAN_PT_PT NULL
#define OPTION_VAL_WONDESWAN_COLOR_PT_PT NULL
#define OPTION_VAL_SWANCRYSTAL_PT_PT NULL
#define OPTION_VAL_GB_DMG_PT_PT NULL
#define OPTION_VAL_GB_POCKET_PT_PT NULL
#define OPTION_VAL_GB_LIGHT_PT_PT NULL
#define OPTION_VAL_BLOSSOM_PINK_PT_PT NULL
#define OPTION_VAL_BUBBLES_BLUE_PT_PT NULL
#define OPTION_VAL_BUTTERCUP_GREEN_PT_PT NULL
#define OPTION_VAL_DIGIVICE_PT_PT NULL
#define OPTION_VAL_GAME_COM_PT_PT NULL
#define OPTION_VAL_GAMEKING_PT_PT NULL
#define OPTION_VAL_GAME_MASTER_PT_PT NULL
#define OPTION_VAL_GOLDEN_WILD_PT_PT NULL
#define OPTION_VAL_GREENSCALE_PT_PT NULL
#define OPTION_VAL_HOKAGE_ORANGE_PT_PT NULL
#define OPTION_VAL_LABO_FAWN_PT_PT NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PT_PT NULL
#define OPTION_VAL_MICROVISION_PT_PT NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_PT_PT NULL
#define OPTION_VAL_ODYSSEY_GOLD_PT_PT NULL
#define OPTION_VAL_SHINY_SKY_BLUE_PT_PT NULL
#define OPTION_VAL_SLIME_BLUE_PT_PT NULL
#define OPTION_VAL_TI_83_PT_PT NULL
#define OPTION_VAL_TRAVEL_WOOD_PT_PT NULL
#define OPTION_VAL_VIRTUAL_BOY_PT_PT NULL
#define WSWAN_GFX_COLORS_LABEL_PT_PT NULL
#define WSWAN_GFX_COLORS_INFO_0_PT_PT NULL
#define OPTION_VAL_16BIT_PT_PT NULL
#define OPTION_VAL_24BIT_PT_PT NULL
#define WSWAN_FRAMESKIP_LABEL_PT_PT NULL
#define WSWAN_FRAMESKIP_INFO_0_PT_PT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_PT_PT NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PT_PT NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_PT_PT NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_PT_PT NULL

struct retro_core_option_v2_category option_cats_pt_pt[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_pt[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_PT_PT,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_PT_PT },
         { "landscape", OPTION_VAL_LANDSCAPE_PT_PT },
         { "portrait",  OPTION_VAL_PORTRAIT_PT_PT },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_PT_PT,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_PT_PT },
         { "disabled", OPTION_VAL_LANDSCAPE_PT_PT },
         { "enabled",  OPTION_VAL_PORTRAIT_PT_PT },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_PT_PT,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_PT_PT },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_PT_PT },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_PT_PT },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_PT_PT },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_PT_PT },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_PT_PT },
         { "gb_light",               OPTION_VAL_GB_LIGHT_PT_PT },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_PT_PT },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_PT_PT },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_PT_PT },
         { "digivice",               OPTION_VAL_DIGIVICE_PT_PT },
         { "game_com",               OPTION_VAL_GAME_COM_PT_PT },
         { "gameking",               OPTION_VAL_GAMEKING_PT_PT },
         { "game_master",            OPTION_VAL_GAME_MASTER_PT_PT },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_PT_PT },
         { "greenscale",             OPTION_VAL_GREENSCALE_PT_PT },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_PT_PT },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_PT_PT },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_PT_PT },
         { "microvision",            OPTION_VAL_MICROVISION_PT_PT },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_PT_PT },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_PT_PT },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_PT_PT },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_PT_PT },
         { "ti_83",                  OPTION_VAL_TI_83_PT_PT },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_PT_PT },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_PT_PT },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_PT_PT,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_PT_PT },
         { "24bit", OPTION_VAL_24BIT_PT_PT },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_PT_PT,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_PT_PT },
         { "manual",   OPTION_VAL_MANUAL_PT_PT },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_PT_PT,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_PT_PT,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_PT_PT,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_pt_pt = {
   option_cats_pt_pt,
   option_defs_pt_pt
};

/* RETRO_LANGUAGE_RO */

#define WSWAN_ROTATE_DISPLAY_LABEL_RO NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_RO NULL
#define OPTION_VAL_MANUAL_RO NULL
#define OPTION_VAL_LANDSCAPE_RO NULL
#define OPTION_VAL_PORTRAIT_RO NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_RO NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_RO NULL
#define OPTION_VAL_AUTO_RO NULL
#define WSWAN_MONO_PALETTE_LABEL_RO NULL
#define WSWAN_MONO_PALETTE_INFO_0_RO NULL
#define OPTION_VAL_DEFAULT_RO NULL
#define OPTION_VAL_WONDERSWAN_RO NULL
#define OPTION_VAL_WONDESWAN_COLOR_RO NULL
#define OPTION_VAL_SWANCRYSTAL_RO NULL
#define OPTION_VAL_GB_DMG_RO NULL
#define OPTION_VAL_GB_POCKET_RO NULL
#define OPTION_VAL_GB_LIGHT_RO NULL
#define OPTION_VAL_BLOSSOM_PINK_RO NULL
#define OPTION_VAL_BUBBLES_BLUE_RO NULL
#define OPTION_VAL_BUTTERCUP_GREEN_RO NULL
#define OPTION_VAL_DIGIVICE_RO NULL
#define OPTION_VAL_GAME_COM_RO NULL
#define OPTION_VAL_GAMEKING_RO NULL
#define OPTION_VAL_GAME_MASTER_RO NULL
#define OPTION_VAL_GOLDEN_WILD_RO NULL
#define OPTION_VAL_GREENSCALE_RO NULL
#define OPTION_VAL_HOKAGE_ORANGE_RO NULL
#define OPTION_VAL_LABO_FAWN_RO NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_RO NULL
#define OPTION_VAL_MICROVISION_RO NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_RO NULL
#define OPTION_VAL_ODYSSEY_GOLD_RO NULL
#define OPTION_VAL_SHINY_SKY_BLUE_RO NULL
#define OPTION_VAL_SLIME_BLUE_RO NULL
#define OPTION_VAL_TI_83_RO NULL
#define OPTION_VAL_TRAVEL_WOOD_RO NULL
#define OPTION_VAL_VIRTUAL_BOY_RO NULL
#define WSWAN_GFX_COLORS_LABEL_RO NULL
#define WSWAN_GFX_COLORS_INFO_0_RO NULL
#define OPTION_VAL_16BIT_RO NULL
#define OPTION_VAL_24BIT_RO NULL
#define WSWAN_FRAMESKIP_LABEL_RO NULL
#define WSWAN_FRAMESKIP_INFO_0_RO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_RO NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_RO NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_RO NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_RO NULL

struct retro_core_option_v2_category option_cats_ro[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ro[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_RO,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_RO,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_RO },
         { "landscape", OPTION_VAL_LANDSCAPE_RO },
         { "portrait",  OPTION_VAL_PORTRAIT_RO },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_RO,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_RO,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_RO },
         { "disabled", OPTION_VAL_LANDSCAPE_RO },
         { "enabled",  OPTION_VAL_PORTRAIT_RO },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_RO,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_RO,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_RO },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_RO },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_RO },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_RO },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_RO },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_RO },
         { "gb_light",               OPTION_VAL_GB_LIGHT_RO },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_RO },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_RO },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_RO },
         { "digivice",               OPTION_VAL_DIGIVICE_RO },
         { "game_com",               OPTION_VAL_GAME_COM_RO },
         { "gameking",               OPTION_VAL_GAMEKING_RO },
         { "game_master",            OPTION_VAL_GAME_MASTER_RO },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_RO },
         { "greenscale",             OPTION_VAL_GREENSCALE_RO },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_RO },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_RO },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_RO },
         { "microvision",            OPTION_VAL_MICROVISION_RO },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_RO },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_RO },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_RO },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_RO },
         { "ti_83",                  OPTION_VAL_TI_83_RO },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_RO },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_RO },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_RO,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_RO,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_RO },
         { "24bit", OPTION_VAL_24BIT_RO },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_RO,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_RO,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_RO },
         { "manual",   OPTION_VAL_MANUAL_RO },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_RO,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_RO,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_RO,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_RO,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ro = {
   option_cats_ro,
   option_defs_ro
};

/* RETRO_LANGUAGE_RU */

#define WSWAN_ROTATE_DISPLAY_LABEL_RU NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_RU NULL
#define OPTION_VAL_MANUAL_RU NULL
#define OPTION_VAL_LANDSCAPE_RU NULL
#define OPTION_VAL_PORTRAIT_RU NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_RU NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_RU NULL
#define OPTION_VAL_AUTO_RU NULL
#define WSWAN_MONO_PALETTE_LABEL_RU NULL
#define WSWAN_MONO_PALETTE_INFO_0_RU NULL
#define OPTION_VAL_DEFAULT_RU NULL
#define OPTION_VAL_WONDERSWAN_RU NULL
#define OPTION_VAL_WONDESWAN_COLOR_RU NULL
#define OPTION_VAL_SWANCRYSTAL_RU NULL
#define OPTION_VAL_GB_DMG_RU NULL
#define OPTION_VAL_GB_POCKET_RU NULL
#define OPTION_VAL_GB_LIGHT_RU NULL
#define OPTION_VAL_BLOSSOM_PINK_RU NULL
#define OPTION_VAL_BUBBLES_BLUE_RU NULL
#define OPTION_VAL_BUTTERCUP_GREEN_RU NULL
#define OPTION_VAL_DIGIVICE_RU NULL
#define OPTION_VAL_GAME_COM_RU NULL
#define OPTION_VAL_GAMEKING_RU NULL
#define OPTION_VAL_GAME_MASTER_RU NULL
#define OPTION_VAL_GOLDEN_WILD_RU NULL
#define OPTION_VAL_GREENSCALE_RU NULL
#define OPTION_VAL_HOKAGE_ORANGE_RU NULL
#define OPTION_VAL_LABO_FAWN_RU NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_RU NULL
#define OPTION_VAL_MICROVISION_RU NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_RU NULL
#define OPTION_VAL_ODYSSEY_GOLD_RU NULL
#define OPTION_VAL_SHINY_SKY_BLUE_RU NULL
#define OPTION_VAL_SLIME_BLUE_RU NULL
#define OPTION_VAL_TI_83_RU NULL
#define OPTION_VAL_TRAVEL_WOOD_RU NULL
#define OPTION_VAL_VIRTUAL_BOY_RU NULL
#define WSWAN_GFX_COLORS_LABEL_RU NULL
#define WSWAN_GFX_COLORS_INFO_0_RU NULL
#define OPTION_VAL_16BIT_RU NULL
#define OPTION_VAL_24BIT_RU NULL
#define WSWAN_FRAMESKIP_LABEL_RU NULL
#define WSWAN_FRAMESKIP_INFO_0_RU NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_RU NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_RU NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_RU NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_RU NULL

struct retro_core_option_v2_category option_cats_ru[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ru[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_RU,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_RU,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_RU },
         { "landscape", OPTION_VAL_LANDSCAPE_RU },
         { "portrait",  OPTION_VAL_PORTRAIT_RU },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_RU,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_RU,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_RU },
         { "disabled", OPTION_VAL_LANDSCAPE_RU },
         { "enabled",  OPTION_VAL_PORTRAIT_RU },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_RU,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_RU,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_RU },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_RU },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_RU },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_RU },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_RU },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_RU },
         { "gb_light",               OPTION_VAL_GB_LIGHT_RU },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_RU },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_RU },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_RU },
         { "digivice",               OPTION_VAL_DIGIVICE_RU },
         { "game_com",               OPTION_VAL_GAME_COM_RU },
         { "gameking",               OPTION_VAL_GAMEKING_RU },
         { "game_master",            OPTION_VAL_GAME_MASTER_RU },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_RU },
         { "greenscale",             OPTION_VAL_GREENSCALE_RU },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_RU },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_RU },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_RU },
         { "microvision",            OPTION_VAL_MICROVISION_RU },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_RU },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_RU },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_RU },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_RU },
         { "ti_83",                  OPTION_VAL_TI_83_RU },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_RU },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_RU },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_RU,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_RU,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_RU },
         { "24bit", OPTION_VAL_24BIT_RU },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_RU,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_RU,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_RU },
         { "manual",   OPTION_VAL_MANUAL_RU },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_RU,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_RU,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_RU,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_RU,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_ru = {
   option_cats_ru,
   option_defs_ru
};

/* RETRO_LANGUAGE_SI */

#define WSWAN_ROTATE_DISPLAY_LABEL_SI NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_SI NULL
#define OPTION_VAL_MANUAL_SI NULL
#define OPTION_VAL_LANDSCAPE_SI NULL
#define OPTION_VAL_PORTRAIT_SI NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_SI NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_SI NULL
#define OPTION_VAL_AUTO_SI NULL
#define WSWAN_MONO_PALETTE_LABEL_SI NULL
#define WSWAN_MONO_PALETTE_INFO_0_SI NULL
#define OPTION_VAL_DEFAULT_SI NULL
#define OPTION_VAL_WONDERSWAN_SI NULL
#define OPTION_VAL_WONDESWAN_COLOR_SI NULL
#define OPTION_VAL_SWANCRYSTAL_SI NULL
#define OPTION_VAL_GB_DMG_SI NULL
#define OPTION_VAL_GB_POCKET_SI NULL
#define OPTION_VAL_GB_LIGHT_SI NULL
#define OPTION_VAL_BLOSSOM_PINK_SI NULL
#define OPTION_VAL_BUBBLES_BLUE_SI NULL
#define OPTION_VAL_BUTTERCUP_GREEN_SI NULL
#define OPTION_VAL_DIGIVICE_SI NULL
#define OPTION_VAL_GAME_COM_SI NULL
#define OPTION_VAL_GAMEKING_SI NULL
#define OPTION_VAL_GAME_MASTER_SI NULL
#define OPTION_VAL_GOLDEN_WILD_SI NULL
#define OPTION_VAL_GREENSCALE_SI NULL
#define OPTION_VAL_HOKAGE_ORANGE_SI NULL
#define OPTION_VAL_LABO_FAWN_SI NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SI NULL
#define OPTION_VAL_MICROVISION_SI NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_SI NULL
#define OPTION_VAL_ODYSSEY_GOLD_SI NULL
#define OPTION_VAL_SHINY_SKY_BLUE_SI NULL
#define OPTION_VAL_SLIME_BLUE_SI NULL
#define OPTION_VAL_TI_83_SI NULL
#define OPTION_VAL_TRAVEL_WOOD_SI NULL
#define OPTION_VAL_VIRTUAL_BOY_SI NULL
#define WSWAN_GFX_COLORS_LABEL_SI NULL
#define WSWAN_GFX_COLORS_INFO_0_SI NULL
#define OPTION_VAL_16BIT_SI NULL
#define OPTION_VAL_24BIT_SI NULL
#define WSWAN_FRAMESKIP_LABEL_SI NULL
#define WSWAN_FRAMESKIP_INFO_0_SI NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_SI NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SI NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_SI NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_SI NULL

struct retro_core_option_v2_category option_cats_si[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_si[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_SI,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_SI,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_SI },
         { "landscape", OPTION_VAL_LANDSCAPE_SI },
         { "portrait",  OPTION_VAL_PORTRAIT_SI },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_SI,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_SI,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_SI },
         { "disabled", OPTION_VAL_LANDSCAPE_SI },
         { "enabled",  OPTION_VAL_PORTRAIT_SI },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_SI,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_SI,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_SI },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_SI },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_SI },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_SI },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_SI },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_SI },
         { "gb_light",               OPTION_VAL_GB_LIGHT_SI },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_SI },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_SI },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_SI },
         { "digivice",               OPTION_VAL_DIGIVICE_SI },
         { "game_com",               OPTION_VAL_GAME_COM_SI },
         { "gameking",               OPTION_VAL_GAMEKING_SI },
         { "game_master",            OPTION_VAL_GAME_MASTER_SI },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_SI },
         { "greenscale",             OPTION_VAL_GREENSCALE_SI },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_SI },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_SI },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SI },
         { "microvision",            OPTION_VAL_MICROVISION_SI },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_SI },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_SI },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_SI },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_SI },
         { "ti_83",                  OPTION_VAL_TI_83_SI },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_SI },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_SI },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_SI,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_SI,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_SI },
         { "24bit", OPTION_VAL_24BIT_SI },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_SI,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_SI,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_SI },
         { "manual",   OPTION_VAL_MANUAL_SI },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_SI,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SI,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_SI,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_SI,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_si = {
   option_cats_si,
   option_defs_si
};

/* RETRO_LANGUAGE_SK */

#define WSWAN_ROTATE_DISPLAY_LABEL_SK NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_SK NULL
#define OPTION_VAL_MANUAL_SK NULL
#define OPTION_VAL_LANDSCAPE_SK NULL
#define OPTION_VAL_PORTRAIT_SK NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_SK NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_SK NULL
#define OPTION_VAL_AUTO_SK NULL
#define WSWAN_MONO_PALETTE_LABEL_SK NULL
#define WSWAN_MONO_PALETTE_INFO_0_SK NULL
#define OPTION_VAL_DEFAULT_SK NULL
#define OPTION_VAL_WONDERSWAN_SK NULL
#define OPTION_VAL_WONDESWAN_COLOR_SK NULL
#define OPTION_VAL_SWANCRYSTAL_SK NULL
#define OPTION_VAL_GB_DMG_SK NULL
#define OPTION_VAL_GB_POCKET_SK NULL
#define OPTION_VAL_GB_LIGHT_SK NULL
#define OPTION_VAL_BLOSSOM_PINK_SK NULL
#define OPTION_VAL_BUBBLES_BLUE_SK NULL
#define OPTION_VAL_BUTTERCUP_GREEN_SK NULL
#define OPTION_VAL_DIGIVICE_SK NULL
#define OPTION_VAL_GAME_COM_SK NULL
#define OPTION_VAL_GAMEKING_SK NULL
#define OPTION_VAL_GAME_MASTER_SK NULL
#define OPTION_VAL_GOLDEN_WILD_SK NULL
#define OPTION_VAL_GREENSCALE_SK NULL
#define OPTION_VAL_HOKAGE_ORANGE_SK NULL
#define OPTION_VAL_LABO_FAWN_SK NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SK NULL
#define OPTION_VAL_MICROVISION_SK NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_SK NULL
#define OPTION_VAL_ODYSSEY_GOLD_SK NULL
#define OPTION_VAL_SHINY_SKY_BLUE_SK NULL
#define OPTION_VAL_SLIME_BLUE_SK NULL
#define OPTION_VAL_TI_83_SK NULL
#define OPTION_VAL_TRAVEL_WOOD_SK NULL
#define OPTION_VAL_VIRTUAL_BOY_SK NULL
#define WSWAN_GFX_COLORS_LABEL_SK NULL
#define WSWAN_GFX_COLORS_INFO_0_SK NULL
#define OPTION_VAL_16BIT_SK NULL
#define OPTION_VAL_24BIT_SK NULL
#define WSWAN_FRAMESKIP_LABEL_SK NULL
#define WSWAN_FRAMESKIP_INFO_0_SK NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_SK NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SK NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_SK NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_SK NULL

struct retro_core_option_v2_category option_cats_sk[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sk[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_SK,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_SK,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_SK },
         { "landscape", OPTION_VAL_LANDSCAPE_SK },
         { "portrait",  OPTION_VAL_PORTRAIT_SK },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_SK,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_SK,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_SK },
         { "disabled", OPTION_VAL_LANDSCAPE_SK },
         { "enabled",  OPTION_VAL_PORTRAIT_SK },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_SK,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_SK,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_SK },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_SK },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_SK },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_SK },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_SK },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_SK },
         { "gb_light",               OPTION_VAL_GB_LIGHT_SK },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_SK },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_SK },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_SK },
         { "digivice",               OPTION_VAL_DIGIVICE_SK },
         { "game_com",               OPTION_VAL_GAME_COM_SK },
         { "gameking",               OPTION_VAL_GAMEKING_SK },
         { "game_master",            OPTION_VAL_GAME_MASTER_SK },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_SK },
         { "greenscale",             OPTION_VAL_GREENSCALE_SK },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_SK },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_SK },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SK },
         { "microvision",            OPTION_VAL_MICROVISION_SK },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_SK },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_SK },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_SK },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_SK },
         { "ti_83",                  OPTION_VAL_TI_83_SK },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_SK },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_SK },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_SK,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_SK,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_SK },
         { "24bit", OPTION_VAL_24BIT_SK },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_SK,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_SK,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_SK },
         { "manual",   OPTION_VAL_MANUAL_SK },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_SK,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SK,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_SK,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_SK,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sk = {
   option_cats_sk,
   option_defs_sk
};

/* RETRO_LANGUAGE_SR */

#define WSWAN_ROTATE_DISPLAY_LABEL_SR NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_SR NULL
#define OPTION_VAL_MANUAL_SR NULL
#define OPTION_VAL_LANDSCAPE_SR NULL
#define OPTION_VAL_PORTRAIT_SR NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_SR NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_SR NULL
#define OPTION_VAL_AUTO_SR NULL
#define WSWAN_MONO_PALETTE_LABEL_SR NULL
#define WSWAN_MONO_PALETTE_INFO_0_SR NULL
#define OPTION_VAL_DEFAULT_SR NULL
#define OPTION_VAL_WONDERSWAN_SR NULL
#define OPTION_VAL_WONDESWAN_COLOR_SR NULL
#define OPTION_VAL_SWANCRYSTAL_SR NULL
#define OPTION_VAL_GB_DMG_SR NULL
#define OPTION_VAL_GB_POCKET_SR NULL
#define OPTION_VAL_GB_LIGHT_SR NULL
#define OPTION_VAL_BLOSSOM_PINK_SR NULL
#define OPTION_VAL_BUBBLES_BLUE_SR NULL
#define OPTION_VAL_BUTTERCUP_GREEN_SR NULL
#define OPTION_VAL_DIGIVICE_SR NULL
#define OPTION_VAL_GAME_COM_SR NULL
#define OPTION_VAL_GAMEKING_SR NULL
#define OPTION_VAL_GAME_MASTER_SR NULL
#define OPTION_VAL_GOLDEN_WILD_SR NULL
#define OPTION_VAL_GREENSCALE_SR NULL
#define OPTION_VAL_HOKAGE_ORANGE_SR NULL
#define OPTION_VAL_LABO_FAWN_SR NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SR NULL
#define OPTION_VAL_MICROVISION_SR NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_SR NULL
#define OPTION_VAL_ODYSSEY_GOLD_SR NULL
#define OPTION_VAL_SHINY_SKY_BLUE_SR NULL
#define OPTION_VAL_SLIME_BLUE_SR NULL
#define OPTION_VAL_TI_83_SR NULL
#define OPTION_VAL_TRAVEL_WOOD_SR NULL
#define OPTION_VAL_VIRTUAL_BOY_SR NULL
#define WSWAN_GFX_COLORS_LABEL_SR NULL
#define WSWAN_GFX_COLORS_INFO_0_SR NULL
#define OPTION_VAL_16BIT_SR NULL
#define OPTION_VAL_24BIT_SR NULL
#define WSWAN_FRAMESKIP_LABEL_SR NULL
#define WSWAN_FRAMESKIP_INFO_0_SR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_SR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SR NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_SR NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_SR NULL

struct retro_core_option_v2_category option_cats_sr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sr[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_SR,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_SR,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_SR },
         { "landscape", OPTION_VAL_LANDSCAPE_SR },
         { "portrait",  OPTION_VAL_PORTRAIT_SR },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_SR,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_SR,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_SR },
         { "disabled", OPTION_VAL_LANDSCAPE_SR },
         { "enabled",  OPTION_VAL_PORTRAIT_SR },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_SR,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_SR,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_SR },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_SR },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_SR },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_SR },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_SR },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_SR },
         { "gb_light",               OPTION_VAL_GB_LIGHT_SR },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_SR },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_SR },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_SR },
         { "digivice",               OPTION_VAL_DIGIVICE_SR },
         { "game_com",               OPTION_VAL_GAME_COM_SR },
         { "gameking",               OPTION_VAL_GAMEKING_SR },
         { "game_master",            OPTION_VAL_GAME_MASTER_SR },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_SR },
         { "greenscale",             OPTION_VAL_GREENSCALE_SR },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_SR },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_SR },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SR },
         { "microvision",            OPTION_VAL_MICROVISION_SR },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_SR },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_SR },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_SR },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_SR },
         { "ti_83",                  OPTION_VAL_TI_83_SR },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_SR },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_SR },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_SR,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_SR,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_SR },
         { "24bit", OPTION_VAL_24BIT_SR },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_SR,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_SR,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_SR },
         { "manual",   OPTION_VAL_MANUAL_SR },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_SR,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SR,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_SR,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_SR,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sr = {
   option_cats_sr,
   option_defs_sr
};

/* RETRO_LANGUAGE_SV */

#define WSWAN_ROTATE_DISPLAY_LABEL_SV NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_SV NULL
#define OPTION_VAL_MANUAL_SV NULL
#define OPTION_VAL_LANDSCAPE_SV NULL
#define OPTION_VAL_PORTRAIT_SV NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_SV NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_SV NULL
#define OPTION_VAL_AUTO_SV NULL
#define WSWAN_MONO_PALETTE_LABEL_SV NULL
#define WSWAN_MONO_PALETTE_INFO_0_SV NULL
#define OPTION_VAL_DEFAULT_SV NULL
#define OPTION_VAL_WONDERSWAN_SV NULL
#define OPTION_VAL_WONDESWAN_COLOR_SV NULL
#define OPTION_VAL_SWANCRYSTAL_SV NULL
#define OPTION_VAL_GB_DMG_SV NULL
#define OPTION_VAL_GB_POCKET_SV NULL
#define OPTION_VAL_GB_LIGHT_SV NULL
#define OPTION_VAL_BLOSSOM_PINK_SV NULL
#define OPTION_VAL_BUBBLES_BLUE_SV NULL
#define OPTION_VAL_BUTTERCUP_GREEN_SV NULL
#define OPTION_VAL_DIGIVICE_SV NULL
#define OPTION_VAL_GAME_COM_SV NULL
#define OPTION_VAL_GAMEKING_SV NULL
#define OPTION_VAL_GAME_MASTER_SV NULL
#define OPTION_VAL_GOLDEN_WILD_SV NULL
#define OPTION_VAL_GREENSCALE_SV NULL
#define OPTION_VAL_HOKAGE_ORANGE_SV NULL
#define OPTION_VAL_LABO_FAWN_SV NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SV NULL
#define OPTION_VAL_MICROVISION_SV NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_SV NULL
#define OPTION_VAL_ODYSSEY_GOLD_SV NULL
#define OPTION_VAL_SHINY_SKY_BLUE_SV NULL
#define OPTION_VAL_SLIME_BLUE_SV NULL
#define OPTION_VAL_TI_83_SV NULL
#define OPTION_VAL_TRAVEL_WOOD_SV NULL
#define OPTION_VAL_VIRTUAL_BOY_SV NULL
#define WSWAN_GFX_COLORS_LABEL_SV NULL
#define WSWAN_GFX_COLORS_INFO_0_SV NULL
#define OPTION_VAL_16BIT_SV NULL
#define OPTION_VAL_24BIT_SV NULL
#define WSWAN_FRAMESKIP_LABEL_SV NULL
#define WSWAN_FRAMESKIP_INFO_0_SV NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_SV NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SV NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_SV NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_SV NULL

struct retro_core_option_v2_category option_cats_sv[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sv[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_SV,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_SV,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_SV },
         { "landscape", OPTION_VAL_LANDSCAPE_SV },
         { "portrait",  OPTION_VAL_PORTRAIT_SV },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_SV,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_SV,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_SV },
         { "disabled", OPTION_VAL_LANDSCAPE_SV },
         { "enabled",  OPTION_VAL_PORTRAIT_SV },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_SV,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_SV,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_SV },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_SV },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_SV },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_SV },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_SV },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_SV },
         { "gb_light",               OPTION_VAL_GB_LIGHT_SV },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_SV },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_SV },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_SV },
         { "digivice",               OPTION_VAL_DIGIVICE_SV },
         { "game_com",               OPTION_VAL_GAME_COM_SV },
         { "gameking",               OPTION_VAL_GAMEKING_SV },
         { "game_master",            OPTION_VAL_GAME_MASTER_SV },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_SV },
         { "greenscale",             OPTION_VAL_GREENSCALE_SV },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_SV },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_SV },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_SV },
         { "microvision",            OPTION_VAL_MICROVISION_SV },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_SV },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_SV },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_SV },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_SV },
         { "ti_83",                  OPTION_VAL_TI_83_SV },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_SV },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_SV },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_SV,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_SV,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_SV },
         { "24bit", OPTION_VAL_24BIT_SV },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_SV,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_SV,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_SV },
         { "manual",   OPTION_VAL_MANUAL_SV },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_SV,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_SV,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_SV,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_SV,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_sv = {
   option_cats_sv,
   option_defs_sv
};

/* RETRO_LANGUAGE_TR */

#define WSWAN_ROTATE_DISPLAY_LABEL_TR NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_TR NULL
#define OPTION_VAL_MANUAL_TR NULL
#define OPTION_VAL_LANDSCAPE_TR NULL
#define OPTION_VAL_PORTRAIT_TR NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_TR "Düğme eşlemelerini döndür"
#define WSWAN_ROTATE_KEYMAP_INFO_0_TR NULL
#define OPTION_VAL_AUTO_TR "otomatik"
#define WSWAN_MONO_PALETTE_LABEL_TR NULL
#define WSWAN_MONO_PALETTE_INFO_0_TR NULL
#define OPTION_VAL_DEFAULT_TR NULL
#define OPTION_VAL_WONDERSWAN_TR NULL
#define OPTION_VAL_WONDESWAN_COLOR_TR NULL
#define OPTION_VAL_SWANCRYSTAL_TR NULL
#define OPTION_VAL_GB_DMG_TR NULL
#define OPTION_VAL_GB_POCKET_TR NULL
#define OPTION_VAL_GB_LIGHT_TR NULL
#define OPTION_VAL_BLOSSOM_PINK_TR NULL
#define OPTION_VAL_BUBBLES_BLUE_TR NULL
#define OPTION_VAL_BUTTERCUP_GREEN_TR NULL
#define OPTION_VAL_DIGIVICE_TR NULL
#define OPTION_VAL_GAME_COM_TR NULL
#define OPTION_VAL_GAMEKING_TR NULL
#define OPTION_VAL_GAME_MASTER_TR NULL
#define OPTION_VAL_GOLDEN_WILD_TR NULL
#define OPTION_VAL_GREENSCALE_TR NULL
#define OPTION_VAL_HOKAGE_ORANGE_TR NULL
#define OPTION_VAL_LABO_FAWN_TR NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_TR NULL
#define OPTION_VAL_MICROVISION_TR NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_TR NULL
#define OPTION_VAL_ODYSSEY_GOLD_TR NULL
#define OPTION_VAL_SHINY_SKY_BLUE_TR NULL
#define OPTION_VAL_SLIME_BLUE_TR NULL
#define OPTION_VAL_TI_83_TR NULL
#define OPTION_VAL_TRAVEL_WOOD_TR NULL
#define OPTION_VAL_VIRTUAL_BOY_TR NULL
#define WSWAN_GFX_COLORS_LABEL_TR NULL
#define WSWAN_GFX_COLORS_INFO_0_TR NULL
#define OPTION_VAL_16BIT_TR NULL
#define OPTION_VAL_24BIT_TR NULL
#define WSWAN_FRAMESKIP_LABEL_TR NULL
#define WSWAN_FRAMESKIP_INFO_0_TR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_TR NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_TR NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_TR NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_TR NULL

struct retro_core_option_v2_category option_cats_tr[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tr[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_TR,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_TR,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_TR },
         { "landscape", OPTION_VAL_LANDSCAPE_TR },
         { "portrait",  OPTION_VAL_PORTRAIT_TR },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_TR,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_TR,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_TR },
         { "disabled", OPTION_VAL_LANDSCAPE_TR },
         { "enabled",  OPTION_VAL_PORTRAIT_TR },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_TR,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_TR,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_TR },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_TR },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_TR },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_TR },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_TR },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_TR },
         { "gb_light",               OPTION_VAL_GB_LIGHT_TR },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_TR },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_TR },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_TR },
         { "digivice",               OPTION_VAL_DIGIVICE_TR },
         { "game_com",               OPTION_VAL_GAME_COM_TR },
         { "gameking",               OPTION_VAL_GAMEKING_TR },
         { "game_master",            OPTION_VAL_GAME_MASTER_TR },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_TR },
         { "greenscale",             OPTION_VAL_GREENSCALE_TR },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_TR },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_TR },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_TR },
         { "microvision",            OPTION_VAL_MICROVISION_TR },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_TR },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_TR },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_TR },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_TR },
         { "ti_83",                  OPTION_VAL_TI_83_TR },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_TR },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_TR },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_TR,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_TR,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_TR },
         { "24bit", OPTION_VAL_24BIT_TR },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_TR,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_TR,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_TR },
         { "manual",   OPTION_VAL_MANUAL_TR },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_TR,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_TR,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_TR,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_TR,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_tr = {
   option_cats_tr,
   option_defs_tr
};

/* RETRO_LANGUAGE_UK */

#define WSWAN_ROTATE_DISPLAY_LABEL_UK NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_UK NULL
#define OPTION_VAL_MANUAL_UK NULL
#define OPTION_VAL_LANDSCAPE_UK NULL
#define OPTION_VAL_PORTRAIT_UK NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_UK NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_UK NULL
#define OPTION_VAL_AUTO_UK NULL
#define WSWAN_MONO_PALETTE_LABEL_UK NULL
#define WSWAN_MONO_PALETTE_INFO_0_UK NULL
#define OPTION_VAL_DEFAULT_UK NULL
#define OPTION_VAL_WONDERSWAN_UK NULL
#define OPTION_VAL_WONDESWAN_COLOR_UK NULL
#define OPTION_VAL_SWANCRYSTAL_UK NULL
#define OPTION_VAL_GB_DMG_UK NULL
#define OPTION_VAL_GB_POCKET_UK NULL
#define OPTION_VAL_GB_LIGHT_UK NULL
#define OPTION_VAL_BLOSSOM_PINK_UK NULL
#define OPTION_VAL_BUBBLES_BLUE_UK NULL
#define OPTION_VAL_BUTTERCUP_GREEN_UK NULL
#define OPTION_VAL_DIGIVICE_UK NULL
#define OPTION_VAL_GAME_COM_UK NULL
#define OPTION_VAL_GAMEKING_UK NULL
#define OPTION_VAL_GAME_MASTER_UK NULL
#define OPTION_VAL_GOLDEN_WILD_UK NULL
#define OPTION_VAL_GREENSCALE_UK NULL
#define OPTION_VAL_HOKAGE_ORANGE_UK NULL
#define OPTION_VAL_LABO_FAWN_UK NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_UK NULL
#define OPTION_VAL_MICROVISION_UK NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_UK NULL
#define OPTION_VAL_ODYSSEY_GOLD_UK NULL
#define OPTION_VAL_SHINY_SKY_BLUE_UK NULL
#define OPTION_VAL_SLIME_BLUE_UK NULL
#define OPTION_VAL_TI_83_UK NULL
#define OPTION_VAL_TRAVEL_WOOD_UK NULL
#define OPTION_VAL_VIRTUAL_BOY_UK NULL
#define WSWAN_GFX_COLORS_LABEL_UK NULL
#define WSWAN_GFX_COLORS_INFO_0_UK NULL
#define OPTION_VAL_16BIT_UK NULL
#define OPTION_VAL_24BIT_UK NULL
#define WSWAN_FRAMESKIP_LABEL_UK NULL
#define WSWAN_FRAMESKIP_INFO_0_UK NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_UK NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_UK NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_UK NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_UK NULL

struct retro_core_option_v2_category option_cats_uk[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_uk[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_UK,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_UK,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_UK },
         { "landscape", OPTION_VAL_LANDSCAPE_UK },
         { "portrait",  OPTION_VAL_PORTRAIT_UK },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_UK,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_UK,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_UK },
         { "disabled", OPTION_VAL_LANDSCAPE_UK },
         { "enabled",  OPTION_VAL_PORTRAIT_UK },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_UK,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_UK,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_UK },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_UK },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_UK },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_UK },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_UK },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_UK },
         { "gb_light",               OPTION_VAL_GB_LIGHT_UK },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_UK },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_UK },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_UK },
         { "digivice",               OPTION_VAL_DIGIVICE_UK },
         { "game_com",               OPTION_VAL_GAME_COM_UK },
         { "gameking",               OPTION_VAL_GAMEKING_UK },
         { "game_master",            OPTION_VAL_GAME_MASTER_UK },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_UK },
         { "greenscale",             OPTION_VAL_GREENSCALE_UK },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_UK },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_UK },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_UK },
         { "microvision",            OPTION_VAL_MICROVISION_UK },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_UK },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_UK },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_UK },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_UK },
         { "ti_83",                  OPTION_VAL_TI_83_UK },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_UK },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_UK },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_UK,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_UK,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_UK },
         { "24bit", OPTION_VAL_24BIT_UK },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_UK,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_UK,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_UK },
         { "manual",   OPTION_VAL_MANUAL_UK },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_UK,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_UK,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_UK,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_UK,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_uk = {
   option_cats_uk,
   option_defs_uk
};

/* RETRO_LANGUAGE_VN */

#define WSWAN_ROTATE_DISPLAY_LABEL_VN NULL
#define WSWAN_ROTATE_DISPLAY_INFO_0_VN NULL
#define OPTION_VAL_MANUAL_VN NULL
#define OPTION_VAL_LANDSCAPE_VN NULL
#define OPTION_VAL_PORTRAIT_VN NULL
#define WSWAN_ROTATE_KEYMAP_LABEL_VN NULL
#define WSWAN_ROTATE_KEYMAP_INFO_0_VN NULL
#define OPTION_VAL_AUTO_VN NULL
#define WSWAN_MONO_PALETTE_LABEL_VN NULL
#define WSWAN_MONO_PALETTE_INFO_0_VN NULL
#define OPTION_VAL_DEFAULT_VN NULL
#define OPTION_VAL_WONDERSWAN_VN NULL
#define OPTION_VAL_WONDESWAN_COLOR_VN NULL
#define OPTION_VAL_SWANCRYSTAL_VN NULL
#define OPTION_VAL_GB_DMG_VN NULL
#define OPTION_VAL_GB_POCKET_VN NULL
#define OPTION_VAL_GB_LIGHT_VN NULL
#define OPTION_VAL_BLOSSOM_PINK_VN NULL
#define OPTION_VAL_BUBBLES_BLUE_VN NULL
#define OPTION_VAL_BUTTERCUP_GREEN_VN NULL
#define OPTION_VAL_DIGIVICE_VN NULL
#define OPTION_VAL_GAME_COM_VN NULL
#define OPTION_VAL_GAMEKING_VN NULL
#define OPTION_VAL_GAME_MASTER_VN NULL
#define OPTION_VAL_GOLDEN_WILD_VN NULL
#define OPTION_VAL_GREENSCALE_VN NULL
#define OPTION_VAL_HOKAGE_ORANGE_VN NULL
#define OPTION_VAL_LABO_FAWN_VN NULL
#define OPTION_VAL_LEGENDARY_SUPER_SAIYAN_VN NULL
#define OPTION_VAL_MICROVISION_VN NULL
#define OPTION_VAL_MILLION_LIVE_GOLD_VN NULL
#define OPTION_VAL_ODYSSEY_GOLD_VN NULL
#define OPTION_VAL_SHINY_SKY_BLUE_VN NULL
#define OPTION_VAL_SLIME_BLUE_VN NULL
#define OPTION_VAL_TI_83_VN NULL
#define OPTION_VAL_TRAVEL_WOOD_VN NULL
#define OPTION_VAL_VIRTUAL_BOY_VN NULL
#define WSWAN_GFX_COLORS_LABEL_VN NULL
#define WSWAN_GFX_COLORS_INFO_0_VN NULL
#define OPTION_VAL_16BIT_VN NULL
#define OPTION_VAL_24BIT_VN NULL
#define WSWAN_FRAMESKIP_LABEL_VN NULL
#define WSWAN_FRAMESKIP_INFO_0_VN NULL
#define WSWAN_FRAMESKIP_THRESHOLD_LABEL_VN NULL
#define WSWAN_FRAMESKIP_THRESHOLD_INFO_0_VN NULL
#define WSWAN_SOUND_SAMPLE_RATE_LABEL_VN NULL
#define WSWAN_SOUND_SAMPLE_RATE_INFO_0_VN NULL

struct retro_core_option_v2_category option_cats_vn[] = {
   { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_vn[] = {
   {
      "wswan_rotate_display",
      WSWAN_ROTATE_DISPLAY_LABEL_VN,
      NULL,
      WSWAN_ROTATE_DISPLAY_INFO_0_VN,
      NULL,
      NULL,
      {
         { "manual",    OPTION_VAL_MANUAL_VN },
         { "landscape", OPTION_VAL_LANDSCAPE_VN },
         { "portrait",  OPTION_VAL_PORTRAIT_VN },
         { NULL, NULL },
      },
      "manual",
   },
   {
      "wswan_rotate_keymap",
      WSWAN_ROTATE_KEYMAP_LABEL_VN,
      NULL,
      WSWAN_ROTATE_KEYMAP_INFO_0_VN,
      NULL,
      NULL,
      {
         { "auto",     OPTION_VAL_AUTO_VN },
         { "disabled", OPTION_VAL_LANDSCAPE_VN },
         { "enabled",  OPTION_VAL_PORTRAIT_VN },
         { NULL, NULL},
      },
      "auto",
   },
   {
      "wswan_mono_palette",
      WSWAN_MONO_PALETTE_LABEL_VN,
      NULL,
      WSWAN_MONO_PALETTE_INFO_0_VN,
      NULL,
      NULL,
      {
         { "default",                OPTION_VAL_DEFAULT_VN },
         { "wonderswan",             OPTION_VAL_WONDERSWAN_VN },
         { "wondeswan_color",        OPTION_VAL_WONDESWAN_COLOR_VN },
         { "swancrystal",            OPTION_VAL_SWANCRYSTAL_VN },
         { "gb_dmg",                 OPTION_VAL_GB_DMG_VN },
         { "gb_pocket",              OPTION_VAL_GB_POCKET_VN },
         { "gb_light",               OPTION_VAL_GB_LIGHT_VN },
         { "blossom_pink",           OPTION_VAL_BLOSSOM_PINK_VN },
         { "bubbles_blue",           OPTION_VAL_BUBBLES_BLUE_VN },
         { "buttercup_green",        OPTION_VAL_BUTTERCUP_GREEN_VN },
         { "digivice",               OPTION_VAL_DIGIVICE_VN },
         { "game_com",               OPTION_VAL_GAME_COM_VN },
         { "gameking",               OPTION_VAL_GAMEKING_VN },
         { "game_master",            OPTION_VAL_GAME_MASTER_VN },
         { "golden_wild",            OPTION_VAL_GOLDEN_WILD_VN },
         { "greenscale",             OPTION_VAL_GREENSCALE_VN },
         { "hokage_orange",          OPTION_VAL_HOKAGE_ORANGE_VN },
         { "labo_fawn",              OPTION_VAL_LABO_FAWN_VN },
         { "legendary_super_saiyan", OPTION_VAL_LEGENDARY_SUPER_SAIYAN_VN },
         { "microvision",            OPTION_VAL_MICROVISION_VN },
         { "million_live_gold",      OPTION_VAL_MILLION_LIVE_GOLD_VN },
         { "odyssey_gold",           OPTION_VAL_ODYSSEY_GOLD_VN },
         { "shiny_sky_blue",         OPTION_VAL_SHINY_SKY_BLUE_VN },
         { "slime_blue",             OPTION_VAL_SLIME_BLUE_VN },
         { "ti_83",                  OPTION_VAL_TI_83_VN },
         { "travel_wood",            OPTION_VAL_TRAVEL_WOOD_VN },
         { "virtual_boy",            OPTION_VAL_VIRTUAL_BOY_VN },
         { NULL, NULL },
      },
      "default"
   },
   {
      "wswan_gfx_colors",
      WSWAN_GFX_COLORS_LABEL_VN,
      NULL,
      WSWAN_GFX_COLORS_INFO_0_VN,
      NULL,
      NULL,
      {
         { "16bit", OPTION_VAL_16BIT_VN },
         { "24bit", OPTION_VAL_24BIT_VN },
         { NULL, NULL },
      },
      "16bit"
   },
   {
      "wswan_frameskip",
      WSWAN_FRAMESKIP_LABEL_VN,
      NULL,
      WSWAN_FRAMESKIP_INFO_0_VN,
      NULL,
      NULL,
      {
         { "disabled", NULL },
         { "auto",     OPTION_VAL_AUTO_VN },
         { "manual",   OPTION_VAL_MANUAL_VN },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "wswan_frameskip_threshold",
      WSWAN_FRAMESKIP_THRESHOLD_LABEL_VN,
      NULL,
      WSWAN_FRAMESKIP_THRESHOLD_INFO_0_VN,
      NULL,
      NULL,
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "wswan_sound_sample_rate",
      WSWAN_SOUND_SAMPLE_RATE_LABEL_VN,
      NULL,
      WSWAN_SOUND_SAMPLE_RATE_INFO_0_VN,
      NULL,
      NULL,
      {
         { "11025",  NULL },
         { "22050",  NULL },
         { "44100",  NULL },
         { "48000",  NULL },
         { "96000",  NULL },
         { "192000", NULL },
         { "384000", NULL },
         { NULL, NULL },
      },
      "44100",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};
struct retro_core_options_v2 options_vn = {
   option_cats_vn,
   option_defs_vn
};


#ifdef __cplusplus
}
#endif

#endif
