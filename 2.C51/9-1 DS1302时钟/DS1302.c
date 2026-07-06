#include <REGX52.H>

sbit DS1302_SCK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

/**
  * @brief  DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_SCK = 0;
	DS1302_IO = 0;
	DS1302_CE = 0;

}

/**
  * @brief  将BCD格式数转换为十进制整数
  * @param  byte 需要修改的BCD数
  * @retval 修改后的十进制整数
  */
unsigned char BCDto10(unsigned char byte)
{
	return ((byte/16*10)+(byte%16));
}

/**
  * @brief  将BCD格式数转换为十进制整数
  * @param  byte 需要修改十进制整数
  * @retval 修改后的的BCD数
  */
unsigned char _10toBCD(unsigned char byte)
{
	return ((byte/10*16)+(byte%10));
}

/**
  * @brief  DS1302写入数据
  * @param  address 需要写入数据的寄存器地址
  * @param  Data 需要写入的数据
  * @retval 无
  */
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

/**
  * @brief  DS1302读取数据
  * @param  address 需要读取数据的寄存器地址
  * @retval unsigned char 返回十进制整数
  */
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

/**
  * @brief  将数组内的日期写入DS1302
  * @param  *arr 需要写入的数组的指针
  * @retval 无
  */
void DS1302_WriteTime(unsigned char *arr)
{
	DS1302_WriteData(0x8C,*(arr+0));//年
	DS1302_WriteData(0x88,*(arr+1));//月
	DS1302_WriteData(0x86,*(arr+2));//日
	DS1302_WriteData(0x84,*(arr+3));//时
	DS1302_WriteData(0x82,*(arr+4));//分
	DS1302_WriteData(0x80,*(arr+5));//秒
	DS1302_WriteData(0x8A,*(arr+6));//周
}

/**
  * @brief  将DS1302内的日期写入数组
  * @param  *arr 需要写入的数组的指针
  * @retval 无
  */
void DS1302_readTime(unsigned char *arr)
{
	*(arr+0) = DS1302_ReadData(0x8D);//年
	*(arr+1) = DS1302_ReadData(0x89);//月
	*(arr+2) = DS1302_ReadData(0x87);//日
	*(arr+3) = DS1302_ReadData(0x85);//时
	*(arr+4) = DS1302_ReadData(0x83);//分
	*(arr+5) = DS1302_ReadData(0x81);//秒
	*(arr+6) = DS1302_ReadData(0x8B);//周
}