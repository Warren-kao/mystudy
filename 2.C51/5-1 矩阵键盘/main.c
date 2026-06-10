#include <REGX52.H>
#include"LCD1602.h"
#include"Delay.h"

void main()
{
	int num = 0;
	LCD_Init();
	LCD_ShowNum(1,1,666,3);
	LCD_ShowChar(1,5,'A');
	LCD_ShowString(2,1,"HELLO WORLD !");

	
	while(1)
	{
		
	
	}
}
	