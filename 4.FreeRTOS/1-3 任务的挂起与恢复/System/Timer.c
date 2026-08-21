#include "stm32f10x.h"                  // Device header

void Timer_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 2 - 1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 2 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);//初始化定时器
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	TIM_ClearFlag(TIM2,TIM_IT_Update);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//NVIC优先级分组
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 5;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);//初始化NVIC
	
	TIM_Cmd(TIM2,ENABLE);//开启定时器
}

/*定时中断模板
void TIM2_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM2,TIM_IT_Update) == SET)
	{
		
		
		TIM_ClearFlag(TIM2,TIM_IT_Update);
	}
	
}
*/


