//---------------BCD counter----------------//
#include<reg51.h>
void delay();
void main()
{
int i;
while(1)
{
for(i=0;i<10;i++)
{
P2=i;
delay();
}
}
}
void delay()
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

