/*Program to generate square wave on port pin P1.0 and rectangular wave on port pin P1.1
using External Interrupt 0 and External Interrupt 1 respectively.*/

//a. Use by default priority and sensitivity.
#include <REG51.H>
sbit LED1=P1^0;
sbit LED2=P1^1;


void ext0_isr(void) interrupt 0
{
	
	LED1=~LED1;
}
void ext1_isr(void) interrupt 2
{
	
	LED2=~LED2;
}

void main()
{
	LED1=~LED1;
	LED2=~LED2; 
	IE=0X85;
	//TCON=0X05;//External Interrupt 0 and 1 Falling Edge
	while(1);
}

//b.Reverse the priority but default sensitivity
//#include <REG51.H>
//sbit LED1=P1^0;
//sbit LED2=P1^1;

//void ext0_isr(void) interrupt 0
//{
//	LED1=~LED1;
//}
//void ext1_isr(void) interrupt 2
//{
//	LED2=~LED2;
//}

//void main()
//{
//	LED1=~LED1;
//	LED2=~LED2; 
//	IE=0X85;
//	IP=0X04;//Higest Priority assigned to INT1
//	//TCON=0X05;//External Interrupt 0 and 1  Falling Edge
//	while(1);
//}