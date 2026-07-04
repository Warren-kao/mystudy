#include <REGX52.H>
#include "Delay.h"
#include "main.h"




/**
  * @brief  74HC595写入一个字节
  * @param  Byte需要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char count;
	for(count = 0;count < 8;count++)
	{
		SER = Byte & (0x80>>count);
		SCK = 1;
		SCK = 0;
	
	}
	RCK = 1;
	RCK = 0;
	
}


/**
  * @brief  LED矩阵屏写入每列数据
  * @param  Column需要写入数据的段码,取值范围0~7,0在左,7在右
  * @param  Data需要写入段码的数据,高位在上,低位在下
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,unsigned char Data)
{
	//P0 = 0xFF;
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80>>Column);

	Delay(1);
	MATRIX_LED_PORT = 0xFF;
	
	
}


/**
  * @brief  LED矩阵屏的初始化
  * @param  无
  * @retval 无
  */
void MatrixLED_Init()
{
	RCK = 0;
	SCK = 0;
	SER = 0;

}