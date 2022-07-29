#include <reg51.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "port.h"
#include "lcd.h"
#include "dht.h"
#include "delay.h"
#include "ADC0804.h"
#include "uart.h"

volatile int I_RH, D_RH, I_Temp, D_Temp, CheckSum;
volatile unsigned char dat[20];
volatile unsigned int adc_value_GPMY, voltage_GPMY, dustDensity;

sbit led = P2^0;

void get_DHT11();
void get_MQ05();
void get_GPMY();

void reverse(char *s){
  char * j;
  int c;
  j = s + strlen(s) - 1;
  while (s < j) {
    c = * s;
    * s++ = * j;
    * j-- = c;
  }
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) 
    n = -n; 
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0); 
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void main() {
	
	Uart_Init();
  
	LCD_Init();
  while (1) {
		volatile unsigned char dat[20];
		get_DHT11();
		get_MQ05();
		get_GPMY();
		delay_ms(1000);
    
  }
}

void get_DHT11() {
  Request();
  Response();

  I_RH = Receive_data();
  D_RH = Receive_data();
  I_Temp = Receive_data();
  D_Temp = Receive_data();
  CheckSum = Receive_data();
	
  if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum) {
		LCD_String_xy(1,1,"Error");
	}
  else{
		itoa(I_RH, dat);
		LCD_String_xy(1,1,"RH:");
		LCD_String(dat);
		itoa(I_Temp, dat);
		LCD_String(" T:");
		LCD_String(dat);
		itoa(I_RH/10, dat);
		Uart_Write_Text(dat);
    itoa(I_RH%10, dat);
    Uart_Write_Text(dat);
		itoa(I_Temp/10, dat);
    Uart_Write_Text(dat);
    itoa(I_Temp%10, dat);
    Uart_Write_Text(dat);
		delay_ms(500);	
  }
}

void get_GPMY() {
	
	LCD_String_xy(2,1,"Bui min:");
  LED_GPMY = 1;
  timer_delay280us();
  voltage_GPMY = ADC0804_Read();
  timer_delay40us();
  LED_GPMY = 0;
  timer_delay9680us();
	
	itoa(voltage_GPMY/100, dat);
	LCD_String(dat);
  Uart_Write_Text(dat);
	itoa((voltage_GPMY/10)%10, dat);
	LCD_String(dat);
	Uart_Write_Text(dat);
	itoa(voltage_GPMY%10, dat);
	LCD_String(dat);
	Uart_Write_Text(dat);
	delay_ms(500);
}

void get_MQ05() {
  if (MQ05)
	{
		LCD_String(" GAS:0");
		Uart_Write_Text("0");
	}
  else
	{
		LCD_String(" GAS:1");
		Uart_Write_Text("1");
	}
	delay_ms(500);
}
