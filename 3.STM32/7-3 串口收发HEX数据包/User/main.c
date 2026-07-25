#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"
#include "Key.h"

uint8_t RxData;

int main()
{
	OLED_Init();
	Serial_Init();
	Key_Init();
	OLED_ShowString(1,1,"RxData:");
	OLED_ShowString(3,1,"TxData:");
	Serial_TxPacket[0] = 0x11;
	Serial_TxPacket[1] = 0x22;
	Serial_TxPacket[2] = 0x33;
	Serial_TxPacket[3] = 0x44;

	while(1)
	{
		if(Key_GetNum() == 1 )
		{
			Serial_SendPacket(Serial_TxPacket,4);
			OLED_ShowHexNum(4,1,Serial_TxPacket[0],2);
			OLED_ShowHexNum(4,4,Serial_TxPacket[1],2);
			OLED_ShowHexNum(4,7,Serial_TxPacket[2],2);
			OLED_ShowHexNum(4,10,Serial_TxPacket[3],2);
			Serial_TxPacket[0] ++;
			Serial_TxPacket[1] ++;
			Serial_TxPacket[2] ++;
			Serial_TxPacket[3] ++;
		}
		if(Serial_GetRxFlag() == 1)
		{
			OLED_ShowHexNum(2,1,Serial_RxPacket[0],2);
			OLED_ShowHexNum(2,4,Serial_RxPacket[1],2);
			OLED_ShowHexNum(2,7,Serial_RxPacket[2],2);
			OLED_ShowHexNum(2,10,Serial_RxPacket[3],2);
		}
	}
}
