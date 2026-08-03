#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "CountSensor.h"
#include "Delay.h"


int main()
{
	uint16_t Num;
	OLED_Init();
	Count_Sensor_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	OLED_ShowString(1,1,"Count:");
	OLED_ShowNum(2,1,Num,3);
	while(1)
	{
		Num = CountSensor_Get();
		OLED_ShowNum(1,7,Num,3);

		OLED_ShowString(2,1,"Running:");
		Delay_ms(100);
		OLED_ShowString(2,1,"        ");
		Delay_ms(100);
		
		PWR_EnterSTOPMode(PWR_Regulator_ON,PWR_STOPEntry_WFI);
		SystemInit();

	}
}
