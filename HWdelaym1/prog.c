#include <REG51.H>
sbit LED=P1^0;
void delay()
{
	TH0=0x00;
	TL0=0x00;
	TR0=1;
	//while((TH0<=0xB4) && (TL0<=0x03));
	while(TL0<=0x03)
	{
		while(TH0<=0xB4);
		TR0=0;
	}
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