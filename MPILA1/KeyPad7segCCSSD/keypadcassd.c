#include <REG51.H>
sfr port2=0XA0;
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

unsigned char snum;
unsigned char num2[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
void keypad(void);
void keypad()
{
	//c1=c2=c3=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		//lcd_data('1');
		snum=num2[1];
		
	}
	else if(c2==0)
	{
		while(c2==0);
		//lcd_data('2');
		snum=num2[2];
	}
	else if(c3==0)
	{
		while(c3==0);
		//lcd_data('3');
		snum=num2[3];
		
	}
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		//lcd_data('4');
		snum=num2[4];
	}
	else if(c2==0)
	{
		while(c2==0);
		//lcd_data('5');
		snum=num2[5];
	}
	else if(c3==0)
	{
		while(c3==0);
		//lcd_data('6');
		snum=num2[6];
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		//lcd_data('7');
		snum=num2[7];
	}
	else if(c2==0)
	{
		while(c2==0);
		//lcd_data('8');
		snum=num2[8];
	}
	else if(c3==0)
	{
		while(c3==0);
		//lcd_data('9');
		snum=num2[9];
	}
	
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		while(c1==0);
		//lcd_data('*');
		snum=num2[0];
	}
	else if(c2==0)
	{
		while(c2==0);
		//lcd_data('0');
		snum=num2[0];
	}
	else if(c3==0)
	{
		while(c3==0);
		//lcd_data('#');
		snum=num2[0];
	}
}
void main(){
	port2=0;//define P2 as output
	while(1){
		keypad();
		port2=snum;
	}
}