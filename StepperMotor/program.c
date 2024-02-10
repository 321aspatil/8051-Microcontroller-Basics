#include <REG51.H>
sbit sw1=P3^0;
sbit sw2=P3^1;
sbit sw3=P3^2; 
unsigned int i;
unsigned int wave[]={0x01,0x02,0x04,0x08};
unsigned int fulld[]={0x0C,0x06,0x03,0x09};
unsigned int halfd[]={0x08,0x0C,0x04,0x06,0x02,0x03,0x01,0x09};
void delay(unsigned int time) // Delay Function
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}

void main() //Project main function
{
	while(1)
	{
		if(sw1==0)
		{
			
			for(i=0;i<=3;i++){
			P2=wave[i];
			delay(100);
			P2=0x00;
			}
			
//			P2=0x01; // 0001 P2_0=1,P2_1=0,P2_2=0,P2_3=0
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x02; //0010
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x04; //0100
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x08; //1000
//			delay(100);
//			P2=0x00; 
//			delay(100);
		}
		else if(sw2==0)
		{
			for(i=0;i<=3;i++){
				P2=fulld[i];
				delay(100);
				P2=0x00;
			}	
//			P2=0x0C; //1100      P2_0=1,P2_1=1,P2_2=0,P2_3=0
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x06; //0110
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x03; //0011
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x09; //1001
//			delay(100);
//			P2=0x00; 
//			delay(100);
		}
		else if(sw3==0)
		{
				for(i=0;i<=7;i++){
				P2=halfd[i];
				delay(100);
				P2=0x00;
			}	
//			P2=0x08; //1000      P2_0=1,P2_1=0,P2_2=0,P2_3=0
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x0C; //1100
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x04; //0100
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x06; //0110
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x02; //0010    
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x03; //0011
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x01; //0001
//			delay(100);
//			P2=0x00; 
//			delay(100);
//			P2=0x09; //1001
//			delay(100);
//			P2=0x00; 
//			delay(100);
		}
		else{
			
		}
	}
}