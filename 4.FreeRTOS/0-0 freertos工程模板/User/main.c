#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "freertos.h"
#include "task.h"


static TaskHandle_t myTaskHandler = NULL;
 
void myTask(void *arg )
{ 
	while(1)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		vTaskDelay(500);
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		vTaskDelay(500);
	}
}
 
int main(void)
{
 
	GPIO_InitTypeDef GPIO_Initstruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_13;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_Initstruct);
	
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	 

	xTaskCreate(myTask,"myTask",512,NULL,2,&myTaskHandler);
	 
	vTaskStartScheduler();
 
	while (1)
	{
	 
	}
 
}