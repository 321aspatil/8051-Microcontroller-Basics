sfr LCD_Port=0XA0; //P2 port as data port
sbit rs=P2^0;	//Register select pin
sbit en=P2^1;//Enable pin

void msdelay(unsigned int time);
void LCD_Command(char);
void LCD_Data(char);
void LCD_String(char *str);
void LCD_Init(void);

void msdelay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<1275;j++);//for getting 1ms delay
	}
}

void LCD_Command(char cmd)//LCD 16*2 command function
{
	LCD_Port=(LCD_Port & 0X0F)|(cmd & 0XF0);//send upper nibble
	rs=0; // command register
	en=1;
	msdelay(1); 
	en=0;
	msdelay(1);
	
	LCD_Port=(LCD_Port & 0X0F)|(cmd <<4);//send lower nibble
	en=1; //enable pulse
	msdelay(1); 
	en=0;
	msdelay(1);
}
void LCD_Data(char char_data)//LCD data write function
{
	LCD_Port=(LCD_Port & 0X0F)|(char_data & 0XF0);//send upper nibble
	rs=1;//Data register
	en=1;
	msdelay(1);
	en=0;
	msdelay(1);
	
	LCD_Port=(LCD_Port & 0X0F)|(char_data <<4);//send lower nibble
	en=1; //enable pulse
	msdelay(1); 
	en=0;
	msdelay(1);
}
void LCD_String(char *str)//send string to lcd function
{
	int i;
	for(i=0;str[i]!=0;i++)//send each char of string till the NULL
	{
		LCD_Data(str[i]);//call LCD data write
	}
}

void LCD_Init(void)//LCD initialize function
{
	msdelay(1);//LCD Power ON Initialization time>15ms
	LCD_Command(0X02);//4 bit mode
	LCD_Command(0X28);//Initialization of 16*2 LCD in 4 bit mode
	LCD_Command(0X0C);//Display ON Cursor OFF
	LCD_Command(0X06);//Auto increment cursor
	LCD_Command(0X01);//clear display
	LCD_Command(0X80);//cursor at home position

}