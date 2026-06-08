#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() {
	int add = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 3 == 0)
			add += i;
	}
	printf("%d",add);
	return 0;
}
