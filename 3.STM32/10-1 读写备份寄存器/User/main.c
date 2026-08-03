#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"

uint16_t ArrWite[] = {0x1234,0x5678};
uint8_t KeyNum;

int main()
{
	//本节开始,电路板替换为FreeRtos电路板,I2C换为SCL PB6,SDA PB7
	OLED_Init();
	//按键替换为PB14
	Key_Init();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	OLED_ShowString(1,1,"W:");
	OLED_ShowString(3,1,"R:");
	OLED_ShowHexNum(2,1,ArrWite[0],4);
	OLED_ShowHexNum(2,6,ArrWite[1],4);
	
	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			BKP_WriteBackupRegister(BKP_DR1,ArrWite[0]);
			BKP_WriteBackupRegister(BKP_DR2,ArrWite[1]);
			OLED_ShowHexNum(2,1,ArrWite[0]++,4);
			OLED_ShowHexNum(2,6,ArrWite[1]++,4);
		}


		OLED_ShowHexNum(4,1,BKP_ReadBackupRegister(BKP_DR1),4);
		OLED_ShowHexNum(4,6,BKP_ReadBackupRegister(BKP_DR2),4);
	}
}
