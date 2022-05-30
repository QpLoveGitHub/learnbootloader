/*Include Files*/
#include <reg52.h>
#include "uart_stc89c52rc.h"
#include "delay.h"
#include "type.h"
#include "iap_eeprom.h"
#include "test.h"

/*Macros*/
#define VERSION_STRING "test_IAP_Eeprom v0,2022.5.30\r\n"

/*Function prototypes*/

int main(void)
{
	Uart_RT_Init();
	SendUartMultiBytes(VERSION_STRING,sizeof(VERSION_STRING));
	test_printf(0,"123\r\n");

#if 1
	Test_IapEepromFunction();
#endif

	while(1)
	{
		delay_1ms(1000);
		//SendUartOneByte('w');
		//SendUartMultiBytes(VERSION_STRING,sizeof(VERSION_STRING));
	}
}