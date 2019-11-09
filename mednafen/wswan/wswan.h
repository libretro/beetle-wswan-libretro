#ifndef __WSWAN_H
#define __WSWAN_H

#include "mednafen/mednafen.h"
#include "mednafen/state.h"

#include "interrupt.h"

#ifndef MAX
   #define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef MIN
   #define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#define mBCD(value) (((value)/10)<<4)|((value)%10)

static INLINE uint8 U8_to_BCD(uint8 num)	
{	
   return( ((num / 10) << 4) + (num % 10) );	
}
	 
extern uint32 WS_InDebug;
extern uint32 rom_size;
extern uint32 SRAMSize;
extern int wsc;

enum
{
   WSWAN_SEX_MALE = 1,
   WSWAN_SEX_FEMALE = 2
};

enum
{
   WSWAN_BLOOD_A = 1,
   WSWAN_BLOOD_B = 2,
   WSWAN_BLOOD_O = 3,
   WSWAN_BLOOD_AB = 4
};

extern int StateAction(StateMem *sm, const unsigned load, const bool data_only);

#endif
