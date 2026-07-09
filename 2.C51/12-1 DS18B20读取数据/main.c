#include <REGX52.H>
#include "DS18B20.h"
#include "LCD1602.h"
#include "Delay.h"

float T;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Temperature:");
	LCD_ShowString(2,5,".");
	while(1)
	{
		DS18B20_ConvertT();
		T = DS18B20_ReadT();
		if(T<0)
		{
			T=-T;
			LCD_ShowString(2,1,"-");
		}
		else
		{
			LCD_ShowString(2,1,"+");
		}
		LCD_ShowNum(2,2,T,3);
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
	}
}