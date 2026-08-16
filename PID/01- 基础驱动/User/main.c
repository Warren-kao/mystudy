#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Timer.h"
#include "RP.h"
#include "Motor.h"
#include "Encoder.h"
#include "Serial.h"



//串口测试
uint16_t RP1,RP2,RP3,RP4;
int16_t Speed;
int16_t Location;
int main ()
{
	OLED_Init();
	RP_Init();
	Serial_Init();
	Encoder_Init();
	Timer_Init();
	while(1)
	{
		RP1 = RP_GetValue(1);
		RP2 = RP_GetValue(2);
		RP3 = RP_GetValue(3);
		RP4 = RP_GetValue(4);
		OLED_Printf(0,0,OLED_8X16,"RP1:%04d",RP1);
		OLED_Printf(0,16,OLED_8X16,"RP2:%04d",RP2);
		OLED_Printf(0,32,OLED_8X16,"RP3:%04d",RP3);
		OLED_Printf(0,48,OLED_8X16,"RP4:%04d",RP4);
		OLED_Update();
		
		printf("%d,%d,%d,%d,%d,%d\n",RP1,RP2,RP3,RP4,Speed,Location);
		Delay_ms(10);
	}
}

void TIM1_UP_IRQHandler()
{
	static uint16_t count;
	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
	{
		count++;
		if(count >= 40)
		{
			count = 0;
			Speed = Encoder_Get();
			Location += Speed;
		}
		TIM_ClearFlag(TIM1,TIM_IT_Update);
	}
	
}


//编码器测试
//int16_t Speed;
//int16_t Location;
//int main ()
//{
//	OLED_Init();
//	Encoder_Init();
//	Timer_Init();
//	while(1)
//	{
//		

//		OLED_Printf(0,0,OLED_8X16,"Speed:%+05d",Speed);
//		OLED_Printf(0,16,OLED_8X16,"Location:%+05d",Location);
//		
//		
//		OLED_Update();
//	}
//}

//void TIM1_UP_IRQHandler()
//{
//	static uint16_t count;
//	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
//	{
//		count++;
//		if(count >= 40)
//		{
//			Speed = Encoder_Get();
//			Location += Speed;
//		}
//		TIM_ClearFlag(TIM1,TIM_IT_Update);
//	}
//	
//}


//电机测试
//uint8_t KeyNum;
//int16_t PWM;
//int main ()
//{
//	OLED_Init();

//	Key_Init();
//	Motor_Init();
//	Timer_Init();
//	while(1)
//	{
//		if(Key_Check(KEY_1,KEY_UP))
//		{
//			PWM += 10;
//			if(PWM > 100)
//				PWM = 100;
//		}else if(Key_Check(KEY_2,KEY_UP))
//		{
//			PWM -= 10;
//			if(PWM < -100)
//				PWM = -100;
//		}else if(Key_Check(KEY_3,KEY_UP))
//		{
//			PWM = 0;
//		}else if(Key_Check(KEY_4,KEY_UP))
//		{
//			PWM = -PWM;
//		}

//		OLED_Printf(0,0,OLED_8X16,"PWM:%04d",PWM);
//		Motor_SetPWM(PWM);
//		
//		OLED_Update();
//	}
//}

//void TIM1_UP_IRQHandler()
//{
//	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
//	{
//		Key_Tick();
//		
//		TIM_ClearFlag(TIM1,TIM_IT_Update);
//	}
//	
//}


//电位器旋钮测试
//uint16_t i,j;
//int main ()
//{
//	OLED_Init();
//	RP_Init();
//	while(1)
//	{
//		OLED_Printf(0,0,OLED_8X16,"RP1:%04d",RP_GetValue(1));
//		OLED_Printf(0,16,OLED_8X16,"RP2:%04d",RP_GetValue(2));
//		OLED_Printf(0,32,OLED_8X16,"RP3:%04d",RP_GetValue(3));
//		OLED_Printf(0,48,OLED_8X16,"RP4:%04d",RP_GetValue(4));
//		OLED_Update();
//	}
//}


//按键测试
//uint16_t i,j;
//int main ()
//{
//	OLED_Init();
//	Timer_Init();
//	Key_Init();
//	while(1)
//	{
//		if(Key_Check(KEY_1,KEY_UP))
//		{
//			j ++;
//		}else if(Key_Check(KEY_2,KEY_UP))
//		{
//			j --;
//		}else if(Key_Check(KEY_3,KEY_UP))
//		{
//			j = 0;
//		}else if(Key_Check(KEY_4,KEY_UP))
//		{
//			j =999;
//		}
//		OLED_ShowNum(0,0,i,5,OLED_8X16);
//		OLED_ShowNum(0,16,j,5,OLED_8X16);
//		OLED_Update();
//	}
//}

//void TIM1_UP_IRQHandler()
//{
//	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
//	{
//		Key_Tick();
//		i++;
//		TIM_ClearFlag(TIM1,TIM_IT_Update);
//	}
//	
//}



//定时中断测试

//uint16_t i;
//int main ()
//{
//	OLED_Init();
//	Timer_Init();
//	while(1)
//	{
//		OLED_ShowNum(0,0,i,5,OLED_8X16);
//		OLED_Update();
//	}
//}

//void TIM1_UP_IRQHandler()
//{
//	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
//	{
//		
//		i++;
//		TIM_ClearFlag(TIM1,TIM_IT_Update);
//	}
//	
//}



//LED测试
//int main ()
//{
//	LED_Init();
//	
//	while(1)
//	{
//		LED_ON();
//		Delay_ms(500);
//		LED_OFF();
//		Delay_ms(500);
//		LED_Turn();
//		Delay_ms(500);
//		LED_Turn();
//		Delay_ms(500);
//	}
//}



//OLED测试
//int main()
//{
//	OLED_Init();
//	OLED_ShowString(0,0,"hello",OLED_8X16);
//	OLED_Update();
//	while(1)
//	{

//	}
//}
