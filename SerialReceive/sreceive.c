#include <REG51.H>
/*void receive(){
	unsigned char rbyte;
	TH1=0xFA;
	SCON=0x50;//mode 1 with reception enable timer 1 as timer
	TR1=1;
	while(RI==0);
	rbyte=SBUF;
	P1=rbyte;
	RI=0;	
}*/
int main()
{
	unsigned char mybyte;
	TMOD=0x20;
	TH1=0xFA;
	SCON=0x50;//mode 1 with reception enable timer 1 as timer
	TR1=1;
	while(1)
	{
		while(RI==0);
		mybyte=SBUF;
		P1=mybyte;
		RI=0;	
	}
}