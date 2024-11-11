//--------------------LED flashing--------------------//
#include <reg51.h>
 my_delay()
 {
 TMOD=0x01;
TCON=0x50;
TL0=0x00;
TH0=0x00;
TR0=1;
while(TF0==0);
TF0=0;
TR0=0;
 }
 void main(void)
 {
 P1= 0X00;
 while(1)
 {
 P1 = 0X00;
 my_delay();
 P1 = 0xFF;
 my_delay();
 }
 }























