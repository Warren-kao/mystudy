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
#include "PID.h"


uint8_t KeyNum;
int16_t PWM,Speed,Location;
PID_t Inner = 
{
	.Kp = 1.3,
	.Ki = 0.25,
	.Kd = 0,
	
	.OutMax = 100,
	.OutMin = -100,
	
	.Dandband = 0,
};

PID_t Outer = 
{
	.Kp = 0.32,
	.Ki = 0,
	.Kd = 0.1,
	
	.OutMax = 150,
	.OutMin = -150,
	
	.Dandband = 0,
};
	

int main ()
{
	OLED_Init();
	Encoder_Init();
	Key_Init();
	Motor_Init();
	RP_Init();
	Timer_Init();
	Serial_Init();
	
	OLED_Printf(0,0,OLED_8X16,"Speed Control");
	OLED_Update();
	while(1)
	{

//		Inner.Kp = RP_GetValue(1) / 4095.0 * 3;
//		Inner.Ki = RP_GetValue(2) / 4095.0 * 2;
//		Inner.Kd = RP_GetValue(3) / 4095.0 * 2;
//		Inner.Target =  RP_GetValue(4) / 4095.0 * 300 -150;
//		
//		OLED_Printf(0,16,OLED_8X16,"Kp:%+4.2f",Inner.Kp);
//		OLED_Printf(0,32,OLED_8X16,"Ki:%+4.2f",Inner.Ki);
//		OLED_Printf(0,48,OLED_8X16,"Kd:%+4.2f",Inner.Kd);
//		
//		OLED_Printf(64,16,OLED_8X16,"Tar:%+04.0f",Inner.Target);
//		OLED_Printf(64,32,OLED_8X16,"Act:%+04.0f",Inner.Actual);
//		OLED_Printf(64,48,OLED_8X16,"Out:%+04.0f",Inner.Out);
//		
//		printf("%+04.0f,%+04.0f,%+04.0f\r\n",Inner.Target,Inner.Actual,Inner.Out);

		Outer.Kp = RP_GetValue(1) / 4095.0 * 3;
		Outer.Ki = RP_GetValue(2) / 4095.0 * 2;
		Outer.Kd = RP_GetValue(3) / 4095.0 * 2;
		Outer.Target =  RP_GetValue(4) / 4095.0 * 816 -408;
		
		OLED_Printf(0,16,OLED_8X16,"Kp:%+4.2f",Outer.Kp);
		OLED_Printf(0,32,OLED_8X16,"Ki:%+4.2f",Outer.Ki);
		OLED_Printf(0,48,OLED_8X16,"Kd:%+4.2f",Outer.Kd);
		
		OLED_Printf(64,16,OLED_8X16,"Tar:%+04.0f",Outer.Target);
		OLED_Printf(64,32,OLED_8X16,"Act:%+04.0f",Outer.Actual);
		OLED_Printf(64,48,OLED_8X16,"Out:%+04.0f",Outer.Out);
		
		printf("%+04.0f,%+04.0f,%+04.0f\r\n",Outer.Target,Outer.Actual,Outer.Out);
		OLED_Update();
		Delay_ms(10);
	}
}

void TIM1_UP_IRQHandler()
{
	static uint16_t count1,count2;
	if(TIM_GetFlagStatus(TIM1,TIM_IT_Update) == SET)
	{

		count1++;
		if(count1 >= 40)
		{
			count1 = 0;
			
			Speed = Encoder_Get();
			Location += Speed;
			
			Inner.Actual = Speed;
			
			PID_Update(&Inner);
			
			Motor_SetPWM(Inner.Out);
			
		}
		
		count2++;
		if(count2 >= 40)
		{
			count2 = 0;
			
			Outer.Actual = Location;
			
			PID_Update(&Outer);
			
			Inner.Target = Outer.Out;
			
		}
		TIM_ClearFlag(TIM1,TIM_IT_Update);
	}
	
}


