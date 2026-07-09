#include <REGX52.H>
#include "I2C.h"
#include "Delay.h"

#define AT24C02_ADDRESS 0xA0

/**
  * @brief  AT24C02写入数据
  * @param  WordAddress 需要写入数据的字地址
  * @param  Data 需要写入的数据
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAddress,unsigned char Data)
{
	I2C_Start();
	I2C_WriteByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_WriteByte(WordAddress);
	I2C_ReceiveAck();
	I2C_WriteByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
	Delay(5);
}

/**
  * @brief   AT24C02读取数据
  * @param  WordAddress 需要读取数据的字地址
  * @retval 所读出的数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char byte = 0;
	I2C_Start();
	I2C_WriteByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_WriteByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_WriteByte(AT24C02_ADDRESS | 0x01);
	I2C_ReceiveAck();
	byte = I2C_ReadByte();
	I2C_SendAck(1);
	I2C_Stop();
	return byte;
}