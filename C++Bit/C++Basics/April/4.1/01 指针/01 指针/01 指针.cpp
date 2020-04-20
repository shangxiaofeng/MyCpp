#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main01(){
	int a = 10;
	int* pa = &a;//指针变量
	return 0;
}

int main02(){
	char ch = 'w';
	int a = 10;
	double d = 10.0;

	char* pc = &ch;
	int* pa = &a;
	double* pd = &d;

	printf("%d\n", sizeof(pc));
	printf("%d\n", sizeof(pa));
	printf("%d\n", sizeof(pd));
	return 0;
}

int main03(){
	int a = 0x11223344;
	/*int* pa = &a;
	*pa = 0;*/

	char* pa = (char*)&a;
	*pa = 0;
	return 0;
}

//指针类型是有意义的
//1. 指针类型决定了指针进行解引用操作的访问多大空间
//char* 指针，解引用操作符访问1个字节 int* 指针解引用访问4个字节 
//2. 指针类型决定了指针+1，跳过多少个字节(走一步，走多大距离)
//char* 指针+1，向后跳1个字节
//int* 指针+1，向后跳4个字节

int main04(){
	int a = 10;
	int* pa = &a;
	char*pc = (char*)&a;
	
	printf("%p\n", pa);
	printf("%p\n", pa+1);//pa 是int* 的指针，+1就是跳过1个整形（4个字节）的意思，实际上加了4

	printf("%p\n", pc);//pc 是char* 的指针，+1就是跳过1个字符（1个字节）的意思，实际上加了1
	printf("%p\n", pc+1);
	return 0;
}


int main05(){
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0};
	//int i = 0;
	//char* p = (char*)arr;
	//for (i = 0; i < 10; i++){
	//	printf("%p ", *(p + i));
	//}

	int i = 0;
	int* p = arr;
	for (i = 0; i < 10; i++){
		printf("%p ", p + i);
	}

	return 0;
}

int main06(){
	//int a = 0;//局部变量-随机值
	//printf("%d\n", a);
	//a++;

	int *p = NULL;//int * p ;野指针    正确的初始化为 int* p = NULL;
	*p = 20;
	return 0;
}


//越界 出现野指针
int main07(){
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	int *p = arr;
	for (i = 0; i <= 12; i++){
		*p = 0;
		p++;
	}
	return 0;
}

//int* test(){
//	int a = 10;
//	return &a;
//}
//int main08(){
//	int *p = test();
//	*p = 20;
//	return 0;
//}

int main09(){
	int a = 10;
	int *p = &a;//初始化
	int* p2 = NULL;//不知道让p2指向哪里
	//使用p访问了a
	p = NULL;
	if (p != NULL)
		*p = 0;
	return 0;
}

int main10(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	int *p = arr;
	for (i = 0; i < 10; i++){
		printf("%d ", *(p + i));
	}
	return 0;
}

int main11(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	char ch[5] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);//地址-地址  --> 指针-指针
	//printf("%p\n", &arr[0] - &arr[9]);
	//指针-指针 的绝对值 是 计算的指针和指针之间元素的个数
	//前提：两个指针指向同一块空间

	return 0;
}
#include <string.h>
//三种方法实现了strlen:1,计数器，2,递归,3,指针-指针

int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}

int main13()
{
	int len = my_strlen("abc");
	//[a][b][c][\0]
	printf("%d\n", len);
	return 0;
}


int main12()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//int*
	printf("%p\n", arr+1);

	printf("%p\n", &arr[0]);//int*
	printf("%p\n", &arr[0]+1);

	printf("%p\n", &arr);//? - 数组指针类型
	printf("%p\n", &arr+1);


	//数组名是数组首元素的地址
	//但是有两个例外：
	//a. sizeof(数组名)，这里的数组名，表示整个数组，sizeof(数组名)计算的是整个数组的大小
	//b. &数组名，这里的数组名，表示整个数组，&数组名 取出的是整个数组的地址
	//
	return 0;
}

int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < 10; i++)
	{
		//printf("%d ", i[arr]); 
		printf("%d ", arr[i]); //arr[i] ==> *(arr+i)
	}

	////数组可以通过指针来访问
	
	for (i = 0; i < sz; i++)
	{
		//printf("%p ---- %p\n", p + i, &arr[i]);
		*(p + i) = i+1;
	}
	for (i = 0; i < sz; i++)
	{
		//printf("%d ", *(p + i));  //*(arr+i)  arr[i]   p[i]
		//printf("%d ", p[i]);//   i[p] ==  *(i+p) == *(p+i) == p[i]
		printf("%d ", i[p]);  //arr[i]
	}
	/*for (i = 0; i < sz; i++)
	{
	printf("%d ", arr[i]);
	}*//*
	return 0;
}*/