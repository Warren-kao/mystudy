#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"
#include "LED.h"

uint8_t RxData;

int main()
{
	OLED_Init();
	LED_Init();
	Serial_Init();

	OLED_ShowString(1,1,"RxData:");
	OLED_ShowString(3,1,"TxData:");
	Serial_SendString("ERROR_COMMAND\r\n");
	while(1)
	{
		if(Serial_RxFlag == 1)
		{
			if(strcmp((char*)Serial_RxPacket,"LED_ON") == 0)
			{
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,(char*)Serial_RxPacket);
				LED1_ON();
				OLED_ShowString(4,1,"                ");
				OLED_ShowString(4,1,"LED_ON_OK");
				Serial_SendString("LED_ON_OK\r\n");
			}else if(strcmp((char*)Serial_RxPacket,"LED_OFF") == 0)
			{
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,(char*)Serial_RxPacket);
				LED1_OFF();
				OLED_ShowString(4,1,"                ");
				OLED_ShowString(4,1,"LED_OFF_OK");
				Serial_SendString("LED_OFF_OK\r\n");
			}else
			{
				OLED_ShowString(2,1,"                ");
				OLED_ShowString(2,1,(char*)Serial_RxPacket);
				OLED_ShowString(4,1,"                ");
				OLED_ShowString(4,1,"ERROR_COMMAND");
				Serial_SendString("ERROR_COMMAND\r\n");
			}
			Serial_RxFlag = 0;
		}
	}
}
