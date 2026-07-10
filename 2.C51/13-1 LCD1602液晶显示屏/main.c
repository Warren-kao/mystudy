#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Hello");
	LCD_ShowNum(1,7,123,3);
	LCD_ShowSignedNum(1,11,-12,3);
	LCD_ShowChar(1,16,0xDF);
	LCD_ShowHexNum(2,1,10,2);
	LCD_ShowBinNum(2,4,0xAA,8);
	LCD_ShowString(2,13,"I'm Warren");
	while(1)
	{
		LCD_WriteCommand(0x18);
		Delay(500);
	}
}