/*
需求：把这个文件的源代码（test.c）打印出来
*/

#include<iostream>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS 
int main(){
	//打开文件
	FILE * file; 
		char c;
	file = fopen("test.txt", "r");
	assert(file != NULL);

	/*while (1){
		c = fgetc(file);
		if (c == EOF){
			break;
		}
		printf("%c ", c);
	}*/
	while ((c = fgetc(file)) != EOF){
		printf("%c ", c);
	}
	printf("\n");
	system("pause");
	return 0;
}