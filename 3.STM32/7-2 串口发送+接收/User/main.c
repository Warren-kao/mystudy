#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;

int main()
{
	OLED_Init();
	Serial_Init();

	while(1)
	{
		if(Serial_GetRxFlag() == 1)
		{
			
			RxData = Serial_GetData();
			Serial_SendByte(RxData);
			OLED_ShowHexNum(1,1,RxData,2);
		}
	}
}
