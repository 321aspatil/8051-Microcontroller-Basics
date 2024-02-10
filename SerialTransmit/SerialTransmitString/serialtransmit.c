#include <REG51.H>
void UART_Init()
{
	TMOD=0x20;//Timer 1,8 bit auto reload mode
	TH1=0xFA;//Load value for 4800 baud rate
	SCON=0x40;//Mode 1 for transmission
	TR1=1;//start timer 1
}
void Transmit_data(char tx_data)
{
	SBUF=tx_data;//load char in SBUF
	while(TI==0);//wait until stop bit transmit
	TI=0;//clear TI flag
}
void String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		Transmit_data(str[i]);
	}
}
void delay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<1275;j++);
	}
}
void main()
{
	UART_Init();
	while(1)
	{
		String("Aniket Sanjay Patil");
		Transmit_data(0x0D);//Enter the next lines
		delay(300);
	}
}
