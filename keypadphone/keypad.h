sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

void keypad(void);
void keypad()
{
	//c1=c2=c3=1;
	r1=0;r2=1;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		lcd_data('1');
	}
a
	else if(c2==0)
	{
		while(c2==0);
		lcd_data('2');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_data('3');
	}
	
	r1=1;r2=0;r3=1;r4=1;
	if(c1==0)
	{
		while(c1==0);
		lcd_data('4');
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_data('5');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_data('6');
	}
	
	r1=1;r2=1;r3=0;r4=1;
	if(c1==0)
	{
		while(c1==0);
		lcd_data('7');
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_data('8');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_data('9');
	}
	
	
	r1=1;r2=1;r3=1;r4=0;
	if(c1==0)
	{
		while(c3==0);
		lcd_data('*');
	}
	else if(c2==0)
	{
		while(c2==0);
		lcd_data('0');
	}
	else if(c3==0)
	{
		while(c3==0);
		lcd_data('#');
	}
}
