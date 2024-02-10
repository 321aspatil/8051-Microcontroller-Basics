#include <REG51.H>
sbit LED_RI = P1^0;
sbit LED_TI = P1^1;
void ser_isr(void) interrupt 4
{	 unsigned char mybyte; 
	  if(RI==1)
		{
			mybyte = SBUF;
			SBUF = mybyte;
			LED_RI = ~LED_RI;
			RI = 0;	
		}
	if(TI==1)
		{
			LED_TI = ~LED_TI;
			TI = 0;
		}
}
void main(void)
{
	LED_RI = 0;
	LED_TI = 1;
	IE = 0X90;
	TMOD = 0x20;
	TH1 = 0xFA;
	SCON = 0x50;
	TR1 = 1;
  while(1);
}
