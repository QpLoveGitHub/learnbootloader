#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "uart_stc89c52rc.h"

void test_printf(unsigned char printFlags, const char *fmt, ...)
{
	va_list args;
	unsigned char length;
	char buf[40];
	
	va_start(args, fmt);
	length = vsprintf(buf, fmt, args);

    // auto test已经用了串口，故之前打印屏蔽 modify by kuan 2017年11月20日15:54:04
	SendUartMultiBytes((unsigned char *)buf, strlen(buf));
	
	va_end(args);
}


