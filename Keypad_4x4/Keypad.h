sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit c4=P1^7;
void keypad(void);
void keypad()
{
	c1=c2=c3=c4=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		LCD_Data('7');
	}
	else if(c2==0)
	{
		while(c2==0);
		LCD_Data('8');
	}
	else if(c3==0)
	{
		while(c3==0);
		LCD_Data('9');
	}
	else if(c4==0)
	{
		while(c4==0);
		LCD_Data('/');
	}
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		LCD_Data('4');
	}
	else if(c2==0)
	{
		while(c2==0);
		LCD_Data('5');
	}
	else if(c3==0)
	{
		while(c3==0);
		LCD_Data('6');
	}
	else if(c4==0)
	{
		while(c4==0);
		LCD_Data('*');
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		LCD_Data('1');
	}
	else if(c2==0)
	{
		while(c2==0);
		LCD_Data('2');
	}
	else if(c3==0)
	{
		while(c3==0);
		LCD_Data('3');
	}
	else if(c4==0)
	{
		while(c4==0);
		LCD_Data('-');
	}
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		while(c1==0);
		LCD_Command(0X01);
		LCD_String("Enter the key:");
		LCD_Command(0XC0);
	}
	else if(c2==0)
	{
		while(c2==0);
		LCD_Data('0');
	}
	else if(c3==0)
	{
		while(c3==0);
		LCD_Data('=');
	}
	else if(c4==0)
	{
		while(c4==0);
		LCD_Data('+');
	}
}
