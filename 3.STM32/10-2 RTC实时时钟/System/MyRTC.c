#include "stm32f10x.h"                  // Device header
#include "MyRTC.h"

struct tm TimeData = {
	.tm_sec = 0,   /* seconds after the minute, 0 to 60
                     (0 - 60 allows for the occasional leap second) */
	.tm_min = 0,   /* minutes after the hour, 0 to 59 */
	.tm_hour = 8,  /* hours since midnight, 0 to 23 */
	.tm_mday = 1,  /* day of the month, 1 to 31 */
	.tm_mon = 8 - 1,   /* months since January, 0 to 11 */
	.tm_year = 2026 - 1900,  /* years since 1900 */
};
time_t time_cnt;

void MyRTC_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	RCC_LSICmd(ENABLE);
	while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) != SET);
	
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
	RCC_RTCCLKCmd(ENABLE);
	if(BKP_ReadBackupRegister(BKP_DR1) == 0)
	{
		//低速外部晶振不起振,切换为内部低速晶振
		//RCC_LSEConfig(RCC_LSE_ON);
		//while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);
		
		
		//LSE时钟在备份域里,LSI不是,断电或者复位OLED会卡死,将下面四行移除if则可以运行,但是断电时时钟不会自增
//		RCC_LSICmd(ENABLE);
//		while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) != SET);
//		
//		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
//		RCC_RTCCLKCmd(ENABLE);
		
		RTC_WaitForSynchro();//等待同步
		RTC_WaitForLastTask();//等待上一个时钟完成
		
		RTC_SetPrescaler(32768 - 1);
		RTC_WaitForLastTask();
		
		MyRTC_SetTime();
		BKP_WriteBackupRegister(BKP_DR1,0x0001);
	}else
	{
		RTC_WaitForSynchro();//等待同步
		RTC_WaitForLastTask();//等待上一个时钟完成
	}


}

void MyRTC_ReadTime()
{
	time_cnt = RTC_GetCounter() + (8 * 3600);
	TimeData = *localtime(&time_cnt);
}

void MyRTC_SetTime()
{
	time_cnt = mktime(&TimeData) - (8 * 3600);
	RTC_SetCounter(time_cnt);
	RTC_WaitForLastTask();	
}


