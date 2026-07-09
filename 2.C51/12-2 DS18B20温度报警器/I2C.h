#ifndef __I2C_H__
#define __I2C_H__

void I2C_Start();
void I2C_Stop();
void I2C_WriteByte(unsigned char byte);
unsigned char I2C_ReadByte();
void I2C_SendAck(bit ack);
bit I2C_ReceiveAck();

#endif