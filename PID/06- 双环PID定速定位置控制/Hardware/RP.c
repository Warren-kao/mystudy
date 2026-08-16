#include "stm32f10x.h"                  // Device header

void RP_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	ADC_RegularChannelConfig(ADC2,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC2,&ADC_InitStruct);
	
	ADC_Cmd(ADC2,ENABLE);
	
	ADC_ResetCalibration(ADC2);
	while (ADC_GetResetCalibrationStatus(ADC2) == SET);
	ADC_StartCalibration(ADC2);
	while (ADC_GetCalibrationStatus(ADC2) == SET);

}

uint16_t RP_GetValue(uint8_t n)
{
	switch(n)
	{
		case 1 :ADC_RegularChannelConfig(ADC2,ADC_Channel_2,1,ADC_SampleTime_55Cycles5) ;break;
		case 2 :ADC_RegularChannelConfig(ADC2,ADC_Channel_3,1,ADC_SampleTime_55Cycles5) ;break;
		case 3 :ADC_RegularChannelConfig(ADC2,ADC_Channel_4,1,ADC_SampleTime_55Cycles5) ;break;
		case 4 :ADC_RegularChannelConfig(ADC2,ADC_Channel_5,1,ADC_SampleTime_55Cycles5) ;break;
	}

	ADC_SoftwareStartConvCmd(ADC2,ENABLE);
	while(ADC_GetFlagStatus(ADC2,ADC_FLAG_EOC) == RESET);
	return ADC_GetConversionValue(ADC2);
}




