#include <REGX52.H>

char font[11] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00};
//0  11000000		00111111
//1  11111001		00000110
//2  10100100		01011011
//3  10110000		01001111
//4  10011001		01100110
//5  10010010		01101101
//6  10000010		01111101
//7  11111000		00000111
//8  10000000		01111111
//9  10010000		01101111
//char pos[8] = {0x1C,0x18,0x14,0x10,0x0C,0x04,0x02,0x00};
	//00011100,00011000,00010100,00010000,00001100,00000100,00000010,00000000


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

void show(unsigned int i,unsigned int n)
{
	switch(i)
	{
		case 1:P2_4 = 1;P2_3 = 1;P2_2 = 1;break;
		case 2:P2_4 = 1;P2_3 = 1;P2_2 = 0;break;
		case 3:P2_4 = 1;P2_3 = 0;P2_2 = 1;break;
		case 4:P2_4 = 1;P2_3 = 0;P2_2 = 0;break;
		case 5:P2_4 = 0;P2_3 = 1;P2_2 = 1;break;
		case 6:P2_4 = 0;P2_3 = 1;P2_2 = 0;break;
		case 7:P2_4 = 0;P2_3 = 0;P2_2 = 1;break;
		case 8:P2_4 = 0;P2_3 = 0;P2_2 = 0;break;
		
	}
	P0 = font[n];
	Delay(1);
	P0 = 0x00;
}
void main()
{ 
	
	while(1)
	{
		show(1,1);
		show(2,2);
		show(3,3);
		
	}
}