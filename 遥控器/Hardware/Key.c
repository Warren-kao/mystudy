#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}

uint8_t Key_GetNum()
{
	uint8_t Num=0;
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_6) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_6) == 0);
		Delay_ms(20);
		Num = 1;
	}
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_7) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_7) == 0);
		Delay_ms(20);
		Num = 2;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_0) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_0) == 0);
		Delay_ms(20);
		Num = 3;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_1) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_1) == 0);
		Delay_ms(20);
		Num = 4;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_2) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_2) == 0);
		Delay_ms(20);
		Num = 5;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_10) == 0);
		Delay_ms(20);
		Num = 6;
	}
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_11) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_11) == 0);
		Delay_ms(20);
		Num = 7;
	}
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_12) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_12) == 0);
		Delay_ms(20);
		Num = 8;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_5) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_5) == 0);
		Delay_ms(20);
		Num = 9;
	}
	if(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_6) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB ,GPIO_Pin_6) == 0);
		Delay_ms(20);
		Num = 10;
	}
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_4) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_4) == 0);
		Delay_ms(20);
		Num = 11;
	}
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_5) == 0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_5) == 0);
		Delay_ms(20);
		Num = 12;
	}
	return Num;
}



