#ifndef __W25Q64_H__
#define __W25Q64_H__

extern struct
{
	uint8_t MID;
	uint16_t DID;
}W25Q64_ID;

void W25Q64_Init();
void W25Q64_ReadID();
void W25Q64_PageProgram(uint32_t Address,uint8_t * Data,uint16_t Count);
void W25Q64_ClearPage(uint32_t Address);
void W25Q64_ReadData(uint32_t Address,uint8_t * Data,uint32_t Count);
#endif