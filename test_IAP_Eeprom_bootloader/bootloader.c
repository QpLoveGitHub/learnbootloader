#include <reg52.h>
#include "bootloader.h"
#include "uart_stc89c52rc.h"
#include "test.h"
#include "delay.h"

#define APP_START_ADDR 0x0a00

int main()
{
	Uart_RT_Init();
	test_printf(0,"bootloader start!\r\n");
	
	((void (code *) (void)) APP_START_ADDR)();
}