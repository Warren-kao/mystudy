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
StaticTask_t Start_Task_TCB;
StackType_t Start_Task_Stack[START_TASK_STACK_SIZE];

#define TASK1_PRIO			1
#define TASK1_STACK_SIZE	128
TaskHandle_t Task1Handler = NULL;
StaticTask_t Task1_Task_TCB;
StackType_t Task1_Stack[TASK1_STACK_SIZE];

#define TASK2_PRIO			2
#define TASK2_STACK_SIZE	128
TaskHandle_t Task2Handler = NULL;
StaticTask_t Task2_Task_TCB;
StackType_t Task2_Stack[TASK2_STACK_SIZE];

#define TASK3_PRIO			3
#define TASK3_STACK_SIZE	128
TaskHandle_t Task3Handler = NULL;
StaticTask_t Task3_Task_TCB;
StackType_t Task3_Stack[TASK3_STACK_SIZE];


StaticTask_t Idel_Task_TCB;//空闲任务控制块
StackType_t Idel_Task_Stack[configMINIMAL_STACK_SIZE]; //空闲任务堆栈
//空闲任务内存分配
void vApplicationGetIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                    StackType_t ** ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * puxIdleTaskStackSize )
{
	*ppxIdleTaskTCBBuffer = &Idel_Task_TCB;
	*ppxIdleTaskStackBuffer = Idel_Task_Stack;
	*puxIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	
}

StaticTask_t Timer_Task_TCB;//定时器任务控制块
StackType_t Timer_Task_Stack[configTIMER_TASK_STACK_DEPTH]; //定时器任务堆栈
//定时器任务内存分配
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
									StackType_t **ppxTimerTaskStackBuffer, 
									uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer = &Timer_Task_TCB;/* 任务控制块内存 */
	*ppxTimerTaskStackBuffer = Timer_Task_Stack;/* 任务堆栈内存 */
	*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;/* 任务堆栈大小 */
}

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
//	xTaskCreate(Task1,"Task1",TASK1_STACK_SIZE,NULL,TASK1_PRIO,&Task1Handler);
//	xTaskCreate(Task2,"Task2",TASK2_STACK_SIZE,NULL,TASK2_PRIO,&Task2Handler);
//	xTaskCreate(Task3,"Task3",TASK3_STACK_SIZE,NULL,TASK3_PRIO,&Task3Handler);
	
	Task1Handler= xTaskCreateStatic(   (TaskFunction_t ) Task1,
										(const char *   ) "Task1",     
										(uint32_t       ) TASK1_STACK_SIZE,  //任务堆栈大小
										(void *         ) NULL,
										(UBaseType_t    ) TASK1_PRIO,
										(StackType_t   *) Task1_Stack,
										(StaticTask_t  *) &Task1_Task_TCB );
	Task2Handler= xTaskCreateStatic(   (TaskFunction_t ) Task2,
										(const char *   ) "Task2",     
										(uint32_t       ) TASK2_STACK_SIZE,  //任务堆栈大小
										(void *         ) NULL,
										(UBaseType_t    ) TASK2_PRIO,
										(StackType_t   *) Task2_Stack,
										(StaticTask_t  *) &Task2_Task_TCB );
	Task3Handler= xTaskCreateStatic(   (TaskFunction_t ) Task3,
										(const char *   ) "Task3",     
										(uint32_t       ) TASK3_STACK_SIZE,  //任务堆栈大小
										(void *         ) NULL,
										(UBaseType_t    ) TASK3_PRIO,
										(StackType_t   *) Task3_Stack,
										(StaticTask_t  *) &Task3_Task_TCB );
	vTaskDelete(NULL);
	taskEXIT_CRITICAL();

}
 
 
int main(void)
{
 
	LED_Init();
	Key_Init();
	Serial_Init();
	 
	StartTaskHandler= xTaskCreateStatic(   (TaskFunction_t ) Start_Task,
											(const char *   ) "Start_Task",     
											(uint32_t       ) START_TASK_STACK_SIZE,  //任务堆栈大小
											(void *         ) NULL,
											(UBaseType_t    ) START_TASK_PRIO,
											(StackType_t   *) Start_Task_Stack,
											(StaticTask_t  *) &Start_Task_TCB );
	vTaskStartScheduler();
	while (1)
	{
	 
	}
 
}