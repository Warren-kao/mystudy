#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MPU6050.h"

uint8_t Data;
int main()
{
	OLED_Init();
	MPU6050_Init();

	OLED_ShowString(1,1,"ID:");
	OLED_ShowHexNum(1,4,MPU6050_GetID(),2);
	OLED_ShowString(1,7,"Temp:");
	
	while(1)
	{
		MPU6050_GetData();
		OLED_ShowSignedNum(2,1,MPU6050_Data.Accx,5);
		OLED_ShowSignedNum(3,1,MPU6050_Data.Accy,5);
		OLED_ShowSignedNum(4,1,MPU6050_Data.Accz,5);
		
		OLED_ShowSignedNum(2,8,MPU6050_Data.Gyrox,5);
		OLED_ShowSignedNum(3,8,MPU6050_Data.Gyroy,5);
		OLED_ShowSignedNum(4,8,MPU6050_Data.Gyroz,5);
		OLED_ShowSignedNum(1,12,MPU6050_Data.Temp/340.0 + 36.53,2);


	}
}
