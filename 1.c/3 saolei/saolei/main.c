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

void show(char b[11][11])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}

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
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board2[x][y] == 48)
		{
			board2[x][y] = '1';
			n--;
		}
	
	}

	



	n = 81;
	int num = 0;//周围雷数
	int flag = 0;//踩雷标志
	while ( n > 10 && flag == 0)
	{

		show(board1);

		//展示雷区
		//printf("\n");
		//show(board2);


		scanf("%d %d",&x,&y);
		if (!(x > 0 && x < 10 && y > 0 && y < 10))
		{
			printf("输入错误\n");
			continue;
		}
		if (board2[x][y] == '1')
		{
			flag = 1;
			break;
		}
		num = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (board2[x + i][y + j] == '1')
					num++;
			}
		}
		if (board1[x][y] == '*')
			n--;
		board1[x][y] = num + '0';
		//printf("剩余%d次\n", n);
		system("cls");

	
	}
	if (flag == 1)
	{
		printf("已踩雷,游戏结束\n");
		show(board2);
	}else
		printf("恭喜你,成功\n");

	return;
}

int main()
{
	int a = 1;
	while (a)
	{
		menu();
		int sca = scanf("%d",&a);
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