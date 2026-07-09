#include <REGX52.H>

sbit OneWire_DQ = P3^7;

bit OneWire_Init()
{
	unsigned char i;
	bit ack;
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	i = 247;while (--i);//Delay 500us
	OneWire_DQ = 1;
	i = 32;while (--i);//Delay  70us
	ack = OneWire_DQ;
	i = 247;while (--i);//Delay  500us
	return ack;
}

void OneWire_WriteBit(bit Bit)
{
	unsigned char i;
	OneWire_DQ = 0;
	i = 4;while (--i);//Delay 10us
	OneWire_DQ = Bit;
	i = 24;while (--i);//Delay 50us
	OneWire_DQ = 1;
}

bit OneWire_ReadBit()
{
	bit Bit;
	unsigned char i;
	OneWire_DQ = 0;
	i = 2;while (--i);//Delay 5us
	OneWire_DQ = 1;
	i = 2;while (--i);//Delay 5us
	Bit = OneWire_DQ;
	i = 24;while (--i);//Delay 50us
	return Bit;
}

void OneWire_WriteByte(unsigned char byte)
{
	unsigned char i;
	
	for(i = 0;i<8;i++)
	{
		OneWire_WriteBit(byte&(0x01<<i));
	}
	
}

unsigned char OneWire_ReadByte()
{
	unsigned char i;
	unsigned char byte = 0x00;
	for(i = 0;i<8; i++)
	{
		if(OneWire_ReadBit()){byte |= (0x01<<i);}
	}
	return byte;
}