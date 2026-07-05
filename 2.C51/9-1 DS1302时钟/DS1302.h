#ifndef __DS1302_H_
#define __DS1302_H_

void DS1302_Init();
void DS1302_WriteData(unsigned char address,Data);
unsigned char DS1302_ReadData(unsigned char address);
void DS1302_WriteTime(unsigned char *[]);
void DS1302_readTime(unsigned char *[]);
#endif