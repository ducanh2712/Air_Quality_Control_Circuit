#ifndef _UART_H_
#define _UART_H_

void Uart_Init();
void Uart_Write(char c);
void Uart_Write_Text(char * str);
char Uart_Data_Ready();
char Uart_Read();

#endif