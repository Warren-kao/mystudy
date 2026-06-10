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
	unsigned char flag = 1;//00000001
	P2_0 = 0;
	while(1)
	{
		//p31检测
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			P2 = ~flag;
			flag = flag <<1;
			if (!flag)
				flag = 0x01;//00000001
		}
		//p30检测
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			flag = flag >> 1;
			if (!flag)
				flag =0x80; //10000000
			P2 = ~flag;
		}
	}
	return;
}