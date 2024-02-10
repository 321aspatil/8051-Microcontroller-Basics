#include <REG51.H>
#include"LCD.h"
#include"keypad.h"

void main()
{
	LCD_Init();//Initialization of LCD
	LCD_String("Enter the key:");//Write String on 1st line of LCD
	LCD_Command(0XC0);//go to 2nd line
	while(1)
	{
		keypad();
	}
}