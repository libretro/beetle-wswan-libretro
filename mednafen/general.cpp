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
#include <stdarg.h>

#include <sys/types.h>

#include <string>

#include "general.h"
#include "state.h"

using namespace std;

static bool IsAbsolutePath(const char *path)
{
   if (
#ifdef _WIN32
         path[0] == '\\' ||
#endif
         path[0] == '/'
      )
         return(true);

 #if defined(WIN32) || defined(DOS)
 if((path[0] >= 'a' && path[0] <= 'z') || (path[0] >= 'A' && path[0] <= 'Z'))
 {
    if(path[1] == ':')
       return(true);
 }
 #endif

 return(false);
}

static bool IsAbsolutePath(const std::string &path)
{
 return(IsAbsolutePath(path.c_str()));
}

void MDFN_GetFilePathComponents(const std::string &file_path, 
      std::string *dir_path_out, std::string *file_base_out, 
      std::string *file_ext_out)
{
 size_t final_ds;		                  // in file_path
 string file_name;
 size_t fn_final_dot;		            // in local var file_name
 string dir_path, file_base, file_ext; // Temporary output

#ifdef _WIN32
 final_ds = file_path.find_last_of('\\');

 size_t alt_final_ds = file_path.find_last_of('/');

 if(final_ds == string::npos || (alt_final_ds != string::npos && alt_final_ds > final_ds))
    final_ds = alt_final_ds;
#else
 final_ds = file_path.find_last_of('/');
#endif

 if(final_ds == string::npos)
 {
  dir_path = string(".");
  file_name = file_path;
 }
 else
 {
  dir_path = file_path.substr(0, final_ds);
  file_name = file_path.substr(final_ds + 1);
 }

 fn_final_dot = file_name.find_last_of('.');

 if(fn_final_dot != string::npos)
 {
  file_base = file_name.substr(0, fn_final_dot);
  file_ext = file_name.substr(fn_final_dot);
 }
 else
 {
  file_base = file_name;
  file_ext = string("");
 }

 if(dir_path_out)
  *dir_path_out = dir_path;

 if(file_base_out)
  *file_base_out = file_base;

 if(file_ext_out)
  *file_ext_out = file_ext;
}

std::string MDFN_EvalFIP(const std::string &dir_path, const std::string &rel_path, bool skip_safety_check)
{
   char slash;
#ifdef _WIN32
   slash = '\\';
#else
   slash = '/';
#endif

   if(IsAbsolutePath(rel_path.c_str()))
      return(rel_path);
   return(dir_path + slash + rel_path);
}

const char * GetFNComponent(const char *str)
{
   const char *tp1;

#ifdef _WIN32
   tp1 = ((char *)strrchr(str,'\\'));

   const char *tp3;

   tp3 = ((char *)strrchr(str,'/'));

   if (tp1<tp3)
      tp1 = tp3;
#else
   tp1 = ((char *)strrchr(str,'/'));
#endif

   if (tp1)
      return (tp1+1);
   else
      return (str);
}
