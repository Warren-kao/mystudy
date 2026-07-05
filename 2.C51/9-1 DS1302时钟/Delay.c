#include <REGX52.H>
#include"Delay.h"

void Delay(unsigned int x)
{
	unsigned char i, j;
	while(x)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		x--;
	}
	
}


//函数定义：
/**
  * @brief  LCD1602延时函数，12MHz调用可延时1ms
  * @param  无
  * @retval 无
  */
void LCD_Delay()
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}