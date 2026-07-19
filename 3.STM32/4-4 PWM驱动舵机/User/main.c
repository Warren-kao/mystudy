#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Servo.h"
#include "Delay.h"
#include "Key.h"


uint8_t Num;
float Angle;

int main()
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	OLED_ShowString(1,1,"Angle:");
	OLED_ShowNum(1,7,(int)Angle,3);
	while(1)
	{
		Num = Key_GetNum();
		if(Num == 1)
		{
			Angle += 30;
			if(Angle > 180)
			{
				Angle = 0;
			}
			Servo_SetAngle(Angle);
			OLED_ShowNum(1,7,(int)Angle,3);
		}else if(Num == 2)
		{
			if(Angle == 0)
			{
				Angle = 180;
			}else
			{
				Angle -= 30;
			}
			Servo_SetAngle(Angle);
			OLED_ShowNum(1,7,(int)Angle,3);
		}

	}
}

