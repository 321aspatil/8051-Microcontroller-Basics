#include <REG51.H>
sfr LCD_PORT=0XA0;
sbit RS=P0^6;
sbit E =P0^7;
void msdelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void lcd_cmd(unsigned char command){
	LCD_PORT=command;
	RS=0;// for command
	E=1;
	msdelay(1);
	E=0;
}
void lcd_data(unsigned char disp_data){
	LCD_PORT=disp_data;
	RS=1;// for data
	E=1;
	msdelay(1);
	E=0;
}
void lcd_init(){
	lcd_cmd(0X38);//for using 2 lines of 5*7 matrix of LCD
	msdelay(1);
	lcd_cmd(0X0c);
	msdelay(10);
	lcd_cmd(0X80);
	msdelay(10);
	
}