#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

int main()
{
	uint8_t KeyNum;
	uint8_t Light;
	LED_Init();
	Key_Init();
	Buzzer_Init();
	
	while(1)
	{
		Light = Light_Sensor_Flag();
		if(Light == 0)
		{
			Buzzer_OFF();
		}else
		{
			Buzzer_ON();
		}           
	}
}
