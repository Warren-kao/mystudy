#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void bubble(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		//Ñ­»·sz-1´Î
//		for (int j = 0; j < sz - i-1; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//
//			}
//		}
//		if (flag)
//			break;
//
//	}
//
//}

void bubble(int arr[], int sz)
{
	int flag = 1;
	for (int i = 0; i < sz-1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			flag = 0;
		}

	}
	if(sz-1>=0 && !flag )
		bubble(arr, sz - 1);
}

void printfarr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[10] = {5,8,1,6,9,4,3,2,7,0};

	bubble(arr, 10);
	printfarr(arr,10);

	return 0;
}