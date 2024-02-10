#include <REG51.H>

sbit c1=P1^0;
sbit c2=P1^1;
sbit r1=P1^2;
sbit r2=P1^3;

sfr num=0XA0;

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
	num=0XA0;
	c1=0;
	c2=0;
	r1=0;
	r2=0;
	while(1)
	{
		c1=1;c2=0;
		if(r1==1 && r2==0)
		{
			P2=0x06;
		}
		if(r1==0 && r2==1)
		{
			P2=0x4F;
		}
		c1=0;c2=1;
		if(r1==1 && r2==0)
		{
			P2=0x5B;
		}
		if(r1==0 && r2==1)
		{
			P2=0x66;
		}
		
	}
}