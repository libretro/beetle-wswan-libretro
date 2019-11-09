/******************************************************************************/
/* Mednafen - Multi-system Emulator                                           */
/******************************************************************************/
/* rtc.cpp - WonderSwan RTC Emulation
**  Copyright (C) 2014-2016 Mednafen Team
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*
 RTC utilizing games:
	Dicing Knight
	Dokodemo Hamster 3
	Inuyasha - Kagome no Sengoku Nikki
*/

#include "wswan.h"
#include <time.h>

static uint32 ClockCycleCounter;

static uint8 Command;
static uint8 CommandBuffer[7];
static uint8 CommandIndex;
static uint8 CommandCount;

struct GenericRTC
{
   uint8 sec;
   uint8 min;
   uint8 hour;
   uint8 wday;
   uint8 mday;
   uint8 mon;
   uint8 year;
};

static GenericRTC RTC = { 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00 };


static bool GenericRTC_BCDInc(uint8 &V, uint8 thresh, uint8 reset_val = 0x00)
{
   V = ((V + 1) & 0x0F) | (V & 0xF0);
   if((V & 0x0F) >= 0x0A)
   {
      V &= 0xF0;
      V += 0x10;

      if((V & 0xF0) >= 0xA0)
      {
         V &= 0x0F;
      }
   }

   if(V >= thresh)
   {
      V = reset_val;

      return(true);
   }

   return(false);
}

static void GenericRTC_Init(const struct tm& toom)
{
   RTC.sec = U8_to_BCD(toom.tm_sec);
   RTC.min = U8_to_BCD(toom.tm_min);
   RTC.hour = U8_to_BCD(toom.tm_hour);
   RTC.wday = U8_to_BCD(toom.tm_wday);
   RTC.mday = U8_to_BCD(toom.tm_mday);
   RTC.mon = U8_to_BCD(toom.tm_mon);
   RTC.year = U8_to_BCD(toom.tm_year % 100);

   if(RTC.sec >= 0x60)	// Murder the leap second.
      RTC.sec = 0x59;
}

static void GenericRTC_Clock(void)
{
   if(GenericRTC_BCDInc(RTC.sec, 0x60))
   {
      if(GenericRTC_BCDInc(RTC.min, 0x60))
      {
         if(GenericRTC_BCDInc(RTC.hour, 0x24))
         {
            uint8 mday_thresh = 0x32;

            if(RTC.mon == 0x01)
            {
               mday_thresh = 0x29;

               if(((RTC.year & 0x0F) % 4) == ((RTC.year & 0x10) ? 0x02 : 0x00))
                  mday_thresh = 0x30;
            }
            else if(RTC.mon == 0x03 || RTC.mon == 0x05 || RTC.mon == 0x08 || RTC.mon == 0x10)
               mday_thresh = 0x31;

            GenericRTC_BCDInc(RTC.wday, 0x07);

            if(GenericRTC_BCDInc(RTC.mday, mday_thresh, 0x01))
            {
               if(GenericRTC_BCDInc(RTC.mon, 0x12))
               {
                  GenericRTC_BCDInc(RTC.year, 0xA0);
               }
            }
         }
      }
   }
}

void RTC_Write(uint8 A, uint8 V)
{
   //printf("RTC Write: %02x %02x\n", A, V);

   if(A == 0xCA)
   {
      Command = V & 0x1F;

      if(Command == 0x15)
      {
         CommandBuffer[0] = RTC.year;
         CommandBuffer[1] = RTC.mon;
         CommandBuffer[2] = RTC.mday;
         CommandBuffer[3] = RTC.wday;
         CommandBuffer[4] = RTC.hour;
         CommandBuffer[5] = RTC.min;
         CommandBuffer[6] = RTC.sec;

         CommandIndex = 0;
         CommandCount = 7;
      }
      else if(Command == 0x14)
      {
         CommandIndex = 0;
         CommandCount = 7;
      }
      else if(Command == 0x13)
      {
         //CommandIndex = 0;
      }
   }
   else if(A == 0xCB)
   {
      if(Command == 0x14)
      {
         if(CommandIndex < CommandCount)
         {
            CommandBuffer[CommandIndex++] = V;
            if(CommandIndex == CommandCount)
            {
               //printf("Program time\n");
               //for(int i = 0; i < CommandCount; i++)
               // printf("%d: %02x\n", i, CommandBuffer[i]);
               //abort();
            #if 0
               RTC.year = CommandBuffer[0];
               RTC.mon = CommandBuffer[1];
               RTC.mday = CommandBuffer[2];
               RTC.wday = CommandBuffer[3];
               RTC.hour = CommandBuffer[4];
               RTC.min = CommandBuffer[5];
               RTC.sec = CommandBuffer[6];

               printf("WDAY: %02x\n", RTC.wday);
            #endif
            }
         }
      }
   }
}

uint8 RTC_Read(uint8 A)
{
   uint8 ret = 0;

   if(A == 0xCA)
   {
      ret = Command | 0x80;
   }
   else if(A == 0xCB)
   {
      ret = 0x80;

      if(Command == 0x15)
      {
         if(CommandIndex < CommandCount)
         {
            ret = CommandBuffer[CommandIndex];

            if(!WS_InDebug)
               CommandIndex++;
         }
      }
   }

   // printf("RTC Read: %02x %02x\n", A, ret);

   return(ret);
}

void RTC_Clock(uint32 cycles)
{
   ClockCycleCounter += cycles;

   while(ClockCycleCounter >= 3072000)
   {
      ClockCycleCounter -= 3072000;
      GenericRTC_Clock();
   }
}

void RTC_Init(void)
{
   struct tm *localTime;
   time_t long_time;

   //Get the system time
   time(&long_time);
   localTime = localtime(&long_time);

   if (localTime)
      GenericRTC_Init(*localTime);

   ClockCycleCounter = 0;

#if 0
   {
      GenericRTC rtc_a, rtc_b;
      time_t ct = 0; //947000000; //time(NULL);

      rtc_a.Init(ct);

      while(ct < INT_MAX)
      {
         rtc_b.Init(ct);

         if(memcmp(&rtc_a, &rtc_b, sizeof(GenericRTC)))
         {
            printf("%02x:%02x:%02x-%02x:%02x:%02x      %02x:%02x:%02x-%02x:%02x:%02x\n", rtc_a.year, rtc_a.mon, rtc_a.mday, rtc_a.hour, rtc_a.min, rtc_a.sec,
                                                                                         rtc_b.year, rtc_b.mon, rtc_b.mday, rtc_b.hour, rtc_b.min, rtc_b.sec);
            abort();
         }

         rtc_a.Clock();
         ct++;
      }
   }
#endif
}

void RTC_Reset(void)
{
   Command = 0x00;
}

int RTC_StateAction(StateMem *sm, const unsigned load, const bool data_only)
{
   SFORMAT StateRegs[] =
   {
      SFVAR(RTC.sec),
      SFVAR(RTC.min),
      SFVAR(RTC.hour),
      SFVAR(RTC.wday),
      SFVAR(RTC.mday),
      SFVAR(RTC.mon),
      SFVAR(RTC.year),

      SFVAR(ClockCycleCounter),

      SFVAR(Command),
      SFVAR(CommandBuffer),
      SFVAR(CommandCount),
      SFVAR(CommandIndex),
      SFEND
   };

   if(!MDFNSS_StateAction(sm, load, data_only, StateRegs, "RTC", false))
      return(0);

   if(load)
   {

   }

   return(1);
}
