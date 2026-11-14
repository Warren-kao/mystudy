#include "stm32f10x.h"                  // Device header

void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_15 | GPIO_Pin_2);
}

void LED1_ON()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);
}

void LED1_OFF()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
}

void LED2_ON()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void LED2_OFF()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED1_Turn()
{
	GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_15)?LED1_ON():LED1_OFF();
}

void LED2_Turn()
{
	GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)?LED2_ON():LED2_OFF();
}


