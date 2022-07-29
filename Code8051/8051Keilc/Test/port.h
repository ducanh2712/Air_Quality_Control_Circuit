#ifndef _PORT_H_
#define _PORT_H_

//Khai bao ket noi voi LCD
#define LCD_DATA P0

sbit RS=P1^2;
sbit RW=P1^1;
sbit EN=P1^0;

//Khai bao ket noi voi DHT11
sbit DHT11=P3^4; 

//Khai bao ket noi voi MQ05
sbit MQ05=P3^5;

//Khai bao ket noi voi ADC0804
#define ADC0804_DATA P2

sbit ADC0804_CS = P1^3;
sbit ADC0804_RD = P1^4;
sbit ADC0804_WR = P1^5;
sbit ADC0804_INTR = P3^3;

//Khai bao ket noi UART
sbit UART_RX = P3^0;
sbit UART_TX = P3^1;

//Khai bao ket noi voi GP2Y1010AU0F
sbit LED_GPMY = P3^6;

//Khai bao chan ngat tat den LCD
sbit LED_LCD = P3^7; 
sbit INT_LCD = P3^3; 

#endif