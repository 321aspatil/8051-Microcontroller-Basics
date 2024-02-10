#include <REG51.H>

sbit c1=P2^0;
sbit c2=P2^1;
sbit c3=P2^2;
sbit r1=P2^3;
sbit r2=P2^4;
sbit r3=P2^5;

sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
sbit led5=P1^4;
sbit led6=P1^5;
sbit led7=P1^6;
sbit led8=P1^7;



/*void msdelay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<1275;j++);
	}
}
*/

void main()
{
	led1=led2=led3=led4=led5=led6=led7=led8=0;
	c1=0;
	c2=0;
	c3=0;
	r1=0;
	r2=0;
	r3=0;
	while(1)
	{
		c1=1;c2=0;c3=0;
		if(r1==1 && r2==0&& r3==0)
		{
			led1=1;
		}
		if(r1==0 && r2==1&& r3==0)
		{
			led2=1;
		}
		if(r1==0 && r2==0&& r3==1)
		{
			led3=1;
		}
		
		c1=0;c2=1;c3=0;
		if(r1==1 && r2==0&& r3==0)
		{
			led4=1;
		}
		if(r1==0 && r2==1&& r3==0)
		{
			led5=1;
		}
		if(r1==0 && r2==0&& r3==1)
		{
			led6=1;
		}
		
		c1=0;c2=0;c3=1;
		if(r1==1 && r2==0&& r3==0)
		{
			led7=1;
		}
		if(r1==0 && r2==1&& r3==0)
		{
			led8=1;
		}
		if(r1==0 && r2==0&& r3==1)
		{
			led1=led2=led3=led4=led5=led6=led7=led8=1;
		}
	}
}