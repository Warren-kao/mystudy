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


uint8_t KeyNum;
int16_t PWM,Speed;
float Target,Actual,Out;
float Kp,Ki,Kd = 5;
float Error0,Error1,ErrorInt;

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

		Kp = RP_GetValue(1) / 4095.0 * 3;
		Ki = RP_GetValue(2) / 4095.0 * 2;
		Kd = RP_GetValue(3) / 4095.0 * 2;
		Target =  RP_GetValue(4) / 4095.0 * 300 -150;
		
		OLED_Printf(0,16,OLED_8X16,"Kp:%+4.2f",Kp);
		OLED_Printf(0,32,OLED_8X16,"Ki:%+4.2f",Ki);
		OLED_Printf(0,48,OLED_8X16,"Kd:%+4.2f",Kd);
		
		OLED_Printf(64,16,OLED_8X16,"Tar:%+04.0f",Target);
		OLED_Printf(64,32,OLED_8X16,"Act:%+04.0f",Actual);
		OLED_Printf(64,48,OLED_8X16,"Out:%+04.0f",Out);
		
		printf("%+04.0f,%+04.0f,%+04.0f\r\n",Target,Actual,Out);

		
		OLED_Update();
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

			
			Actual = Encoder_Get();
			
			Error1 = Error0;
			Error0 = Target - Actual;
			
			if( Ki != 0)
			{
				ErrorInt += Error0;
			}
			
			
			Out = Kp * Error0 + Ki * ErrorInt + Kd * (Error0 - Error1);
			
			if(Out > 100){Out = 100;}
			if(Out < -100){Out = -100;}
			
			Motor_SetPWM(Out);

			
		}
		TIM_ClearFlag(TIM1,TIM_IT_Update);
	}
	
}


