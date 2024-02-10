#include <REG51.H>
sbit led=P1^0;
void delay()
{
	TMOD=0x02;
	TH0=0xA3;
	TL0=0xA3;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
}
void main()
{
	while(1){
		led=~led;
		delay();
	}
}