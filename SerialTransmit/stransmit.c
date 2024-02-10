#include <REG51.H>
void transmit(char ch)
{
	TMOD=0x20;//mode 2 of timer 1 is selected as timer
	TH1=0xFA;//4800 baud rate
	SCON=0x40;//mode 1 of serial transmission
	TR1=1;
	SBUF=ch;
	while(TI==0);
	TI=0;	
}
void main()
{
	while(1){
	transmit('*');
	transmit('A');
	transmit('N');
	transmit('I');
	transmit('K');
	transmit('E');
	transmit('T');
	transmit('*');
	}
} 