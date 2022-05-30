#ifndef __IAP_EEPROM_H
#define __IAP_EEPROM_H
#include "type.h"
#define CMD_IDLE 0
#define CMD_READ 1
#define CMD_PROGRAM 2
#define CMD_ERASE 3

#define ENABLE_IAP 0x81
#define IAP_ADDRESS 0x02000

//extern  void Delay(Byte n);
void IapIdle(void);
BYTE IapReadByte(WORD addr);
void IapProgramByte(WORD addr,BYTE dat);
void IapEraseSector(WORD addr);

extern void Test_IapEepromFunction(void);

#endif
