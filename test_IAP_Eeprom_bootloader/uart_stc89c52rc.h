#ifndef __UART_STC89C52RC_H
#define __UART_STC89C52RC_H

extern void Uart_RT_Init(void);
extern void SendUartOneByte(unsigned char byte_to_send);
extern void SendUartMultiBytes(unsigned char *p_multiBytes,unsigned char len);

#endif