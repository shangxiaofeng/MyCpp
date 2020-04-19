#include<stdio.h>
/*
写一个字符串到文件中去 fputs
打印该文件的到屏幕
*/

int main(){
	FILE* file1;
	FILE* file2;
	char line[128];

	file1 = fopen("admin.c", "r");
	file2 = fopen("test.c", "w");

	if (file1 == NULL || file2 == NULL){
		printf("文件打开失败！\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file1)){
		fputs(line, file2);
	}
	return 0;
}