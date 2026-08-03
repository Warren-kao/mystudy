#ifndef __MYRTC_H__
#define __MYRTC_H__
#include <time.h>

extern struct tm TimeData;
extern time_t time_cnt;

void MyRTC_Init();
void MyRTC_ReadTime();
void MyRTC_SetTime();

#endif