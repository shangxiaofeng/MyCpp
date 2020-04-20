#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

//1、对int类型数组排序
int int_cmp(const void * p1, const void * p2){
	return (*(int *)p1 - *(int *)p2);
}

//2、对char类型数组排序
int cmp(const void *p1, const void * p2){
	return (*(char*)p1 - *(char*)p2);
}

int main01(){
	int arr[] = { 1, 8, 9, 2, 3, 4, 5, 6, 7, 10 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

int main02(){
	char ch[] = { 'w', 'm', 'g', 't', 'b', 'i' ,'\0'};
	int i = 0;
	qsort(ch, sizeof(ch) / sizeof(ch[0]), sizeof(char), cmp);
	for (i = 0; i < sizeof(ch) / sizeof(ch[0]); ++i){
		printf("%c ", ch[i]);
	}
	printf("\n");
	return 0;
}



int double_cmp(const void * p1, const void * p2){
	return *(double *)p1 > *(double *)p2 ? 1 : -1;
	//返回值的问题，显然double_cmp返回的是一个整型，所以避免double返回小数而被丢失。
}
int main04(){
	double arr[] = { 1.1, 8.6, 9.6, 2, 3.7, 4.77, 5, 6.66, 7.90, 1.0 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(double), double_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		printf("%0.2f ", arr[i]);
	}
	printf("\n");
	return 0;
}

typedef struct S{
	double data;
	int other;
}S;

int S_cmp(const void * p1, const void * p2){
	return (*(S*)p1).data >(*(S*)p2).data ? 1 : -1;
}


int main(){
	S s[] = { 2.3, 5, 6, 7, 8, 9, 9,100 };
	int i = 0;
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(S), S_cmp);
	for (i = 0; i < sizeof(s) / sizeof(s[0]); ++i){
		printf("%0.2f ", s[i]);
	}
	printf("\n");
	return 0;
}


