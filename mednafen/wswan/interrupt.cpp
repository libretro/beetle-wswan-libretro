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

#include "wswan.h"
#include "interrupt.h"
#include "v30mz.h"

static const uint8 LevelTriggeredMask = (1U << WSINT_SERIAL_RECV);

static uint8 IAsserted;
static uint8 IStatus;
static uint8 IEnable;
static uint8 IVectorBase;

static bool IOn_Cache;
static uint32 IOn_Which;
static uint32 IVector_Cache;

static void RecalcInterrupt(void)
{
   IStatus |= (IAsserted & LevelTriggeredMask) & IEnable;

   IOn_Cache = false;
   IOn_Which = 0;
   IVector_Cache = 0;

   for(int i = 0; i < 8; i++)
   {
      if(IStatus & IEnable & (1U << i))
      {
         IOn_Cache = true;
         IOn_Which = i;
         IVector_Cache = (IVectorBase + i) * 4;
         break;
      }
   }
}

void WSwan_InterruptDebugForce(unsigned int level)
{
   v30mz_int((IVectorBase + level) * 4, true);
}

void WSwan_InterruptAssert(unsigned which, bool asserted)
{
   const uint8 prev_IAsserted = IAsserted;

   IAsserted &= ~(1U << which);
   IAsserted |= (unsigned)asserted << which;

   IStatus |= ((prev_IAsserted ^ IAsserted) & IAsserted) & IEnable;

   RecalcInterrupt();
}

void WSwan_Interrupt(unsigned which)
{
   IStatus |= (1U << which) & IEnable;
   RecalcInterrupt();
}

void WSwan_InterruptWrite(uint32 A, uint8 V)
{
   //printf("Write: %04x %02x\n", A, V);
   switch(A)
   {
      case 0xB0: IVectorBase = V;
                 RecalcInterrupt();
                 break;

      case 0xB2: IEnable = V;
                 IStatus &= IEnable;
                 RecalcInterrupt();
                 break;

      case 0xB6: /*printf("IStatus: %02x\n", V);*/
                 IStatus &= ~V;
                 RecalcInterrupt();
                 break;
   }
}

uint8 WSwan_InterruptRead(uint32 A)
{
   //printf("Read: %04x\n", A);
   switch(A)
   {
      case 0xB0: return(IVectorBase);
      case 0xB2: return(IEnable);
      case 0xB6: return(1 << IOn_Which); //return(IStatus);
   }
   return (0);
}

void WSwan_InterruptCheck(void)
{
   if(IOn_Cache)
   {
      v30mz_int(IVector_Cache, false);
   }
}

void WSwan_InterruptReset(void)
{
   IAsserted = 0x00;
   IEnable = 0x00;
   IStatus = 0x00;
   IVectorBase = 0x00;
   RecalcInterrupt();
}

int WSwan_InterruptStateAction(StateMem *sm, const unsigned load, const bool data_only)
{
   SFORMAT StateRegs[] =
   {
      SFVAR(IAsserted),
      SFVAR(IStatus),
      SFVAR(IEnable),
      SFVAR(IVectorBase),
      SFEND
   };

   if(!MDFNSS_StateAction(sm, load, data_only, StateRegs, "INTR", false))
      return(0);

   if(load)
   {
      if(load < 0x0936)
         IAsserted = 0;

      RecalcInterrupt();
   }

   return(1);
}
