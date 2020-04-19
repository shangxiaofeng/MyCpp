#include<stdio.h>
#include <stdlib.h> 
int main(){
	FILE* file = fopen("test.txt", "a");
	if (file == NULL){
		printf("文件打开失败！\n");
	}
	fputs("do well", file);
	system ("pause");
	fclose(file);
	printf("文件已经关闭\n");
	system("pause");
	return 0;
}