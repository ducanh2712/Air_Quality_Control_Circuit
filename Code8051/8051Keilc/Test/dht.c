#include <reg51.h>
#include "dht.h"
#include "port.h"
#include "delay.h"


void Request()   /* Microcontroller send request */
{
 DHT11 = 0;  /* set to low pin */
 timer_delay20ms(); /* wait for 20ms */
 DHT11 = 1;  /* set to high pin */
}

void Response()   /* Receive response from DHT11 */
{
 while(DHT11==1);
 while(DHT11==0);
 while(DHT11==1);
}

int Receive_data()  /* Receive data */
{
 int q,c=0; 
 for (q=0; q<8; q++)
 {
  while(DHT11==0);/* check received bit 0 or 1 */
  timer_delay30us();
  if(DHT11 == 1) /* If high pulse is greater than 30ms */
  c = (c<<1)|(0x01);/* Then its logic HIGH */
  else  /* otherwise its logic LOW */
  c = (c<<1);
  while(DHT11==1);
 }

 return c;
}