#include <REG51.H>
sbit pin=P1^0;
sfr DATA = 0xA0;

unsigned char msg[4]={0x76,0X79,0X38,0X73};
void delay()
{
	int i;
	for(i=0;i<10;i++){
	TH0=0x4F;
	TL0=0xBD;
	TR0=1;
	pin=~pin;
	while(TF0==0);
	TF0=0;
	TR0=1;
	}
}
void main()
{
	TMOD=0x01;
	while(1)
	{
		P3 = 0x1E;
		DATA = msg[0];
		delay();
		
		P3 = 0x1D;
		DATA = msg[1];
		delay();
		
		P3 = 0x1B;
		DATA = msg[2];
		delay();
		
		P3 = 0x17;
		DATA = msg[3];
		delay();
		
		P3 = 0x0F;
		DATA = msg[3];
		delay();
	}
}