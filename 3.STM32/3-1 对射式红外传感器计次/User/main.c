#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "CountSensor.h"


int main()
{
	uint16_t Num;
	OLED_Init();
	Count_Sensor_Init();
	OLED_ShowString(1,1,"Warren's");
	OLED_ShowNum(2,1,Num,3);
	while(1)
	{
		Num = CountSensor_Get();
		OLED_ShowNum(2,1,Num,3);

	}
}
