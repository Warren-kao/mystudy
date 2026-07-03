#include <REGX52.H>
#include <intrins.h>
#include "Timer0.h"
#include "LCD1602.h"

unsigned int hour,min,s;
void main()
{
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"Clock");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,s,2);
		
	}
}


void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count = 0;
		s++;
		if(s>=60)
		{
			min++;
			s = 0;
		}
		if(min >= 60)
		{
			hour++;
			min = 0;
		}
		if(hour >=24)
			hour = 0;
		
	}
	
}