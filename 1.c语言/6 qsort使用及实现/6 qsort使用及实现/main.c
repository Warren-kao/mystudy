#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stu
{
	char name[20];
	unsigned int age;
};

void printf_arr(int arr[],int i)
{
	for (int j = 0; j < i; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");

}

void printf_stu(struct stu* su,int i )
{
	for (int j = 0; j < i; j++)
	{
		printf("%s %d\n", (su[j]).name, (su[j]).age);
	}
	printf("\n");
}

int cmp_int(const void* x,const void* y)
{
	return *(int*)x - *(int*)y;
 }

int cmp_stu_age(const void* x, const void* y)
{
	return ((*(struct stu*)x).age - (*(struct stu*)y).age);

}
int cmp_stu_name(const void* x, const void* y)
{
	 return strcmp((*(struct stu*)x).name,(*(struct stu*)y).name);
}


void qsort_test1()
{
	int arr[] = { 5,6,9,1,8,3,7,4,2,0 };
	struct stu su[] = { {"zhangsan", 18},{"lisi",40},{"wangwu",30} };

	//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));

	printf_arr(arr, (sizeof(arr) / sizeof(arr[0])));
	qsort(arr,(sizeof(arr)/sizeof(arr[0])),sizeof(arr[0]),cmp_int);
	printf_arr(arr, (sizeof(arr) / sizeof(arr[0])));

	//printf_stu(su, (sizeof(su) / sizeof(su[0])));
	//qsort(su,(sizeof(su)/sizeof(su[0])),sizeof(su[0]),cmp_stu_age);
	//qsort(su,(sizeof(su)/sizeof(su[0])),sizeof(su[0]),cmp_stu_name);
	//printf_stu(su, (sizeof(su) / sizeof(su[0])));
}

void swap(char* x, char* y, size_t size)
{
	unsigned char tmp = 0;
	for (size_t i = 0; i < size; i++)
	{
		tmp = *(x + i);
		*(x + i)= *(y + i);
		*(y + i) = tmp;
	}
}


//void qsort (void* base, size_t num, size_t size,int (*compar)(const void*, const void*));
void my_qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
{
	for (size_t i = 0; i < num - 1; i ++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (compar((char*)base + (j * size), (char*)base + ((j + 1) * size)) > 0)
			{
				swap((char*)base + (j * size), (char*)base + ((j + 1) * size),size);
			}
		}
	}

}



void qsort_test2()
{
	int arr[] = { 5,6,9,1,8,3,7,4,2,0 };
	struct stu su[] = { {"zhangsan", 18},{"lisi",40},{"wangwu",30} };

	

	//printf_arr(arr, (sizeof(arr) / sizeof(arr[0])));
	//my_qsort(arr,(sizeof(arr)/sizeof(arr[0])),sizeof(arr[0]),cmp_int);
	//printf_arr(arr, (sizeof(arr) / sizeof(arr[0])));

	printf_stu(su, (sizeof(su) / sizeof(su[0])));
	//my_qsort(su,(sizeof(su)/sizeof(su[0])),sizeof(su[0]),cmp_stu_age);
	my_qsort(su, (sizeof(su) / sizeof(su[0])), sizeof(su[0]), cmp_stu_name);
	printf_stu(su, (sizeof(su) / sizeof(su[0])));
}


int main()
{
	//qsort_test1();


	//用冒泡排序实现快速排序
	qsort_test2();


	return 0;
}