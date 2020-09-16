#ifndef __WSWAN_EEPROM_H
#define __WSWAN_EEPROM_H

#include <stdint.h>

#include "../state.h"

uint8_t WSwan_EEPROMRead(uint32_t A);
void WSwan_EEPROMWrite(uint32_t A, uint8_t V);
int WSwan_EEPROMStateAction(StateMem *sm, int load, int data_only);
void WSwan_EEPROMReset(void);
void WSwan_EEPROMInit(const char *Name, const uint16_t BYear, const uint8_t BMonth, const uint8_t BDay, const uint8_t Sex, const uint8_t Blood);

#endif
