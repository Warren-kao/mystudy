#include <REGX52.H>
#include "DS18B20.h"
#include "LCD1602.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float T;
char Thigh,Tlow;
unsigned char KeyNum;
void main()
{
	//Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(1,7,".");
	while(1)
	{
		/*温度显示*/
		DS18B20_ConvertT();
		T =  DS18B20_ReadT();
		if(T<0)
		{
			LCD_ShowChar(1,3,'-');
			T =-T;
		}else if(T >= 0)
		{
			LCD_ShowChar(1,3,'+');
		}
		LCD_ShowNum(1,4,T,3);
		LCD_ShowNum(1,8,(unsigned long)(T*100)%100,2);
		
		/*温度阈值*/
		LCD_ShowString(2,1,"TH:");
		LCD_ShowString(2,9,"TL:");
		LCD_ShowSignedNum(2,4,Thigh,2);
		LCD_ShowSignedNum(2,12,Tlow,2);
		
		/*按键控制*/
		KeyNum = Key();
		if(KeyNum)
		{
			switch (KeyNum)
			{
				case 1:Thigh++;break;
				case 2:Thigh--;break;
				case 3:Tlow++;break;
				case 4:Tlow--;break;
			}
		}
		
	}
}

//void Timer0_Rountine() interrupt 1
//{	
//	static unsigned int T0Count;
//	TH0 = 0xFC;
//	TL0 = 0x18;
//	T0Count++;
//	if(T0Count >= 20)
//	{
//		Key_Loop();
//		T0Count = 0; 
//	}
//	
//}