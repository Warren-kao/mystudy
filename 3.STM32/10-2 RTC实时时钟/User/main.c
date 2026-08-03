#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"
#include "MyRTC.h"

uint8_t KeyNum;

int main()
{
	//本节开始,电路板替换为FreeRtos电路板,I2C换为SCL PB6,SDA PB7
	OLED_Init();
	//按键替换为PB14
	Key_Init();
	MyRTC_Init();
	
	OLED_ShowString(1,1,"Date:xxxx-xx-xx");
	OLED_ShowString(2,1,"Time:xx-xx-xx");
	OLED_ShowString(3,1,"Cnt:");

	while(1)
	{
		MyRTC_ReadTime();
		OLED_ShowNum(1,6,TimeData.tm_year + 1900,4);
		OLED_ShowNum(1,11,TimeData.tm_mon + 1,2);
		OLED_ShowNum(1,14,TimeData.tm_mday,2);
		OLED_ShowNum(2,6,TimeData.tm_hour,2);
		OLED_ShowNum(2,9,TimeData.tm_min,2);
		OLED_ShowNum(2,12,TimeData.tm_sec,2);
		OLED_ShowNum(3,5,RTC_GetCounter(),10);
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			MyRTC_SetTime();
		}
 	}
}
