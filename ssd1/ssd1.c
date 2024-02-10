#include <REG51.H>
sfr port2=0XA0;
void msdelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
}
void main(){
	unsigned char num[16]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90,0X88,0X83,0XC6,0XA1,0X86,0X8E};
	unsigned char num2[10]={0X3F,0X06,0X5B,0X4F,0X66,0X60,0XF0,0X07,0X7F,0X6F};
	unsigned char k;
	port2=0;//define P2 as output
	while(1){
		for(k=0;k<10;k++){
			port2=num2[k];
			msdelay(100);
		}
	}

}