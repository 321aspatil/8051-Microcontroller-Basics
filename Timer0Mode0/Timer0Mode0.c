//NOC=1ms/1.08592us = 921
//max count of mode 0 is 8192
//8192-921=7271
//7271 in hex=0x1C67
//7271 in binary is 1 1100 0110 0111 ---->   1110 0011 0 0111  use this form to write the hex code in TH0 and TL0 
//Load TH0=0xE3 TL0= 0x07
#include <REG51.H>
sbit mybit=P1^5;
void TMODDelay()
{
	TMOD=0x00;
	TH0=0xE3;
	TL0=0x07;
	TR0=1;
	while(TF0==0);
	TF0=0;
	TR0=0;
}
void main()
{
	while(1)
	{
		mybit=~mybit;
		TMODDelay();
	}
}