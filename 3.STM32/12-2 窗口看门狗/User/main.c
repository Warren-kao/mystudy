#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Key.h"

int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"WWDG TEST");
	if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST) == SET)
	{
		OLED_ShowString(2,1,"WWDG RST");
		Delay_ms(500);
		OLED_ShowString(2,1,"        ");
		
		RCC_ClearFlag();
	}else
	{
		OLED_ShowString(3,1,"RST");
		Delay_ms(500);
		OLED_ShowString(3,1,"    ");
	}
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	WWDG_SetWindowValue(0x40 | 21);

	WWDG_Enable(0x40 | 54);
	
	
	while(1)
	{
		Key_GetNum();
		IWDG_ReloadCounter();
		OLED_ShowString(4,1,"FEED");
		Delay_ms(20);
		OLED_ShowString(4,1,"    ");
		Delay_ms(20);
		WWDG_SetCounter(0x40 | 54);
		
	}
}
