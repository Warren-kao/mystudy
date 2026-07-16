#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoder.h"

int16_t Num;

int main()
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1,1,"Warren's");
	while(1)
	{
		Num += Encode_Get();
		OLED_ShowSignedNum(2,1,Num,5);
		
	}
}
