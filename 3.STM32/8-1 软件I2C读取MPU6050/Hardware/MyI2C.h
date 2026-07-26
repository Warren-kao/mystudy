#ifndef __MYI2C_H__
#define __MYI2C_H__

void MyI2C_Init();
void MyI2C_Start();
void MyI2C_Stop();
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_ReadByte();
void MyI2C_SendAck(uint8_t Ack);
uint8_t MyI2C_ReadAck();

#endif