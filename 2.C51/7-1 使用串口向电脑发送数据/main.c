#include <REGX52.H>
#include "Delay.h"
#include "UART.h"


unsigned char count = 0;
void main()
{
	UART_Init();

	while(1)
	{
		UART_SendByte(count++);
		Delay(1000);

		
	}
}