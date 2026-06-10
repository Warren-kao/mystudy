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

		P2_0 = 0;
	while(1){
//		P2 = 0xFE;
//		Delay(500);
//		P2 = 0xFF;
//		Delay(1000);
		

		Delay(1000);
		P2_0 = ~P2_0;
		
		
	}
}