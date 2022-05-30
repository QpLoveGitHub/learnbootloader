#include "reg52.h"
#include "uart_stc89c52rc.h"
#include "test.h"
/*
Function Prototype: void Uart_RT_Init()
Entry Params: baud ,eg,9600,115200 etc,
Return Value:void
Author:
Time: 2022-5-14
description: config uart baudrate,enable uart interrupt
*/
void Uart_RT_Init(void)
{
  	//SCON = 0X50;
	SCON = 0xd0;
	TMOD &= 0X0F;
	TMOD |= 0X20;
	//TH1 = 220;
	//TL1 = 220;
	TH1 = 253;
	TL1 = 253;
	TR1 =1;
	ES = 1;
}

/*send one byte by uart*/
void SendUartOneByte(unsigned char byte_to_send)
{
	//TB8 = P;
	SBUF = byte_to_send;
	while(0 == TI);
	TI = 0;
}

void SendUartMultiBytes(unsigned char *p_multiBytes,unsigned char len)
{
	unsigned char i;
//	if(((void *)p_multiBytes == (void*)0) || (len == 0))
//	{
//		return;
//	}
	for(i=0;i<len;i++)
	{
		SendUartOneByte(p_multiBytes[i]);
	}
}





