#include <REG51.H>

#define display_port P2 // Data pins connected to port 3 on microcontroller 
sbit rs = P2^0;         // RS pins connected to pin 2 of port 2
sbit rw = P2^1;					// RW pins connected to pin 2 of port 2
sbit e = P2^2;					// E pins connected to pin 2 of port 2

void msdelay(unsigned int time) // Function for creating delay in millisecond
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char command) // Function to send command instruction to LCD
{
 	display_port = (command & 0xF0);
	rs = 0;
	rw = 0;
	e = 1;
	msdelay(1);
	e = 0;
	
	display_port = ((command<<4) & 0xF0) ;
	rs = 0;
	rw = 0;
	e = 1;
	msdelay(1);
	e = 0;
	
}

void lcd_data(unsigned char disp_data) // Function to send display data to LCD
{
	display_port = (disp_data & 0xF0);
	rs = 1;
	rw = 0;
	e = 1;
	msdelay(1);
	e = 0;
	
	display_port = ((disp_data<<4) & 0xF0);
	rs = 1;
	rw = 0;
	e = 1;
	msdelay(1);
	e = 0;
	
}

void lcd_init() // Function to prepare LCD and get it ready
{
		lcd_cmd(0x28); // for using 2 lines and 5x7 matrix in LCD
	  msdelay(10);
		lcd_cmd(0x0C); // turn display ON, cursor blinking
	  msdelay(10);
		lcd_cmd(0x01); // clear screen
	  msdelay(10);
		lcd_cmd(0x80); // bring cursor to position 1 of line 1
	  msdelay(10);
}

void main()
{
	unsigned char a[] = "MPI-8051"; // string of 14 characters with a null character
	int l=0;
	lcd_init();
	while(a[l] != '\0') // searching the null terminator in the sentences
	{
		lcd_data(a[l]);
		l++;
		msdelay(50);
	}
}