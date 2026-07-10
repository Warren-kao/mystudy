#include <REGX52.H>
/**
  * @brief  定时器0初始化,1毫秒@12.000MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init()//1毫秒@12.000MHz
{
	TMOD &= 0xF0;//高地址不变,低地址清零
	TMOD |= 0x01;//最低位置1,16位模式
	
	//TCON
	TF0 = 0;//标志位清零
	TR0 = 1;//定时器开启
	//TH0 = 24535 / 255;//计数器高位寄存器
	//TL0 = 24535 % 255 + 1;//计数器低位寄存器
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	//中断控制
	ET0 = 1;//定时器中断开启
	EA = 1;//中断开启
	PT0 = 0;//优先级为低

}

/**
  * @brief  定时器中断函数模板
  * @param  无
  * @retval 
  */
//void Timer0_Rountine() interrupt 1
//{	
//	static unsigned int T0Count;
//	TH0 = 0xFC;
//	TL0 = 0x18;
//	T0Count++;
//	if(T0Count >= 1000)
//	{
//		T0Count = 0; 
//	}
//	
//}