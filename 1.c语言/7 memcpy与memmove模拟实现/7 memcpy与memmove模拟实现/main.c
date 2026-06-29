#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void* my_memcpy(void* place,void* sour,size_t num)
{
	void* ret = place;
	while (num--)
	{
		*(char*)place = *(char*)sour;
		place = (char*)place+1;
		sour = (char*)sour+1;
	}
	return ret;
}
void* my_memmove(void* place,void* sour,size_t num)
{
	void* ret = place;
	if (place < sour)
	{
		while (num--)
		{
			*(char*)place = *(char*)sour;
			place = (char*)place+1;
			sour = (char*)sour+1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)place + num) = *((char*)sour + num);
		}
	}
	return ret;
}

int main()
{

	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = {10,11,12,13,14,15,16,17,18,19};

	//memcpy(arr2,arr1,20);
	//my_memcpy(arr2+5,arr1,20);
	//memmove(arr1+2,arr1,20);
	my_memmove(arr1+5,arr1,20);



	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}
