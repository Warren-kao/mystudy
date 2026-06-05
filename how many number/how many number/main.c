#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() 
{
	long long num = 0;
	int len = 0;
	printf("请输入任意长度数字\n");
	scanf("%d",&num);
	do
	{
		len++;
		num /= 10;

	} while (num);
	printf("输入的数字长度为%d\n", len);
	return 0;
}