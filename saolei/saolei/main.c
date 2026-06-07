#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void menu()
{
	printf("选择游戏开始\n");
	printf("******************\n");
	printf("**** 1  play  ****\n");
	printf("**** 0  exit  ****\n");
	printf("******************\n");
	return;
}


void play()
{
	//游戏初始化
	int x = 0;
	int y = 0;
	//创建随机数
	srand((unsigned int)time(NULL));
	//生成9x9键盘
	char board1[11][11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{ 
			if (j == 0)
				board1[i][j] = '0'+i;
			else if(i == 0)
				board1[i][j] = '0'+j;
			else
				board1[i][j] = '*';
		}
		
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0 ;j < 10; j++)
		{
			printf("%c ", board1[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
		printf("\n");


	//生成9x9雷区
	char board2[11][11];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			board2[i][j] = '0';
		}
	}

	int n = 10;
	while (n)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board2[x][y] == 48)
		{
			board2[x][y] = '1';
			n--;
		}
	
	}
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			printf("%c ", board2[i][j]);
		}
		printf("\n");
	}

	//scanf("%d%d",&x,&y);
	return;
}

int main()
{
	int a = 1;
	while (a)
	{
		menu();
		scanf("%d",&a);
		system("cls");
		if (a == 1)
		{
			//printf("开始游戏\n");
			play();
		}
		else if(a != 1&& a != 0 )
		{
			printf("输入错误\n");
			a = 1;
		}
	}
	return 0;
}