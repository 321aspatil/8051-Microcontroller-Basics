#include <REG51.H>
sbit LED=P1^0;
void timer0_isr() interrupt 1
{
	LED=~LED;
	TH0=0xDB;
	TL0=0xFF;
}
void main()
{
	LED=0;
	TMOD=0x01;
	IE=0x82;        // enable timer 0 interrupt  
	TR0 = 1;        // start timer  
	while (1); 	
}

