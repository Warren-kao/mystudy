#include "stm32f10x.h"                  // Device header
#include "OLED.h"


int main()
{
	OLED_Init();
	OLED_ShowString(1,1,"Warren's");
	OLED_ShowNum(2,1,666,3);
	
	while(1)
	{

	}
}
