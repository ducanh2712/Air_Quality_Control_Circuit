#include <reg51.h>
#include "interrupt.h"
#include "port.h"

void INT_Init()
{	
	IT1 = 1;
	EX1 = 1;
	EA = 1;
}