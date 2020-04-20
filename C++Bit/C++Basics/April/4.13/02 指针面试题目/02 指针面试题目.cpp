#include<stdio.h>
#include<iostream>
using namespace std;

int main01(){
	int a[5] = { 1, 2, 3, 4, 5 };
	//printf("%p\n", &a);
	//printf("%p\n", &a+1); //z整个数组的地址向后移动
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}

//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test{
	int Num;//4
	char *pcName;//4
	short sDate;//2
	char cha[2];//2
	short sBa[4];//8
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main02(){
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}


int main03(){
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a +1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}

int main04(){
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p = NULL;
	p = a[0];
	printf("%d\n", p[0]);
	return 0;
}

int main05(){
	int a[5][5];
	int(*p)[4];
	//p = a;
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}

int main06(){
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}

int main07(){
	char *a[] = { "work", "at", "alibaba" };   
	char**pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}

int main(){
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}