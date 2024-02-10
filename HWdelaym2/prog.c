#include <REG51.H>
sbit LED=P1^0;
void delay()
{
	TH0=0x4B;
	TL0=0xFC;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}
void main()
{
	TMOD=0x01;
	while(1)
	{
		LED=0;
		delay();
		LED=1;
		delay();
	}
}