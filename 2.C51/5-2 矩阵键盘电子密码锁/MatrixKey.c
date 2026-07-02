#include <REGX52.H>
#include "Delay.h"

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