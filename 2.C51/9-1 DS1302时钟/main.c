#include <REGX52.H>
#include "DS1302.h"
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"



unsigned char DS1302_Time []={26,7,5,16,30,00,7};

void main()
{
	DS1302_Init();
	LCD_Init();
	DS1302_WriteData(0x8e,0x00);
	DS1302_WriteTime(DS1302_Time);
	LCD_ShowString(1,1,"  -  -");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[2],2);
		LCD_ShowNum(1,7,DS1302_Time[3],2);
		LCD_ShowNum(2,1,DS1302_Time[4],2);
		LCD_ShowNum(2,4,DS1302_Time[5],2);
		LCD_ShowNum(2,7,DS1302_Time[6],2);
		Delay(50);

	}
}

void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	if(T0Count >= 50)
	{
		DS1302_readTime(DS1302_Time);
		
		T0Count = 0;
		P2 = ~P2; 
	}
	
}