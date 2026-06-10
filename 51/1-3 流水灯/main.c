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


void main(){
	
	int i;
	while(1)
	{
		//顺序循环
//		if(i>=8)
//			i = 0;

//		Delay(100);
//		i++;
		
		
		//交替循环
		for(i = 0 ; i < 8; i ++)
		{
			P2 = ~(0x01 << i);
			Delay(50);
		}
		for(i = 7 ; i >= 0; i --)
		{
			P2 = ~(0x01 << i);
			Delay(50);
		}
		
	}
}