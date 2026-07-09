#include <REGX52.H>
#include "AT24C02.h"
#include "LCD1602.h"
#include "Key.h"
#include "Delay.h"


unsigned int Num;
unsigned char KeyNum;
void main()
{
	LCD_Init();
	Num = 0;
	while(1)
	{
		KeyNum=Key();
		if(KeyNum == 1)
		{
			Num++;
		}else if(KeyNum==2)
		{
			Num--;
		}else if(KeyNum==3)
		{
			AT24C02_WriteByte(0,Num%256);
			AT24C02_WriteByte(1,Num/256);
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Write OK");
			Delay(1000);
			LCD_ShowString(2,1,"        ");
		}else if(KeyNum==4)
		{
			Num = AT24C02_ReadByte(1)*256;
			Num += AT24C02_ReadByte(0);
			LCD_ShowNum(1,1,Num,5);
			LCD_ShowString(2,1,"Read OK");
			Delay(1000);
			LCD_ShowString(2,1,"       ");
		}
		LCD_ShowNum(1,1,Num,5);
	}
}