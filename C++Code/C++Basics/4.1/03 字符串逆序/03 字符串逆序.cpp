/*
字符串逆序: 写一个函数，可以逆序一个字符串的内容。
*/

#include<stdio.h>、
#include"string.h"
//方法1
void  reverseString01(char* p, int len){
	int mid = len / 2;
	int i = 0;
	for (i = 0; i < mid; i++){
		int temp = p[i];
		p[i] = p[len - 1 - i];
		p[len - 1 - i] = temp;
	}
}
void printfCh(char* q, int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%c ", q[i]);
	}
	printf("\n");
}


//方法2
void reverseString02(char* r){
	char* left= r;
	char* right = r + strlen(r) - 1;
	while (left < right){
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
int main(){
	char ch[] = "helloSLAM!";
	int length = sizeof(ch) / sizeof(ch[0]);
	reverseString01(ch, length);
	printfCh(ch, length);

	reverseString02(ch);
	printfCh(ch, length);

	
	return 0;
}