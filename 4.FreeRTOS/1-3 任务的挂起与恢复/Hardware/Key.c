#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "freertos.h"

void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}

uint8_t Key_GetNum()
{
	uint8_t Num=0;
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_14) == 0)
	{
		vTaskDelay(10);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_14) == 0);
		vTaskDelay(10);
		Num = 1;
	}else if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_15) == 0)
	{
		vTaskDelay(10);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_15) == 0);
		vTaskDelay(10);
		Num = 2;
	}
	return Num;
}



