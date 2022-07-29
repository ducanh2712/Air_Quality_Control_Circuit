#include <reg51.h>
#include "ADC0804.h"
#include "port.h"

unsigned char ADC0804_Read()
{
	unsigned char kq;
	//Chon chip
	ADC0804_CS = 0;
	
	//Tao xung bat dau chuyen doi
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	//Doi chuyen doi xong
	while(ADC0804_INTR);
	
	//Doc gia tri
	ADC0804_RD = 0;
	kq = ADC0804_DATA;
	ADC0804_RD = 1;
	
	return kq;
}
	
	
