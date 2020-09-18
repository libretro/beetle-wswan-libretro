#ifndef _MEDNAFEN_H
#define _MEDNAFEN_H

#include <stdlib.h>
#include <string.h>

#include "git.h"
#include "mednafen-types.h"
#include "settings.h"

extern MDFNGI EmulatedWSwan;

void MDFN_LoadGameCheats(void *override);
void MDFN_FlushGameCheats(int nosave);

void MDFN_MidSync(EmulateSpecStruct *espec);
void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y);

#endif
