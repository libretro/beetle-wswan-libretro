#ifndef MDFN_SETTINGS_H
#define MDFN_SETTINGS_H

#include <string>

uint64 MDFN_GetSettingUI(const char *name);
int64 MDFN_GetSettingI(const char *name);
bool MDFN_GetSettingB(const char *name);
std::string MDFN_GetSettingS(const char *name);
#endif
