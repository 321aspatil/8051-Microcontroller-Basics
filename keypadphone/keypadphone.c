#include <REG51.H>
#include"LCD.h"
#include"keypad.h"

void main()
{
	unsigned char a[]="Press any Key:";
	int i=0;
	lcd_init();
	while(a[i]!='\0'){
		lcd_data(a[i]);
		i++;
		msdelay(50);
	}
	lcd_cmd(0XC0);
	while(1)
	{
		keypad();
	}
}

