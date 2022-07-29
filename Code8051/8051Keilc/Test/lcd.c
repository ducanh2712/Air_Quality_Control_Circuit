#include <reg51.h>
#include "lcd.h"
#include "port.h"
#include "delay.h"


void LCD_Command (unsigned char cmd) 
{
	LCD_DATA = cmd;
	RS=0;		
	RW=0;		
	EN=1; 
	delay_ms(1);
	EN=0;
	delay_ms(5);
}

void LCD_Char (unsigned char char_data) 
{
	LCD_DATA=char_data;
	RS=1;		
	RW=0;	
	EN=1;   				
	delay_ms(1);
	EN=0;
	delay_ms(5);
}

void LCD_String (unsigned char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);  
	}
}

void LCD_String_xy (char row, char pos, char *str) 
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + pos - 1;
	LCD_Command(cmd);
	LCD_String(str);
}

void LCD_Init ()	
{	
	LCD_Command(0x30);
	delay_ms(5);		
	LCD_Command(0x30);
	delay_ms(1);	
	LCD_Command(0x38);
	LCD_Command(0x01);
	LCD_Command(0x0C);
}