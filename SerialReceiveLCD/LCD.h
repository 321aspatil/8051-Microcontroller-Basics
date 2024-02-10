sfr LCD_Port=0xA0;//port P2 as data port
sbit rs=P2^0;//Register select pin
sbit en=P2^1;//Enable pin

void delay(unsigned int);
void LCD_Command(char);
void LCD_data(char);
void LCD_String(char *str);
void LCD_Init(void);

void delay(unsigned int count)
{
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<1275;j++);
	}
}
void LCD_Command(char cmd)
{
	LCD_Port=(LCD_Port & 0x0F)|(cmd & 0xF0);//send upper nibble
	rs=0;
	en=1;
	delay(1);
	en=0;
	delay(1);
	
	LCD_Port=(LCD_Port & 0x0F)|(cmd << 0xF0);//send lower nibble
	en=1;
	delay(1);
	en=0;
	delay(1);
}
void LCD_data(char char_data)
{
	LCD_Port=(LCD_Port & 0x0F)|(char_data & 0xF0);//send upper nibble
	rs=1;
	en=1;
	delay(1);
	en=0;
	delay(1);
	
	LCD_Port=(LCD_Port & 0x0F)|(char_data << 0xF0);//send lower nibble
	en=1;
	delay(1);
	en=0;
	delay(1);
}
void LCD_String(char *str)//Send string to LCD function
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_data(str[i]);
	}
}
void LCD_Init(void)
{
	delay(20);
	LCD_Command(0x02);//4 bit mode
	LCD_Command(0x28);//Initialization of 16x2 LCD in 4 bit mode
	LCD_Command(0x0C);//Display ON cursor off
	LCD_Command(0x06);//Auto increment cursor
	LCD_Command(0x01);//clear display
	LCD_Command(0x80);//cursor at home position
}