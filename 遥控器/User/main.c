#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"
#include "AD.h"
#include "Delay.h"

int main()
{
	OLED_Init();
	Key_Init();
	AD_Init();
	
	OLED_ShowString(1,1,"Warren's");
	
	uint8_t Num = 0;
	
	while(1)
	{
		Num          = Key_GetNum();
		if(Num)
			OLED_ShowNum(2,1,Num,2);
		//左摇杆
		OLED_ShowSignedNum(3,1,AD_GetValue(ADC_Channel_0)/41-49,4);
		OLED_ShowSignedNum(3,10,AD_GetValue(ADC_Channel_2)/41-49,4);
		//右摇杆		
		OLED_ShowSignedNum(4,1,AD_GetValue(ADC_Channel_1)/41-49,4);
		OLED_ShowSignedNum(4,10,AD_GetValue(ADC_Channel_3)/41-49,4);
		
	}
}
