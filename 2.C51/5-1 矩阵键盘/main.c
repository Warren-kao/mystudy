#include <REGX52.H>
#include"LCD1602.h"
#include"Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum = 16;

void main()
{
	int num = 0;
	LCD_Init();
	LCD_ShowString(1,1,"Key Number:");

	
	while(1)
	{
		KeyNum = MatrixNum();

		
		if(KeyNum != 16)
		{
			LCD_ShowNum(2,1,KeyNum,2);
		}

	}
}
	