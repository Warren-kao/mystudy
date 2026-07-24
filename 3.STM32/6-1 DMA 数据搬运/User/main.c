#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyDMA.h"
#include "Delay.h"

uint8_t Arr1[] = {0x1A,0x2B,0x3C,0x4D};
uint8_t Arr2[] = {0,0,0,0};

int main()
{
	OLED_Init();
	
	OLED_ShowString(1,1,"Arr1");
	OLED_ShowHexNum(1,6,(uint32_t)&Arr1,8);
	OLED_ShowString(3,1,"Arr2");
	OLED_ShowHexNum(3,6,(uint32_t)&Arr2,8);

	MyDMA_Init((uint32_t)Arr1,(uint32_t)Arr2,8);
	
	while(1)
	{
		Arr1[0]++;
		Arr1[1]++;
		Arr1[2]++;
		Arr1[3]++;
		OLED_ShowHexNum(2,1,Arr1[0],2);
		OLED_ShowHexNum(2,4,Arr1[1],2);
		OLED_ShowHexNum(2,7,Arr1[2],2);
		OLED_ShowHexNum(2,10,Arr1[3],2);

		Delay_ms(1000);
		
		MyDMA_Transfer();

		OLED_ShowHexNum(4,1,Arr2[0],2);
		OLED_ShowHexNum(4,4,Arr2[1],2);
		OLED_ShowHexNum(4,7,Arr2[2],2);
		OLED_ShowHexNum(4,10,Arr2[3],2);
		Delay_ms(1000);
	}
}
