#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"

int16_t Speed;

int main()
{
	OLED_Init();
	Timer_Init();
	Encoder_Init();

	OLED_ShowString(1,1,"CNT:");
	while(1)
	{
		OLED_ShowSignedNum(1,5,Speed,5);
	}
}


void TIM2_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM2,TIM_IT_Update) == SET)
	{
		
		Speed = Encoder_Get();
		TIM_ClearFlag(TIM2,TIM_IT_Update);
	}
	
}


