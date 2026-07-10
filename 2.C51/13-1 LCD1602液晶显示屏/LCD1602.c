#include <REGX52.H>

sbit	LCD_RS = P2^6;
sbit	LCD_RW = P2^5;
sbit	LCD_E = P2^7;

#define LCD_DataPort P0

void LCD_Delay()		//@12.000MHz 1ms
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RW = 0;
	LCD_RS = 0;
	LCD_DataPort = Command;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RW = 0;
	LCD_RS = 1;
	LCD_DataPort = Data;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
	
}

void LCD_Init()
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}

void LCD_SetCursor(unsigned char Line,unsigned char Column )
{
	if(Line == 1)
	{
		LCD_WriteCommand(0x80|Column-1);
	}else if(Line == 2)
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
}

void LCD_ShowChar(unsigned char Line,unsigned char Column ,unsigned char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column ,unsigned char *String)
{
	LCD_SetCursor(Line,Column);
	while(*String != '\0')
	{
		LCD_WriteData(*(String++));
	}
}

void LCD_ShowNum(unsigned char Line,unsigned char Column ,unsigned long Num,unsigned char Length)
{
	while (Length--)
	{
		LCD_SetCursor(Line,Column+Length);
		LCD_WriteData('0'+(Num%10));
		Num /= 10;
	}
}

void LCD_ShowSignedNum(unsigned char Line,unsigned char Column ,long Num,unsigned char Length)
{
	if(Num>=0)
	{
		LCD_ShowChar(Line,Column ,'+');
	}else if(Num<0)
	{
		LCD_ShowChar(Line,Column ,'-');
		Num = -Num;
	}
	while (Length)
	{
		LCD_SetCursor(Line,Column+Length);
		LCD_WriteData('0'+(Num%10));
		Num /= 10;
		Length--;
	}
}

void LCD_ShowHexNum(unsigned char Line,unsigned char Column ,unsigned long Num,unsigned char Length)
{
	while (Length--)
	{
		LCD_SetCursor(Line,Column+Length);
		if((Num%16)>9)
		{
			LCD_WriteData('A'+(Num%16-10));
		}else
		{
			LCD_WriteData('0'+(Num%16));
		}
		Num /= 16;
	}
}

void LCD_ShowBinNum(unsigned char Line,unsigned char Column ,unsigned long Num,unsigned char Length)
{
	while (Length--)
	{
		LCD_SetCursor(Line,Column+Length);
		LCD_WriteData('0'+(Num%2));
		Num /= 2;
	}
}


