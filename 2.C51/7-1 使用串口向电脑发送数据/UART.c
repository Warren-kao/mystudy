#include <REGX52.H>


void UART_Init()
{
	SCON = 0x40;//0100 0000
	//SM0 = 0;
	//SM1 = 1;//模式设置为8位无校验模式
	//TI = 0;//写标志
	//RI = 0;//读标志
	
	PCON &= 0x7F;//电源寄存器,最高两位是SMOD,SMOD0.  SMOD为1开启双倍频率
	
	//配置定时器1寄存器
	TMOD &= 0x0F;//低地址不变,高地址清零
	TMOD |= 0x20;//最低位置10,设定定时器1为8位自动重装方式



	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;//定时器开启
	
}

/**
  * @brief  使用串口发送一个字节的数据
  * @param  Byte
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
	
}