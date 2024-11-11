//----------------squar wave pic timer ------------------//


 /*CALCULATIONS
* required time = 100ms Fosc=48Mhz
* TMR value = 0xFFFF - (required time) / (4 * Tosc * Prescaler)
* = 0xFFFF - (0.1 * 48000000) / (4 * 256)
* = 0xFFFF - 0x124F
* TMR = 0xEDB0
* TMRH = 0xED
* TMRL = 0xB0
*/
#include <p18f4550.h>
 
void interrupt timer_isr(void)
{
​if(TMR0IF == 1)                         //If timer0 interrupt flag is set.....
    {
      TMR0ON = 0;                           // Stop the timer
      TMR0IF = 0;                           //Clear the interrupt flag
      TMR0H = 0xED;                         //Reload Timer0
      TMR0L = 0xB0;
      LATB =~LATB;                          //Toggle PORTB
      TMR0ON = 1;                           // Start the timer
    }
}
 
void main()
{
​ADCON1 = 0x0F;        //Configuring the PORTE pins as digital I/O
​TRISB = 0;                  //Configruing the LED port pins as outputs
​LATB = 0xFF;                //Setting the initial value of the LED's after reset
​T0CON = 0x07;​//Set the timer to 16-bit mode,internal instruction cycle clock,1:256 prescaler
​TMR0H = 0xED;                // Reset Timer0 to 0x48E5 TO MAKE DELAY OF 1 SECOND
​TMR0L = 0xB0;
​INTCONbits.TMR0IF = 0;      // Clear Timer0 overflow flag
​INTCONbits.TMR0IE = 1;​​// TMR0 interrupt enabled
​T0CONbits.TMR0ON = 1;​​// Start timer0
​INTCONbits.GIE = 1;​​​// Global interrupt enabled
​while(1);      //Program execution stays here until the timer overflow interrupt is generated
}
 