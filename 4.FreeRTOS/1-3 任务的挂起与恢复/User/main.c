#include "stm32f10x.h"                  // Device header
#include "OLED.h" 
#include "freertos.h"
#include "task.h"
#include "LED.h"
#include "Key.h"
#include <stdio.h>
#include "Serial.h"

#define START_TASK_PRIO			0
#define START_TASK_STACK_SIZE	128
TaskHandle_t StartTaskHandler = NULL;

#define TASK1_PRIO			1
#define TASK1_STACK_SIZE	128
TaskHandle_t Task1Handler = NULL;

#define TASK2_PRIO			2
#define TASK2_STACK_SIZE	128
TaskHandle_t Task2Handler = NULL;

#define TASK3_PRIO			3
#define TASK3_STACK_SIZE	128
TaskHandle_t Task3Handler = NULL;


void Task1(void * pvParameters )
{ 
	uint32_t i = 0 ;
	while(1)
	{
		printf("Task1正在运行!!!%zu\r\n",i++);
		LED1_Turn();
		vTaskDelay(500);
	}
}

void Task2(void * pvParameters )
{ 
	uint32_t j = 0;
	while(1)
	{
		printf("Task2正在运行!!!%zu\r\n",j++);
		LED2_Turn();
		vTaskDelay(300);
	}
}

void Task3(void * pvParameters )
{
	uint8_t KeyNum = 0;
	while(1)
	{	
		//printf("Task3正在运行!!!\r\n");
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			printf("Task1已挂起\r\n");
			vTaskSuspend(Task1Handler);
		}else if(KeyNum == 2)
		{
			printf("Task1已恢复\r\n");
			vTaskResume(Task1Handler);
		}

		vTaskDelay(10);

	}
}

void Start_Task(void * pvParameters)
{
	taskENTER_CRITICAL();
	xTaskCreate(Task1,"Task1",TASK1_STACK_SIZE,NULL,TASK1_PRIO,&Task1Handler);
	xTaskCreate(Task2,"Task2",TASK2_STACK_SIZE,NULL,TASK2_PRIO,&Task2Handler);
	xTaskCreate(Task3,"Task3",TASK3_STACK_SIZE,NULL,TASK3_PRIO,&Task3Handler);

	taskEXIT_CRITICAL();
	vTaskDelete(NULL);
}
 
 
int main(void)
{
 
	LED_Init();
	Key_Init();
	Serial_Init();
	 
	xTaskCreate(Start_Task,"Start_Task"
				,START_TASK_STACK_SIZE,NULL
				,START_TASK_PRIO,&StartTaskHandler);
	vTaskStartScheduler();
	while (1)
	{
	 
	}
 
}