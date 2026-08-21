#include "stm32f10x.h"                  // Device header
#include "freertos.h"
#include "task.h"
#include <stdio.h>
#include "Serial.h"
#include "Timer.h"
#include "Delay.h"

#define START_TASK_PRIO			0
#define START_TASK_STACK_SIZE	128
TaskHandle_t StartTaskHandler = NULL;

#define TASK1_PRIO			1
#define TASK1_STACK_SIZE	128
TaskHandle_t Task1Handler = NULL;



void Task1(void * pvParameters )
{ 
	uint8_t Task_Num = 0;
	while(1)
	{
		if(++Task_Num == 5)
		{
			printf("关闭中断\r\n");
			portDISABLE_INTERRUPTS();
			Delay_s(5);
			printf("开启中断\r\n");
			portENABLE_INTERRUPTS();
			Task_Num = 0;
		}
		//printf("Task1正在运行!!!\r\n");
		vTaskDelay(1000);
	}
}


void Start_Task(void * pvParameters)
{
	taskENTER_CRITICAL();
	xTaskCreate(Task1,"Task1",TASK1_STACK_SIZE,NULL,TASK1_PRIO,&Task1Handler);


	vTaskDelete(NULL);
	taskEXIT_CRITICAL();
}
 
 
int main(void)
{

	Serial_Init();
	Timer_Init();
	 
	xTaskCreate(Start_Task,"Start_Task"
				,START_TASK_STACK_SIZE,NULL
				,START_TASK_PRIO,&StartTaskHandler);
	vTaskStartScheduler();
	while (1)
	{
	 
	}
 
}


void TIM2_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM2,TIM_IT_Update) == SET)
	{
		printf("中断优先级4任务!!\r\n");
		
		TIM_ClearFlag(TIM2,TIM_IT_Update);
	}
	
}

void TIM3_IRQHandler()
{
	if(TIM_GetFlagStatus(TIM3,TIM_IT_Update) == SET)
	{
		printf("中断优先级6任务!!!!!!!\r\n");
		
		TIM_ClearFlag(TIM3,TIM_IT_Update);
	}
	
}




