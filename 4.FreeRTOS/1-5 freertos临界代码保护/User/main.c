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
	while(1)
	{
		printf("Task1正在运行!!!\r\n");
		LED1_Turn();
		vTaskDelay(500);
	}
}

void Task2(void * pvParameters )
{ 
	while(1)
	{
		printf("Task2正在运行!!!\r\n");
		LED2_Turn();
		vTaskDelay(300);
	}
}

void Task3(void * pvParameters )
{
	uint8_t KeyNum = 0;
	while(1)
	{	
		printf("Task3正在运行!!!\r\n");
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			if(Task1Handler != NULL)
			{
				printf("Task1已删除\r\n");
				vTaskDelete(Task1Handler);	
				Task1Handler = NULL;
			}else{
				xTaskCreate(Task1,"Task1",TASK1_STACK_SIZE,NULL,TASK1_PRIO,&Task1Handler);
			}

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