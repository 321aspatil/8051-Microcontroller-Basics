#include <REG51.H>

sbit c1 = P3^0;
sbit c2 = P3^1;
sbit c3 = P3^2;
sbit r1 = P2^0;
sbit r2 = P2^1;
sbit r3 = P2^2;
sfr n = 0xA0;

int main()
{
	n = 0x00;
	c1=0;c2=0;c3=0;r1=0;r2=0;r3=0;
	
	while(1)
	{
		c1=1;c2=0;c3=0;
		if(r1==1 && r2==0 && r3==0)
		{
			P2 = 0x06;
		}
		if(r1==0 && r2==1 && r3==0)
		{
			P2 = 0x66;
		}
		if(r1==0 && r2==0 && r3==1)
		{
			P2 = 0x07;
		}
		
		c1=0;c2=1;c3=0;
		if(r1==1 && r2==0 && r3==0)
		{
			P2 = 0x5B;
		}
		if(r1==0 && r2==1 && r3==0)
		{
			P2 = 0x6D;
		}
		if(r1==0 && r2==0 && r3==1)
		{
			P2 = 0x7F;
		}
		
		c1=0;c2=0;c3=1;
		if(r1==1 && r2==0 && r3==0)
		{
			P2 = 0x4F;
		}
		if(r1==0 && r2==1 && r3==0)
		{
			P2 = 0x7D;
		}
		if(r1==0 && r2==0 && r3==1)
		{
			P2 = 0x6F;
		}
		if(r1==0 && r2==0 && r3==0)
		{
	  P2=0x00;
		}
	}
}