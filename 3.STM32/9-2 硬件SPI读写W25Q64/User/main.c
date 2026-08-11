#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "W25Q64.h"

uint8_t ArrWrite[] = {0x01,0x02,0x03,0x04};
uint8_t ArrRead[4];
int main()
{
	OLED_Init();
	W25Q64_Init();

	
	OLED_ShowString(1,1,"MID:   DID:");
	W25Q64_ReadID();
	OLED_ShowHexNum(1,5,W25Q64_ID.MID,2);
	OLED_ShowHexNum(1,12,W25Q64_ID.DID,4);
	OLED_ShowString(2,1,"W:");
	OLED_ShowString(3,1,"R:");
	
	W25Q64_ClearPage(0x000000);
	
	W25Q64_PageProgram(0x000000,ArrWrite,4);
	W25Q64_ReadData(0x000000,ArrRead,4);
	OLED_ShowHexNum(2,3,ArrWrite[0],2);
	OLED_ShowHexNum(2,6,ArrWrite[1],2);
	OLED_ShowHexNum(2,9,ArrWrite[2],2);
	OLED_ShowHexNum(2,12,ArrWrite[3],2);

	OLED_ShowHexNum(3,3,ArrRead[0],2);
	OLED_ShowHexNum(3,6,ArrRead[1],2);
	OLED_ShowHexNum(3,9,ArrRead[2],2);
	OLED_ShowHexNum(3,12,ArrRead[3],2);
	
	while(1)
	{

	}
	
}
