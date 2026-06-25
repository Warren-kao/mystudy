#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void menu()
{
	printf("*********************\n");
	printf("***1 add    2 sub****\n");
	printf("***3 mul    4 div****\n");
	printf("***0 exit        ****\n");
	printf("*********************\n");
	printf("请输入\n");
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}

int main()
{

	int x = 0, y = 0;
	int n = 0;
	int(*p[5])(int,int) = {NULL,add,sub,mul,div};
	do
	{
		menu();
		scanf("%d", &n);
		if (n == 0)
		{
			printf("程序退出\n");
		}else if (n > 0 && n < 5)
		{
			printf("请输入计算的数字\n");
			scanf("%d %d",&x,&y);
			printf("%d\n",p[n](x, y));
		}
		else
		{
			printf("输入错误\n");
		}
	} while (n);



	return 0;
}

