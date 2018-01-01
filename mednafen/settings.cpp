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
#include <string>
#include "settings.h"

uint64 MDFN_GetSettingUI(const char *name)
{
   if (!strcmp("wswan.ocmultiplier", name))
      return 1;
   if (!strcmp("wswan.bday", name))
      return 23;
   if (!strcmp("wswan.bmonth", name))
      return 6;
   if (!strcmp("wswan.byear", name))
      return 1989;
   if (!strcmp("wswan.slstart", name))
      return 4;
   if (!strcmp("wswan.slend", name))
      return 235;

   return 0;
}

int64 MDFN_GetSettingI(const char *name)
{
   if (!strcmp("wswan.sex", name))
      return 0;
   if (!strcmp("wswan.blood", name))
      return 0;
   return 0;
}

bool MDFN_GetSettingB(const char *name)
{
   if (!strcmp("cheats", name))
      return 0;
   if (!strcmp("wswan.forcemono", name))
      return 0;
   if (!strcmp("wswan.language", name))
      return 1;
   if (!strcmp("wswan.correct_aspect", name))
      return 1;
   return 0;
}

std::string MDFN_GetSettingS(const char *name)
{
   if (!strcmp("wswan.name", name))
      return std::string("Mednafen");
   /* FILESYS */
   return 0;
}
