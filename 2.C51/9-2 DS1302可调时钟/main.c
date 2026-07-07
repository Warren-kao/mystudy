#include <REGX52.H>
#include "DS1302.h"
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"
#include "Key.h"



char DS1302_Time []={26,7,5,23,59,55,7};
unsigned char num,MODE,KeyNum,SetFlag,SetFlagNum;

void ShowTime()
{
	if(MODE == 0)
	{
		LCD_ShowNum(1,1,DS1302_Time[0],2);//年
		LCD_ShowNum(1,4,DS1302_Time[1],2);//月
		LCD_ShowNum(1,7,DS1302_Time[2],2);//日
		LCD_ShowNum(2,1,DS1302_Time[3],2);//时
		LCD_ShowNum(2,4,DS1302_Time[4],2);//分
		LCD_ShowNum(2,7,DS1302_Time[5],2);//秒
		DS1302_ReadTime(DS1302_Time);
	}
	if(SetFlagNum && (SetFlag==0)&&(MODE==1))
	{
		LCD_ShowString(1,1,"  ");
	}else if(SetFlagNum && (SetFlag==1))
	{
		LCD_ShowString(1,4,"  ");
	}else if(SetFlagNum && (SetFlag==2))
	{
		LCD_ShowString(1,7,"  ");
	}else if(SetFlagNum && (SetFlag==3))
	{
		LCD_ShowString(2,1,"  ");
	}else if(SetFlagNum && (SetFlag==4))
	{
		LCD_ShowString(2,4,"  ");
	}else if(SetFlagNum && (SetFlag==5))
	{
		LCD_ShowString(2,7,"  ");
	}else
	{
		LCD_ShowNum(1,1,DS1302_Time[0],2);//年
		LCD_ShowNum(1,4,DS1302_Time[1],2);//月
		LCD_ShowNum(1,7,DS1302_Time[2],2);//日
		LCD_ShowNum(2,1,DS1302_Time[3],2);//时
		LCD_ShowNum(2,4,DS1302_Time[4],2);//分
		LCD_ShowNum(2,7,DS1302_Time[5],2);//秒
	}
	

	
}

void SetTime()
{
	if(KeyNum == 2)
	{
		SetFlag++;
		SetFlag %= 6;
	}
	if(KeyNum == 3)
	{
		DS1302_Time[SetFlag] ++;
		//年份判断
		DS1302_Time[0]%=100;
		//月份判断
		if(DS1302_Time[1] > 12)
		{
			DS1302_Time[1]=1;
		}
		//大小月判断
		if((DS1302_Time[1] == 1) || (DS1302_Time[1] == 3) || (DS1302_Time[1] == 5) || (DS1302_Time[1] == 7) || (DS1302_Time[1] == 8) || (DS1302_Time[1] == 10) || (DS1302_Time[1] == 12))
		{
			if(DS1302_Time[2]>31)
			{
				DS1302_Time[2] = 1;
			}
		}else if((DS1302_Time[1] == 4) || (DS1302_Time[1] == 6) || (DS1302_Time[1] == 9) || (DS1302_Time[1] == 11))
		{
			if(DS1302_Time[2]>30)
			{
				DS1302_Time[2] = 1;
			}
		//闰平年判断
		}else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0]%4 == 0)
			{
				if(DS1302_Time[2]>29)
				{
					DS1302_Time[2] = 1;
				}
			}else
			{
				if(DS1302_Time[2]>28)
				{
					DS1302_Time[2] = 1;
				}
			}
		}
		//时 判断
		DS1302_Time[3]%=25;
		//分 判断
		DS1302_Time[4]%=61;
		//秒 判断
		DS1302_Time[5]%=61;
	}

	if(KeyNum == 4)
	{
		DS1302_Time[SetFlag] --;
		//年份判断
		if(DS1302_Time[0] < 0)
		{
			DS1302_Time[0] = 99;
		}
		//月份判断
		if(DS1302_Time[1] < 1)
		{
			DS1302_Time[1]=12;
		}
		if((DS1302_Time[1] == 1) || (DS1302_Time[1] == 3) || (DS1302_Time[1] == 5) || (DS1302_Time[1] == 7) || (DS1302_Time[1] == 8) || (DS1302_Time[1] == 10) || (DS1302_Time[1] == 12))
		{
			if(DS1302_Time[2]>31)
			{
				DS1302_Time[2] = 1;
			}
		}else if((DS1302_Time[1] == 4) || (DS1302_Time[1] == 6) || (DS1302_Time[1] == 9) || (DS1302_Time[1] == 11))
		{
			if(DS1302_Time[2]>30)
			{
				DS1302_Time[2] = 1;
			}
		//闰平年判断
		}else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0]%4 == 0)
			{
				if(DS1302_Time[2]>29)
				{
					DS1302_Time[2] = 1;
				}
			}else
			{
				if(DS1302_Time[2]>28)
				{
					DS1302_Time[2] = 1;
				}
			}
		}
		//大小月判断
		if((DS1302_Time[1] == 1) || (DS1302_Time[1] == 3) || (DS1302_Time[1] == 5) || (DS1302_Time[1] == 7) || (DS1302_Time[1] == 8) || (DS1302_Time[1] == 10) || (DS1302_Time[1] == 12))
		{
			if(DS1302_Time[2]<1)
			{
				DS1302_Time[2] = 31;
			}
		}else if((DS1302_Time[1] == 4) || (DS1302_Time[1] == 6) || (DS1302_Time[1] == 9) || (DS1302_Time[1] == 11))
		{
			if(DS1302_Time[2] < 1)
			{
				DS1302_Time[2] = 30;
			}
		//闰平年判断
		}else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0]%4 == 0)
			{
				if(DS1302_Time[2]<1)
				{
					DS1302_Time[2] = 29;
				}
			}else
			{
				if(DS1302_Time[2]<1)
				{
					DS1302_Time[2] = 28;
				}
			}
		}
		//时 判断
		if(DS1302_Time[3] < 0)
		{
			DS1302_Time[3] = 59;
		}
		//分 判断
		if(DS1302_Time[4] < 0)
		{
			DS1302_Time[4] = 59;
		}
		//秒 判断
		if(DS1302_Time[5] < 0)
		{
			DS1302_Time[5] = 59;
		}
	}
	ShowTime();
}

void main()
{
	DS1302_Init();
	LCD_Init();
	Timer0_Init();
	

	DS1302_WriteTime(DS1302_Time);
	LCD_ShowString(1,1,"  -  -");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		KeyNum = GetKeyNum();
		if(KeyNum == 1)
		{
			if(MODE == 0){MODE = 1;}
			else if(MODE == 1){MODE = 0;DS1302_WriteTime(DS1302_Time);}
		}
		switch(MODE)
		{
			case 0 :ShowTime();break;
			case 1 :SetTime();break;
		}

	}
}

void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	if(T0Count >= 250)
	{
		SetFlagNum = !SetFlagNum;
		T0Count = 0;
	}
	
}