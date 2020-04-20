/*
字符串旋转结果
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
*/

#include<stdio.h>
#include<assert.h>
#include<string.h>

char* reverse(char * ch){
	assert(ch != NULL);
	char* left = ch;
	char* right = ch+strlen(ch) - 1;
	while (left < right){
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
	return ch;
}

int main(){
	char ch[] = {"abba"};
	/*printf("请输入字符串：");
	scanf_s("%s", ch);*/
	char *arr = reverse(ch);
	if (!strstr(arr, "abba") ){
			printf("%s\n", arr);
		return 1;
	}
	else{
		return -1;
	}
	return 0;
}