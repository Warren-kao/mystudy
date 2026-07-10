#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor = P1^0;
sbit LED = P2^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main()
{
	Timer0_Init();
	Compare = 0;
	Nixie_Set(1,0);
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 2)
		{
			Speed++;
			Speed %= 4;
			Nixie_Set(1,Speed);
			switch (Speed)
			{
				case 0 :Compare = 0;break;
				case 1 :Compare = 30;break;
				case 2 :Compare = 60;break;
				case 3 :Compare = 90;break;
			}
		}
		Nixie_Loop();
	}
}


void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count1;
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值

	T0Count1++;

	if(T0Count1 >= 200)
	{
		Key_Loop();
		T0Count1 = 0; 
	}
	Counter++;
	Counter %= 100;
	if(Counter<Compare)
	{
		Motor = 1;
		LED = 0;
		
	}else
	{
		Motor = 0;
		LED = 1;
	}
		
}