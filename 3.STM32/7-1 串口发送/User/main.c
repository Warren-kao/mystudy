#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"


int main()
{
	OLED_Init();
	Serial_Init();
	//Serial_SendByte(0xCC);
	
	//uint8_t Arr[] = {0x1A,0x2B,0x3C,0x4D};
	//Serial_SendArr(Arr,sizeof(Arr)/sizeof(Arr[0]));
	//Serial_SendString("Hello Word!\r\n");
	//Serial_SendNum(54321,3);
	printf("你好,我是Warren",666);
	while(1)
	{

	}
}
