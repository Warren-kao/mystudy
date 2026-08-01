#include "stm32f10x.h"                  // Device header
#include "MySPI.h"
#include "W25Q64_Ins.h"

struct
{
	uint8_t MID;
	uint16_t DID;
}W25Q64_ID;

void W25Q64_Init()
{
	MySPI_Init();
}

void W25Q64_WriteEnable()
{
	MySPI_Start();
	MySPI_SwapByte(W25Q64_WRITE_ENABLE);
	MySPI_Stop();
}

void W25Q64_ReadID()
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_JEDEC_ID);
	W25Q64_ID.MID = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	W25Q64_ID.DID = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	W25Q64_ID.DID <<= 8;
	W25Q64_ID.DID |= MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	MySPI_Stop();
}


void W25Q64_WaitBusy()
{
	uint32_t Timeout = 100000;
	MySPI_Start();
	while ((MySPI_SwapByte(W25Q64_READ_STATUS_REGISTER_1) & 0x01) == 1)
	{
		Timeout--;
		if(Timeout == 0)
		{
			break;
		}
	}
	MySPI_Stop();
}

void W25Q64_PageProgram(uint32_t Address,uint8_t * Data,uint16_t Count)
{
	uint32_t i;
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_PAGE_PROGRAM);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);
	for(i = 0;i < Count;i++)
	{
		MySPI_SwapByte(Data[i]);
	}
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_ClearPage(uint32_t Address)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_ReadData(uint32_t Address,uint8_t * Data,uint32_t Count)
{
	uint32_t i;
	MySPI_Start();
	MySPI_SwapByte(W25Q64_READ_DATA);
	MySPI_SwapByte(Address >> 16);
	MySPI_SwapByte(Address >> 8);
	MySPI_SwapByte(Address);
	for(i = 0;i < Count;i++)
	{
		Data[i] = MySPI_SwapByte(W25Q64_DUMMY_BYTE);
	}
	MySPI_Stop();
}


