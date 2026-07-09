#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

/**
  * @brief  I2C结束
  * @param  无
  * @retval 无
  */
void I2C_Stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

/**
  * @brief  I2C写输入
  * @param  byte 需要写入的字节
  * @retval 无
  */
void I2C_WriteByte(unsigned char byte)
{
	unsigned char i;
	for(i = 0;i<8;i++)
	{
		I2C_SDA = byte & (0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

/**
  * @brief  I2C读字节
  * @param  无
  * @retval 需要读取的字节
  */
unsigned char I2C_ReadByte()
{
	unsigned char i,byte;
	I2C_SDA = 1;
	byte = 0x00;
	for(i = 0;i <8; i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA){byte |= (0x80>>i);}
		I2C_SCL = 0;
	}
	return byte;
}

/**
  * @brief  I2C回复应答
  * @param  ack 需要应答的内容,0为接收,1为未接收
  * @retval 无
  */
void I2C_SendAck(bit ack)
{
	I2C_SDA = ack;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

/**
  * @brief  I2C接收应答
  * @param  无
  * @retval 接收到的应答数据,0为ok
  */
bit I2C_ReceiveAck()
{
	bit ack;
	I2C_SDA = 1;
	I2C_SCL = 1;
	ack = I2C_SDA;
	I2C_SCL = 0;
	return ack;
}