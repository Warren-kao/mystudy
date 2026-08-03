#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Key.h"

int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"IWDG TEST");
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == SET)
	{
		OLED_ShowString(2,1,"IWDG RST");
		Delay_ms(500);
		OLED_ShowString(2,1,"        ");
		
		RCC_ClearFlag();
	}else
	{
		OLED_ShowString(3,1,"RST");
		Delay_ms(500);
		OLED_ShowString(3,1,"    ");
	}

	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	IWDG_SetReload(2499);
	IWDG_ReloadCounter();
	IWDG_Enable();
	while(1)
	{
		Key_GetNum();
		IWDG_ReloadCounter();
		OLED_ShowString(4,1,"FEED");
		Delay_ms(200);
		OLED_ShowString(4,1,"    ");
		Delay_ms(600);

		
	}
}
