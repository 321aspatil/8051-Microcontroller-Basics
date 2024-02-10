//External interrupt 0 as low level sensitive interrupt
//#include <REG51.H>
//sbit LED=P1^0;
//void delay(unsigned int time){
//	unsigned int i,j;
//	for(i=0;i<time;i++){
//		for(j=0;j<1275;j++);
//	}
//}
//void ext0_isr(void) interrupt 0
//{

//	LED=0;
//	delay(5);
//	LED=1;
//	delay(5);
//}

//void main()
//{
//	
//	//LED=~LED;
//	IE=0X81;
//	while(1);
//}

//External interrupt 0 as falling edge sensitive interrupt
#include <REG51.H>
sbit LED=P1^0;
void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void ext0_isr(void) interrupt 0
{

	LED=0;
	delay(5);
	LED=1;
	delay(5);
}

void main()
{
	LED=~LED;
	TCON=0X01;//external interrupt 0 as falling edge sensitive interrupt
	IE=0X81;
	while(1);
}
