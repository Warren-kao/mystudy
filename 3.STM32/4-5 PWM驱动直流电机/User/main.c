#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Motor.h"
#include "Delay.h"
#include "Key.h"

uint8_t KeyNum;
int8_t Speed;

int main()
{
	OLED_Init();
	Motor_Init();
	Key_Init();
	OLED_ShowString(1,1,"Speed:");
	OLED_ShowSignedNum(1,7,Speed,4);
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				if(Speed == 100)
				{
					Speed = -100;
				}else
				{
					Speed += 20;
				}
				OLED_ShowSignedNum(1,7,Speed,4);
				Motor_SetSpeed(Speed);
			}else if(KeyNum == 2)
			{
				if(Speed == -100)
				{
					Speed = 100;
				}else
				{
					Speed -= 20;
				}
				OLED_ShowSignedNum(1,7,Speed,4);
				Motor_SetSpeed(Speed);
			}
			
			
		}

	}
}

