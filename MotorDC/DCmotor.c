#include<REG51.h>
sbit RL1=P2^0;
sbit RL2=P2^1;
sbit SW1=P1^0;
sbit SW2=P1^1;
void main()
{
	while(1)
	{
		if(SW1==0 && SW2==1)
		{
			RL1=1;
			RL2=0;
		}
		else if(SW1==1 && SW2==0)
		{
			RL1=0;
			RL2=1;
		}
		else
		{
			RL1=0;
			RL2=0;
		}
	}
}