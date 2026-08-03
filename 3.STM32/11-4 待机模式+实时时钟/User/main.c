#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"
#include "MyRTC.h"
#include "Delay.h"

uint8_t KeyNum;

int main()
{
	//本节开始,电路板替换为FreeRtos电路板,I2C换为SCL PB6,SDA PB7
	OLED_Init();
	//按键替换为PB14
	Key_Init();
	MyRTC_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	
	OLED_ShowString(1,1,"CNT:");
	OLED_ShowString(2,1,"ALR:");
	OLED_ShowString(3,1,"ALRF:");

	PWR_WakeUpPinCmd(ENABLE);	
	
	uint32_t Alarm = RTC_GetCounter() + 10;
	RTC_SetAlarm(Alarm);
	
	OLED_ShowNum(2,6,Alarm,10);


	while(1)
	{
		OLED_ShowNum(1,6,RTC_GetCounter(),10);
		OLED_ShowNum(3,6,RTC_GetFlagStatus(RTC_FLAG_ALR),10);
		
		OLED_ShowString(4,1,"Running:");
		Delay_ms(100);
		OLED_ShowString(4,1,"        ");
		Delay_ms(100);
		
		OLED_Clear();
		
		PWR_EnterSTANDBYMode();

 	}
}
