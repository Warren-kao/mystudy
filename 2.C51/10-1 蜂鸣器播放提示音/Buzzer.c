#include <REGX52.H>
#include <intrins.h>

//蜂鸣器端口：
sbit Buzzer=P2^5;

/**
  * @brief  Buzzer延迟函数,500微秒,一秒钟2000次,1000Hz
  * @param  无
  * @retval 无
  */
void Buzzer_Delay()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}


/**
  * @brief  蜂鸣器发出声音
  * @param  ms 声音的时间,单位毫秒,范围0~65535
  * @retval 无
  */
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay();
	}
}