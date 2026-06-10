#include <REGX52.H>

void Delay(unsigned int x)
{
	unsigned char i, j;
	while(x)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		x--;
	}
	
}

void main()
{
	
	P2_0 = 1;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			P2_0 = ~P2_0;
			
		}
	}
}