// ------------------lcd   to pic microcontroller------------------//
#include <P18F4550.h>
 
void lcdcmd(unsigned char value);
 void lcddata(unsigned char value);
void MSDelay(unsigned int itime);
 
#define ldata PORTB    // PortB acts as 8 data lines
#define rs PORTAbits.RA0
#define en PORTAbits.RA1
 
void main()
{
TRISB = 0x00;
TRISAbits.TRISA0=0;
TRISAbits.TRISA1=0;
 
ADCON1 = 0x0F; // disable analog input
 en = 0;
MSDelay(250);
lcdcmd(0x38);//initialize LCD as 2row 16 col in 8bit mode
 MSDelay(250);
lcdcmd(0x0E);    // Increment curser
 MSDelay(15);
lcdcmd(0x01);    // Display On cursor blinking
MSDelay(15);
lcdcmd(0x06);    //Shift cursor right
 MSDelay(15);
lcdcmd(0xC0);    // Address of display
 MSDelay(15);
lcddata('P');    // character to display
MSDelay(15);
lcddata('C');    // character to display
MSDelay(15);
lcddata('C');    // character to display
MSDelay(15);
lcddata('O');    // character to display
MSDelay(15);
lcddata('E');    // character to display
MSDelay(15);
lcddata('R');    // character to display
MSDelay(15);
}
void lcdcmd(unsigned char value)
{
rs = 0;
ldata = value;
en = 1;
MSDelay(1);
en = 0;
}
 
void lcddata(unsigned char value)
{
rs = 1;
ldata = value;
en = 1;
 MSDelay(1);
 en = 0;
}
 
void MSDelay(unsigned int itime)
{
unsigned int i, j;
for(i=0;i<itime;i++)
{
 for(j=0;j<135;j++);
}
}
 