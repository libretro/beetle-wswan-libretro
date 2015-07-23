/* Mednafen - Multi-system Emulator
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

#include "mednafen.h"

#include <string.h>
#include	<stdarg.h>
#include	<errno.h>
#include	"include/trio/trio.h"
#include	<list>
#include	<algorithm>

#include	"general.h"

#include	"state.h"
#include "video.h"
#include	"file.h"

#include	"mempatcher.h"
#include	"md5.h"

#ifdef _MSC_VER
#include "msvc_compat.h"
#endif

extern MDFNGI EmulatedWSwan;
MDFNGI *MDFNGameInfo = &EmulatedWSwan;

MDFNGI *MDFNI_LoadGame(const char *force_module, const char *name)
{
   MDFNFILE GameFile;
	std::vector<FileExtensionSpecStruct> valid_iae;
   MDFNGameInfo = &EmulatedWSwan;

	// Construct a NULL-delimited list of known file extensions for MDFN_fopen()
   const FileExtensionSpecStruct *curexts = MDFNGameInfo->FileExtensions;

   while(curexts->extension && curexts->description)
   {
      valid_iae.push_back(*curexts);
      curexts++;
   }

	if(!GameFile.Open(name, &valid_iae[0], _("game")))
   {
      MDFNGameInfo = NULL;
      return 0;
   }

   if(MDFNGameInfo->Load(name, &GameFile) <= 0)
   {
      GameFile.Close();
      MDFNGameInfo = NULL;
      return(0);
   }

	MDFN_LoadGameCheats(NULL);
	MDFNMP_InstallReadPatches();

	if(!MDFNGameInfo->name)
   {
      unsigned int x;
      char *tmp;

      MDFNGameInfo->name = (UTF8 *)strdup(GetFNComponent(name));

      for(x=0;x<strlen((char *)MDFNGameInfo->name);x++)
      {
         if(MDFNGameInfo->name[x] == '_')
            MDFNGameInfo->name[x] = ' ';
      }
      if((tmp = strrchr((char *)MDFNGameInfo->name, '.')))
         *tmp = 0;
   }

   return(MDFNGameInfo);
}

void MDFNI_CloseGame(void)
{
   if(!MDFNGameInfo)
      return;

   MDFN_FlushGameCheats(0);

   MDFNGameInfo->CloseGame();

   if(MDFNGameInfo->name)
      free(MDFNGameInfo->name);
   MDFNGameInfo->name = NULL;

   MDFNMP_Kill();

   MDFNGameInfo = NULL;
}
