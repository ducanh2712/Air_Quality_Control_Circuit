#include <reg51.h>
#include "delay.h"



void delay_ms(unsigned int count)  /* Function to provide delay Approx 1ms */
{
	int i;
	for(i=0;i<count;i++)
	{
		timer_delay01us();
	}
}

void timer_delay01us()  /* Timer0 delay function */
{

 //TMOD = 0x01;
 //TH0 = 0xB8;  /* Load higher 8-bit in TH0 */
 //TL0 = 0x0C;  /* Load lower 8-bit in TL0 */
 //TR0 = 1;  /* Start timer0 */
 //while(TF0 == 0); /* Wait until timer0 flag set */
 //TR0 = 0;  /* Stop timer0 */
 //TF0 = 0;  /* Clear timer0 flag */
	
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0FCH
	MOV TL0, #018H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}

void timer_delay20ms()  /* Timer0 delay function */
{

 //TMOD = 0x01;
 //TH0 = 0xB8;  /* Load higher 8-bit in TH0 */
 //TL0 = 0x0C;  /* Load lower 8-bit in TL0 */
 //TR0 = 1;  /* Start timer0 */
 //while(TF0 == 0); /* Wait until timer0 flag set */
 //TR0 = 0;  /* Stop timer0 */
 //TF0 = 0;  /* Clear timer0 flag */
	
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0B1H
	MOV TL0, #0E0H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}

void timer_delay30us()  /* Timer0 delay function */
{
 //TMOD = 0x01;  /* Timer0 mode1 (16-bit timer mode) */
 //TH0 = 0xFF;  /* Load higher 8-bit in TH0 */
 //TL0 = 0xF1;  /* Load lower 8-bit in TL0 */
 //TR0 = 1;  /* Start timer0 */
 //while(TF0 == 0); /* Wait until timer0 flag set */
// TR0 = 0;  /* Stop timer0 */
// TF0 = 0;  /* Clear timer0 flag */
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0FFH
	MOV TL0, #0E2H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}

void timer_delay280us()  /* Timer0 delay function */
{
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0FEH
	MOV TL0, #0E8H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}


void timer_delay40us()  /* Timer0 delay function */
{
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0FFH
	MOV TL0, #0D8H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}


void timer_delay9680us()  /* Timer0 delay function */
{	
	#pragma asm
	MOV TMOD, #21H
	MOV TH0, #0DAH
	MOV TL0, #030H
	SETB TR0
	JNB TF0, $
	CLR TR0
	CLR TF0
	#pragma endasm
}