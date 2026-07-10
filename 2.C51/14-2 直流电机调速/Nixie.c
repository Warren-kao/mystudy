#include <REGX52.H>
#include "Delay.h"

unsigned char font[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};
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



unsigned char Nixie_Buf[9]={0,10,10,10,10,10,10,10,10};

void Nixie_Set(unsigned int i,unsigned int n)
{
	 Nixie_Buf[i] = n;
}

void Nixie_Show(unsigned int i,unsigned int n)
{
	P0 = 0x00;
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
}

void Nixie_Loop()
{
	static unsigned char i = 1;
	Nixie_Show(i,Nixie_Buf[i]);
	if((++i) > 8 )
	{
		i=1;
	}
}