/*
字符串逆序（递归实现）

编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。
*/

#include<stdio.h>
#include"string.h"

//递归实现
/*
递归方式：
对于字符串“abcdefg”，递归实现的大概原理：
1. 交换a和g，
2. 以递归的方式逆置源字符串的剩余部分，剩余部分可以看成一个有效的字符串，再以类似的方式逆置
*/
void reverse_string(char* arr){
	int len = strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);

	*(arr + len - 1) = '\0';
	if (strlen(arr + 1) >= 2)
		reverse_string(arr + 1);

	*(arr + len - 1) = tmp;
}

//函数循环实现
void reverse_string02(char* string,int len){
	int mid = len / 2;
	int i = 0;
	for (i = 0; i < mid; i++){
		int temp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = temp;
	}
}
void printfString(char * string,int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%c ",string[i]);
	}
	printf("\n");
}

//函数循环实现
void reverse_string03(char* arr){
	char *left = arr;
	char *right = arr + strlen(arr) - 1;

	while (left<right){
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}
}

int main(){
	char s1[] = "bitGood" ;
	int length = sizeof(s1) / sizeof(s1[0]);
	printfString(s1,length);
	reverse_string(s1);

	reverse_string02(s1, length);

	printfString(s1, length);
	reverse_string03(s1);
	printfString(s1, length);
	return 0;
}