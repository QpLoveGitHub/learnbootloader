#include "iap_eeprom.h"
#include "reg51.h"
#include "intrins.h"
#include "uart_stc89c52rc.h"
#include "delay.h"
#include "test.h"

sfr IAP_DATA = 0xe2;
sfr IAP_ADDRH = 0xe3;
sfr IAP_ADDRL = 0xe4;
sfr IAP_CMD = 0xe5;
sfr IAP_TRIG = 0xe6;
sfr IAP_CONTR = 0xe7;

void IapIdle(void)
{
	IAP_CONTR = 0;
	IAP_CMD = 0;
	IAP_TRIG = 0;
	IAP_ADDRH = 0x20;
	IAP_ADDRL = 0;	
}

BYTE IapReadByte(WORD addr)
{
	BYTE dat;

	IAP_CONTR = ENABLE_IAP;
	IAP_CMD = CMD_READ;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr >> 8;
	IAP_TRIG = 0x46;
	IAP_TRIG = 0xb9;
	_nop_();
	dat = IAP_DATA;
	IapIdle();

	return dat;
}

void IapProgramByte(WORD addr, BYTE dat)
{
	IAP_CONTR = ENABLE_IAP;
	IAP_CMD = CMD_PROGRAM;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr >> 8;
	IAP_DATA = dat;
	IAP_TRIG = 0x46;
	IAP_TRIG = 0xb9;
	_nop_();
}

void IapEraseSector(WORD addr)
{
	IAP_CONTR = ENABLE_IAP;
	IAP_CMD = CMD_ERASE;
	IAP_ADDRL = addr;
	IAP_ADDRH = addr >> 8;
	IAP_TRIG = 0x46;
	IAP_TRIG = 0xb9;
	_nop_();
	IapIdle();
}

 void Test_IapEepromFunction(void)
{
	WORD i;
	WORD tmp;
	P1 = 0xfe;
	delay_1ms(10);
#if 1
	IapEraseSector(IAP_ADDRESS);
	test_printf(0,"iapErase\r\n");
	delay_1ms(10);
	for(i=0;i<512;i++)
	{
		tmp = IapReadByte((IAP_ADDRESS + i));
		if(tmp != 0xff)
		{
			test_printf(0,"readerror cnt=%d tmp=%d\r\n",i,tmp);
			break;
		}
	}	

	delay_1ms(10);
	for(i=0;i<512;i++)
	{
		IapProgramByte(IAP_ADDRESS+i, (BYTE)(i+3));
	}
#endif
#if 1
	delay_1ms(10);
	for(i=0;i<512;i++)
	{
		tmp = IapReadByte(IAP_ADDRESS+i);
		test_printf(0,"readbyte cnt=%d tmp=%d\r\n",i,tmp);
		delay_1ms(100);
		if(tmp != (BYTE)(i+3))
		{
			test_printf(0,"read previous error,readbyte cnt=%d tmp=%d\r\n",i,tmp);
			break;
		}
	}
#endif
	test_printf(0,"Erase Success!\r\n");
}


