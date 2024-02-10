#include <REG51.H>
#include"LCD.h"
void UART_Init()
{
	TMOD=0x20;
	TH1=0xFA;
	SCON=0x50;
	TR1=1;
}
unsigned char RX_data(void)
{
	unsigned char a;
	while(RI==0);
	RI=0;
	a=SBUF;//Received data is stored in a variable
	return a;
}
void main()
{
	unsigned char x;
	LCD_Init();
	UART_Init();
	while(1)
	{
		x=RX_data();
		if(x==0x00D)
		{
			LCD_Command(0xCD);//go to 2nd line
		}
		else if(x=='1')
		{
			LCD_Command(0x01);//clear the LCD
		}
		else
		{
			LCD_data(x);
			delay(10);
			
		}
	}
}