#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  读取矩阵键盘哪个数字被按下
  * @param  无
  * @retval 无符号zchar
			如果未松手,会卡在函数里
  */
unsigned char MatrixNum()
{
		unsigned char Num = 16;
		P1 = 0xFF;
		
		P1_3=0;
		if(!P1_7){Delay(20);while(!P1_7);Delay(20);Num = 7;}
		if(!P1_6){Delay(20);while(!P1_6);Delay(20);Num = 4;}
		if(!P1_5){Delay(20);while(!P1_5);Delay(20);Num = 1;}
		if(!P1_4){Delay(20);while(!P1_4);Delay(20);Num = 15;}
		
		P1 = 0xFF;
		P1_2=0;
		if(!P1_7){Delay(20);while(!P1_7);Delay(20);Num = 8;}
		if(!P1_6){Delay(20);while(!P1_6);Delay(20);Num = 5;}
		if(!P1_5){Delay(20);while(!P1_5);Delay(20);Num = 2;}
		if(!P1_4){Delay(20);while(!P1_4);Delay(20);Num = 0;}
		
		P1 = 0xFF;
		P1_1=0;
		if(!P1_7){Delay(20);while(!P1_7);Delay(20);Num = 9;}
		if(!P1_6){Delay(20);while(!P1_6);Delay(20);Num = 6;}
		if(!P1_5){Delay(20);while(!P1_5);Delay(20);Num = 3;}
		if(!P1_4){Delay(20);while(!P1_4);Delay(20);Num = 14;}

		P1 = 0xFF;
		P1_0=0;
		if(!P1_7){Delay(20);while(!P1_7);Delay(20);Num = 10;}
		if(!P1_6){Delay(20);while(!P1_6);Delay(20);Num = 11;}
		if(!P1_5){Delay(20);while(!P1_5);Delay(20);Num = 12;}
		if(!P1_4){Delay(20);while(!P1_4);Delay(20);Num = 13;}

			
		return Num;
}

int get ()
{
	int j = 4;
	P1 = 0x0F;
	if(!P1_3){while(P1_3);Delay(20);j = 0;}
	if(!P1_2){while(P1_2);Delay(20);j = 1;}
	if(!P1_1){while(P1_1);Delay(20);j = 2;}
	if(!P1_0){while(P1_0);Delay(20);j = 3;}
	
	return j;
}

//if换一种思路遍历
//可以用,但是局部变量修饰成为了全局变量,待改进
unsigned char getnum()
{
	char arr[4][4] = {{7,8,9,10},{4,5,6,11},{1,2,3,12},{15,0,14,13}};
		//unsigned char num = 16;
	static unsigned char i = 4, j = 4;
	unsigned char flag = 0;
		
	P1 = 0xF0;
	if(!P1_7){Delay(20);i = 0;flag = 1;}
	if(!P1_6){Delay(20);i = 1;flag = 1;}
	if(!P1_5){Delay(20);i = 2;flag = 1;}
	if(!P1_4){Delay(20);i = 3;flag = 1;}
	
	P1 = 0x0F;
	if(!P1_3){while(P1_3);Delay(20);j = 0;}
	if(!P1_2){while(P1_2);Delay(20);j = 1;}
	if(!P1_1){while(P1_1);Delay(20);j = 2;}
	if(!P1_0){while(P1_0);Delay(20);j = 3;}

	if(flag)
		return arr[i][j];
	else
		return 16;
}

