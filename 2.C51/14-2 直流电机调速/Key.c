#include <REGX52.H>

static unsigned char num;

unsigned char Key()
{
	unsigned char temp;
	temp = num;
	num = 0;
	return temp;
}

/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char GetKey()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char NowState,LastState;
	LastState = NowState;
	NowState = GetKey();
	if(LastState==1&&NowState==0)
	{
		num = 1;
	}else if(LastState==2&&NowState==0)
	{
		num = 2;
	}else if(LastState==3&&NowState==0)
	{
		num = 3;
	}else if(LastState==4&&NowState==0)
	{
		num = 4;
	}
}


/**
  * @brief  定时器扫描按键模板
  * @param  
  * @retval 
  */
//void Timer0_Rountine() interrupt 1
//{	
//	static unsigned int T0Count;
//	TH0 = 0xFC;
//	TL0 = 0x18;
//	T0Count++;
//	if(T0Count >= 20)
//	{
//		Key_Loop();
//		T0Count = 0; 
//	}
//	
//}