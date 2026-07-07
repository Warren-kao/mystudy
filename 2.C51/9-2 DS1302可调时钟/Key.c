#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  获取按键数值
  * @param  无
  * @retval 按键松手后返回按键数值,默认为0,范围0~4
  */
char GetKeyNum()
{
	unsigned char num = 0;
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);num = 1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);num = 2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);num = 3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);num = 4;}
	
	return num;	
}