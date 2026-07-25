#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdio.h>

void Serial_Init();
void Serial_SendByte(uint8_t Byte);
void Serial_SendArr(uint8_t* Arr,uint16_t Size);
void Serial_SendString(char* String);
void Serial_SendNum(uint32_t Num,uint8_t length);

#endif