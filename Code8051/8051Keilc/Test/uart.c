#include <reg51.h>
#include "uart.h"
#include "port.h"
#include <stdio.h>

void Uart_Init()
{
		// Khoi tao UART o mode 1, 1200 baud
	SM0 = 0; SM1 = 1;		// Chon UART mode 1
	TMOD = 0x21;            // 0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	TH1 = 0xE6;				// Toc do baud 1200
	TR1 = 1;				// Timer1 bat dau chay
	TI = 1;					// San sang gui du lieu
}

void Uart_Write(char c)
{
	SBUF = c;
 	while(TI == 0);
	TI = 0;
	
	
}

void Uart_Write_Text(char * str)
{
	unsigned char i = 0;
 	while(str[i]!=0)
	{
		Uart_Write(str[i]);
		i++;
	}
}

char Uart_Data_Ready()
{
	return RI;
}

char Uart_Read()
{
	RI = 0;
	return SBUF;
}