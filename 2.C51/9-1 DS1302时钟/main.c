#include <REGX52.H>
#include "DS1302.h"
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"



unsigned char DS1302_Time []={26,7,5,23,59,55,7};
unsigned int num;
void main()
{
	DS1302_Init();
	LCD_Init();
	Timer0_Init();
	

	DS1302_WriteTime(DS1302_Time);
	LCD_ShowString(1,1,"  -  -");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
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
		DS1302_ReadTime(DS1302_Time);
		T0Count = 0;
	}
	
}