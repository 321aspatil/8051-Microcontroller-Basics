#include <REG51.H>

sbit rs = P3^4;
sbit rw = P3^5;
sbit e = P3^6;

sbit R0 = P1^0;
sbit R1 = P1^1;
sbit R2 = P1^2;
sbit R3 = P1^3;

sbit C0 = P1^4;
sbit C1 = P1^5;
sbit C2 = P1^6;

int cnt1=0;
int cnt2=0;
void delay()
{
	int i;
	e = 1;
	for(i=0;i<30000;i++);
	e = 0;
}

void lcd_cmd(unsigned int ch)
{
	rs = 0;
	rw = 0;
	P2 = 0x00;
	P2 = ch;
	delay();
}

void lcd_data(unsigned char ch)
{
	rs = 1;
	rw = 0;
	P2 = 0x00;
	P2 = ch;
	cnt1++;
	cnt2++;
	delay();
	
}

void main()
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0c);
	lcd_cmd(0x80);
	lcd_cmd(0x06);

	while(1)
	{
		if(cnt1==16){
			lcd_cmd(0xC0);
			cnt1=0;
		}
		if(cnt2==32){
			lcd_cmd(0x01);
			cnt2=0;
		}
		else{
		R0 = R1 = R2 = R3 = 1;
		R0 = 0;
		if(C0 == 0)
		{
			lcd_data('1');
			while(C0 == 0);
		}
		if(C1 == 0)
		{
			lcd_data('2');
			while(C1 == 0);
		}
		if(C2 == 0)
		{
			lcd_data('3');
			while(C2 == 0);
		}
		
		R0 = R1 = R2 = R3 = 1;
		R1 = 0;
		if(C0 == 0)
		{
			lcd_data('4');
			while(C0 == 0);
		}
		if(C1 == 0)
		{
			lcd_data('5');
			while(C1 == 0);
		}
		if(C2 == 0)
		{
			lcd_data('6');
			while(C2 == 0);
		}
		
		/****** */
		R0 = R1 = R2 = R3 = 1;
		R2 = 0;
		if(C0 == 0)
		{
			lcd_data('7');
			while(C0 == 0);
		}
		if(C1 == 0)
		{
			lcd_data('8');
			while(C1 == 0);
		}
		if(C2 == 0)
		{
			lcd_data('9');
			while(C2 == 0);
		}
		
		/****** */
		
		R0 = R1 = R2 = R3 = 1;
		R3 = 0;
		if(C0 == 0)
		{
			lcd_data('*');
			while(C0 == 0);
		}
		R0 = R1 = R2 = R3 = 1;
		R3 = 0;
		if(C1 == 0)
		{
			lcd_data('0');
			while(C1 == 0);
		}
		R0 = R1 = R2 = R3 = 1;
		R3 = 0;
		if(C2 == 0)
		{
			lcd_data('#');
			while(C2 == 0);
		}
	}
	}
}












