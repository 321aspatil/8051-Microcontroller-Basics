#include <REG51.H>
void transmit(char ch)
{
	TH1=0xFA;
	SCON=0x40;//mode 1 of serial transmission
	TR1=1;
	SBUF=ch;
	while(TI==0);
	TI=0;	
}
void main()
{
	TMOD=0x20;//mode 2 of timer 1 is selected as timer
	transmit('*');
	transmit('A');
	transmit('N');
	transmit('I');
	transmit('K');
	transmit('E');
	transmit('T');
	transmit('*');
} 

/*
#include <REG51.H>
void receive(){
	unsigned char rbyte;
	TH1=0xFA;
	SCON=0x50;//mode 1 with reception enable timer 1 as timer
	TR1=1;
	while(1)
	{
		while(RI==0);
		rbyte=SBUF;
		P1=rbyte;
		RI=0;	
	}
}
void main()
{
	TMOD=0x20;
	receive();
}
*/