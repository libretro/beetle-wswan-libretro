#ifndef __MDFN_MEMPATCHER_H
#define __MDFN_MEMPATCHER_H

#include "mempatcher-driver.h"

typedef struct __SUBCHEAT
{
	uint32 addr;
	uint8 value;
	int compare; // < 0 on no compare
} SUBCHEAT;

extern bool SubCheatsOn;

#ifdef __cplusplus
extern "C" {
#endif

void MDFNMP_Kill(void);

void MDFNMP_ApplyPeriodicCheats(void);

void MDFNMP_InstallReadPatches(void);

bool MDFNMP_Init(uint32 ps, uint32 numpages);

void MDFNMP_AddRAM(uint32 size, uint32 address, uint8 *RAM);

#ifdef __cplusplus
}
#endif

void MDFNMP_RemoveReadPatches(void);


#endif
