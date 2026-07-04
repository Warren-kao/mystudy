#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"
#include "main.h"



void main()
{
	MatrixLED_Init();

	while(1)
	{

		MatrixLED_ShowColumn(0,0x3C);	
		MatrixLED_ShowColumn(1,0x42);	
		MatrixLED_ShowColumn(2,0xA9);	
		MatrixLED_ShowColumn(3,0x85);	
		MatrixLED_ShowColumn(4,0x85);	
		MatrixLED_ShowColumn(5,0xA9);	
		MatrixLED_ShowColumn(6,0x42);	
		MatrixLED_ShowColumn(7,0x3C);	
	}
}