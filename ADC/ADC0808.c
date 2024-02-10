#include <REGX51.H>
sbit A0=P3^0;
sbit A1=P3^1;
sbit A2=P3^2;
sbit ALE=P3^3;
sbit SOC=P3^4;

void msdelay(unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<1275;j++);
	}
}
void main()
{
	P1=0xFF;
	while(1)
	{
		SOC=0;ALE=0;
		A0=0;A1=0;A2=0;
		ALE=0;ALE=1;
		SOC=1;SOC=0;
		msdelay(10);
		P2=P1;
		msdelay(1);
	}
}