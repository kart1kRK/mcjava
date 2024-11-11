/*------------------7 Segment Display Code ---------------------*/
Interfacing Pins:
	A	->		P0.6
	B	->		P0.5
	C	->		P0.0
	D	->		P0.7
	E	->		P0.2
	F	->		P0.3
	G	->		P0.4
	Dp	->		P0.1
*/	
 #include <reg51.h>
void DELAY_ms(unsigned int ms_Count)
{     unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<100;j++);
    }
}
int main()
 {
    char seg_code[]={0x12,0xDE,0x0B,0x0E,0xC6,0x26,0x22,0x9E,0x02,0x06};
    int i;
    while (1) 
    {        for (i = 0; i <= 9; i++) // loop to display 0-9
        {
            P2 = seg_code[i]; 
            DELAY_ms(1000);
        }
    }
}


