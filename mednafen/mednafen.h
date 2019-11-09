#ifndef _MEDNAFEN_H
#define _MEDNAFEN_H

#include "mednafen-types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "git.h"

extern MDFNGI *MDFNGameInfo;

#include "settings.h"

void MDFN_LoadGameCheats(void *override);
void MDFN_FlushGameCheats(int nosave);

void MDFN_MidSync(EmulateSpecStruct *espec);
void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y);

#include "mednafen-driver.h"
#include "mempatcher.h"
#include "general.h"
#include "mednafen-endian.h"

extern void MDFN_PrintError(const char *format, ...);
extern void MDFN_Notify(const char *format, ...);
extern void MDFN_Error(const char *format, ...);
extern void MDFN_printf(const char *format, ...);

#endif
