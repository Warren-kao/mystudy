#include <REGX52.H>
#include <intrins.h>
#include "Timer0.h"
#include "Key.h"

unsigned char LedMod;
void main()
{
	Timer0_Init();
	P2 = 0xFE;
	while(1)
	{
	
		switch(GetKeyNum())
		{
			//case 1:LEdMod = 1;break;//K1损坏
			case 2:LedMod = 2;break;
			case 3:LedMod = 3;break;
			case 4:LedMod = 4;P2 = 0x00;break;
		}
	}
}


void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	if(T0Count >= 500)
	{
		T0Count = 0;
		switch(LedMod)
		{
			case 2 : P2 = _cror_(P2,1);break;
			case 3 : P2 = _crol_(P2,1);break;
			case 4 : P2=~P2;break;
		}
		
	}
	
}