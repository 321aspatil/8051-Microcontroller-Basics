#include <REG51.H>
void main()
{
	unsigned char mybyte;
	TMOD=0x20;
	TH1=0xFA;
	SCON=0x50;
	TR1=1;
	while(1)
	{
		while(RI==0);
		mybyte=SBUF;
		RI=0;
		SBUF=mybyte;
		while(TI==0);
		TI=0;
	}
}