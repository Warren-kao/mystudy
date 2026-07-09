#include <REGX52.H>
#include "OneWire.h"

#define DS1802B20_SKIP_ROM				0xCC//跳过地址验证
#define DS1802B20_CONVERT_T				0x44//开启温度转换
#define DS1802B20_READ_SCRATCHPAD		0xBE//读取寄存器

void DS18B20_ConvertT()
{
	OneWire_Init();
	OneWire_WriteByte(DS1802B20_SKIP_ROM);
	OneWire_WriteByte(DS1802B20_CONVERT_T);
}

float DS18B20_ReadT()
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();
	OneWire_WriteByte(DS1802B20_SKIP_ROM);
	OneWire_WriteByte(DS1802B20_READ_SCRATCHPAD);
	TLSB = OneWire_ReadByte();
	TMSB = OneWire_ReadByte();
	Temp = (TMSB<<8)|TLSB;
	T = Temp/16.0;
	return T;
}