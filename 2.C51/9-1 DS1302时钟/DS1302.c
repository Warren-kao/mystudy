#include <REGX52.H>

sbit DS1302_SCK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

void DS1302_Init()
{
	DS1302_SCK = 0;
	DS1302_IO = 0;
	DS1302_CE = 0;

}


unsigned char BCDto10(unsigned char byte)
{
	return ((byte/16*10)+(byte%16));
}

unsigned char _10toBCD(unsigned char byte)
{
	return ((byte/10*16)+(byte%10));
}

void DS1302_WriteData(unsigned char address,Data)
{
	unsigned char i;
	Data = _10toBCD(Data);
	DS1302_CE = 1;
	for(i = 0;i < 8 ; i++)
	{
		DS1302_IO = address & (0x01<<i);
		DS1302_SCK = 1;
		DS1302_SCK = 0;
	}
	
	for(i = 0;i < 8;i++)
	{
		DS1302_IO = Data & (0x01<<i);
		DS1302_SCK = 1;
		DS1302_SCK = 0;
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
}

unsigned char DS1302_ReadData(unsigned char address)
{
	unsigned char Data;

	unsigned char i;
	DS1302_CE = 1;
	for(i = 0;i < 8 ; i++)
	{
		DS1302_SCK = 0;
		DS1302_IO = address & (0x01<<i);
		DS1302_SCK = 1;
	}
	
	for(i = 0;i < 8;i++)
	{
		DS1302_SCK = 1;
		DS1302_SCK = 0;
		if(DS1302_IO){Data |= 0x01<<i;}
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Data = BCDto10(Data);
}

void DS1302_WriteTime(unsigned char *arr)
{
	unsigned char i ;
	for(i = 0;i<7;i++)
	{
		DS1302_WriteData(0x8C-(2*i),*(arr+i));
	}
}
void DS1302_readTime(unsigned char *arr)
{
	unsigned char i ;
	for(i = 0;i<7;i++)
	{
		*(arr+i) = DS1302_ReadData(0x8D-2*i);
	}
}