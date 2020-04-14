//用C语言在屏幕上输出以下图案：
#include<stdio.h>

int main() {
	int i = 0;
	int line;
	printf("请输入您打印的行数：");
	scanf_s("%d", &line);
	for (i = 0; i < line; i++){
		int j = 0;
		for (j = 0; j <line-1-i; j++){
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line-1; i++){
		int j = 0;
		for (int j = 0; j <= i; j++){
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i)-1; j++){
			printf("*");
		}
		printf("\n");
	}
		return 0;
}