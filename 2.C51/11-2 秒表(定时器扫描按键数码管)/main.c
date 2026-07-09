#include <REGX52.H>
#include "Dealy.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"
#include "AT24C02.h"

unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
			RunFlag = !RunFlag;
		}else if(KeyNum == 2)
		{
			Min = 0;
			Sec = 0;
			MiniSec = 0;
		}else if(KeyNum == 3)
		{
			AT24C02_WriteByte(0,MiniSec);
			AT24C02_WriteByte(1,Sec);
			AT24C02_WriteByte(2,Min);
		}else if(KeyNum == 4)
		{
			MiniSec = AT24C02_ReadByte(0);
			Sec = AT24C02_ReadByte(1);
			Min = AT24C02_ReadByte(2);
		}
		Nixie_Set(1,Min/10);
		Nixie_Set(2,Min%10);
		Nixie_Set(3,11);
		Nixie_Set(4,Sec/10);
		Nixie_Set(5,Sec%10);
		Nixie_Set(6,11);
		Nixie_Set(7,MiniSec/10);
		Nixie_Set(8,MiniSec%10);
	}
}

void Sec_Loop()
{
	if(RunFlag)
	{
		MiniSec++;
		if(MiniSec > 99)
		{
			MiniSec=0;
			Sec++;	
		}
		if(Sec>=60)
		{
			Sec=0;
			Min++;	
		} 
		if(Min>=60)
		{
			Min=0;
		}
	}
}

void Timer0_Rountine() interrupt 1
{	
	static unsigned int T0Count1,T0Count2,T0Count3;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count1++;
	T0Count2++;
	T0Count3++;
	if(T0Count1 >= 20)
	{
		Key_Loop();
		T0Count1 = 0; 
	}
	if(T0Count2 >= 2)
	{
		Nixie_Loop();
		T0Count2 = 0; 
	}
	if(T0Count3 >= 10)
	{
		Sec_Loop();
		T0Count3 = 0; 
	}
	
}