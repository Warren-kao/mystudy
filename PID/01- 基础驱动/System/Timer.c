#include "stm32f10x.h"                  // Device header

void Timer_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	TIM_InternalClockConfig(TIM1);//定时器外部时钟来源
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 1000 - 1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 720 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);//初始化定时器
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	
	TIM_ClearFlag(TIM1,TIM_IT_Update);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC优先级分组
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);//初始化NVIC
	
	TIM_Cmd(TIM1,ENABLE);//开启定时器
}

/*定时中断模板
void TIM1_UP_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
	{
		
		
		TIM_ClearFlag(TIM1,TIM_IT_Update);
	}
	
}
*/


