// -------------Relay ,Buzzer, LED Program---------------//


#include<P18f4550.h>
#define lrbit PORTAbits.RA2
#define rlbit PORTAbits.RA3
#define buzzer PORTAbits.RA5
#define relay PORTAbits.RA4
//Function Definitions
voidmsdelay (unsigned int time)//Function for delay
{
unsignedint i, j;
for (i = 0; i < time; i++)
 {
​for (j = 0; j < 275; j++);​//Calibrated for a 1 ms delay in MPLAB
}
}
void main()
{
unsigned char val=0;
    INTCON2bits.RBPU=0;
    ADCON1=0x0F;                 //set pins as digital
    TRISAbits.TRISA2=1;          //set RA2 as input (SW1=lrbits)
     TRISAbits.TRISA3=1;         //set RA3 as input (SW2=rlbits)
     TRISAbits.TRISA5=0;         // set Buzzer pin RA5 as output
     TRISAbits.TRISA4=0;         // set Relay pin RA4 as output
     TRISB=0x00;                 //PortB as output
     PORTB=0x00;
buzzer=0;
relay=0;
while(1)
     {
if(!(lrbit))                          //To check whether SW1 is pressed
val=1;
if (!(rlbit))​​​​//To check whether SW2 is pressed
​​val = 2;
​if (val == 1)
​   {
​​buzzer = 1;           //Buzzer ON
​​relay = 1;            //Relay ON
​​PORTB = PORTB >>1;  ​//Shift left by 1 bit
​​if (PORTB == 0x00)
​​PORTB = 0x80; ​​// Make the MSB bit equal to 1
​​msdelay(250);
​   }
​if (val == 2)
​   {​​buzzer = 0;             //Buzzer OFF
​​relay = 0;              //Relay OFF
​​PORTB = PORTB<<1;    ​//Shift right by 1 bit
​​if (PORTB == 0x00)
​​​PORTB = 0x01;  ​​// Make the LSB bit eqaul to 1
​​msdelay(250);
​   }
    }
}           //End of the Program


