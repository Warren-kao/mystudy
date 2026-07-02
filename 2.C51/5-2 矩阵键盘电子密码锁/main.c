#include <REGX52.H>
#include"LCD1602.h"
#include"Delay.h"
#include "MatrixKey.h"

unsigned int PassWord = 1234;

unsigned char KeyNum ,Count;
unsigned int passwd;

void main()
{
	int num = 0;
	LCD_Init();
	LCD_ShowString(1,1,"PassWord");
	
	while(1)
	{

		KeyNum = MatrixNum();
		if(KeyNum<10)
		{
			if(Count < 4)
			{
				passwd *=10;
				passwd += KeyNum;
				LCD_ShowNum(2,1,passwd,4);
				Count++;
			}
		}else if(KeyNum==10)
		{
			if(passwd == PassWord)
			{
				LCD_ShowString(1,14,"OK ");
				LCD_ShowString(2,1,"    ");
				passwd = 0;
				Count = 0;
			}else
			{
				LCD_ShowString(1,14,"ERR");
				LCD_ShowString(2,1,"    ");
				passwd = 0;
				Count = 0;
			}
		}else if(KeyNum == 11)
		{
			passwd /= 10;
			Count --;
			if(Count>4)
				Count = 0;
			LCD_ShowNum(2,1,passwd,4);
		}
		else if(KeyNum == 12)
		{
			passwd = 0;
			Count = 0;
			LCD_ShowNum(2,1,passwd,4);
		}
	}


}
	