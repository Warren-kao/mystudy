#include "stm32f10x.h"                  // Device header
#include <stdio.h>

uint8_t Serial_RxData;//串口读数据
uint8_t Serial_RxFlag;//串口读数据标志位
uint8_t Serial_RxPacket[100];
uint8_t Serial_TxPacket[4];

void Serial_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}

void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1, Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}

void Serial_SendArr(uint8_t* Arr,uint16_t Size)
{
	uint16_t i;
	for(i = 0;i < Size ; i++)
	{
		Serial_SendByte(Arr[i]);
	}
}

void Serial_SendPacket(uint8_t* Arr,uint16_t Size)
{
	uint16_t i;
	Serial_SendByte(0xFF);
	for(i = 0;i < Size ; i++)
	{
		Serial_SendByte(Arr[i]);
	}
	Serial_SendByte(0xFE);
}

void Serial_SendString(char* String)
{
	while(*String)
	{
		Serial_SendByte( *String);
		String++;
	}
}


uint32_t Serial_Pow(uint32_t x,uint8_t y)
{
	uint32_t Ret = 1;
	while(y--)
	{
		Ret *= x;
	}
	return Ret;
}

void Serial_SendNum(uint32_t Num,uint8_t length)
{
	uint8_t i;
	for(i = 0;i < length ; i++)
	{
		Serial_SendByte(Num / Serial_Pow(10,length-i-1) % 10 + '0');
	}
}

int fputc(int ch,FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

uint8_t Serial_GetData()
{
	return Serial_RxData;
}



void USART1_IRQHandler()
{
	static uint8_t pArr;
	static uint8_t RxState;
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == SET)
	{
		uint8_t RxData = USART_ReceiveData(USART1);
		if(RxState == 0)
		{
			if(RxData == '@' && Serial_RxFlag == 0)
			{
				RxState = 1;
				pArr = 0;
			}
		}else if(RxState == 1)
		{
			if(RxData == '\r')
			{
				RxState = 2;
			}else
			{
				Serial_RxPacket[pArr++] = RxData;
			}
		}else if(RxState == 2)
		{
			if(RxData == '\n')
			{
				Serial_RxFlag = 1;
				Serial_RxPacket[pArr] = '\0';
				RxState = 0;
			}
		}
		USART_ClearFlag(USART1,USART_FLAG_RXNE);

	}	
}


