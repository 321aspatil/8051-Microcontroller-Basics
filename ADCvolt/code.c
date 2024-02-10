#include<reg51.h>
#include<stdio.h>
sbit ale=P3^3;  
sbit oe=P3^6; 
sbit start=P3^4; 
sbit eoc=P3^5;  
sbit clk=P3^7;  
sbit ADDA=P3^0;  //Address pins for selecting input channels.
sbit ADDB=P3^1;
sbit ADDC=P3^2;
#define lcd P2  //lcd 
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
#define Adc_Data P1  //ADC

int result[3],ADC_value;

void delay(unsigned int count) 
{
    int i,j;
    for(i=0;i<count;i++)
    for(j=0;j<1000;j++);
}
void lcd_data(unsigned char ch)
{
    rs=1;
    rw=0;
    lcd=ch & 0xF0;
    en=1;
    delay(1);
    en=0;
    lcd=ch<<4 & 0xF0;
    en=1;
    delay(1);
    en=0;
}
void lcdcmd(unsigned char ch)
{
    rs=0;
    lcd=ch & 0xf0;
    en=1;
    delay(1);
    en=0;
    
		lcd=ch<<4 & 0xF0;
    en=1;
    delay(1);
    en=0;
}
void lcdprint(char *str) //Function to send string data to LCD.
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}
void lcd_Init()
{
	lcdcmd(0x38);
	lcdcmd(0x02);
	lcdcmd(0x0e);
  lcdcmd(0x01);
}
void show()
{ 
sprintf(result,"%d",ADC_value);
lcdprint(result);
lcdprint(" ");
}
void main()
{
    eoc=1;
    ale=0;
    oe=0;
    start=0;
    lcd_Init();
    while(1)
    {
        ADDC=0; ADDB=0;ADDA=0;
				ADC_value=0;
				lcdcmd(0xc0);
				ale=1;start=1;
				delay(1);
				ale=0;start=0;
				ADC_value=Adc_Data;
				delay(1);
				show();
        ADC_value=0;
    }  
}