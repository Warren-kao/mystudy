#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "XPT2046.h"

unsigned int XP,YP,VBAT;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADJ");
	while(1)
	{
		XP = XPT2046_ReadAD(XPT2046_XP);
		LCD_ShowNum(2,1,XP,16);
		Delay(10);
//		YP = XPT2046_ReadAD(XPT2046_YP);
//		LCD_ShowNum(2,6,YP,3);
//		Delay(10);
//		VBAT = XPT2046_ReadAD(XPT2046_VBAT);
//		LCD_ShowNum(2,11,VBAT,3);
//		Delay(10);
	}
}