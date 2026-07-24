#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "AD.h"
#include "Delay.h"


int main()
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1,1,"AD0:");
	OLED_ShowString(2,1,"AD1:");
	OLED_ShowString(3,1,"AD2:");
	OLED_ShowString(4,1,"AD3:");

	
	while(1)
	{

		OLED_ShowNum(1,5,ADArr[0],5);
		OLED_ShowNum(2,5,ADArr[1],5);
		OLED_ShowNum(3,5,ADArr[2],5);
		OLED_ShowNum(4,5,ADArr[3],5);
		
		
		Delay_ms(100);

	}
}
