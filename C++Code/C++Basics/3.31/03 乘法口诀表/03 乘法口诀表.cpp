#include<stdio.h>
/*
实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。
*/
int Table(int n){
	if (n <= 0){
		return -1;
	}
	int i = 0;
	
	for (i = 1; i <= n; i++){
		int j = 0;
		for (j = 1; j <= i; j++){
			printf("%d*%d=%-2d ", i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}

int main(){
	int n;
	printf("请输入一个整数：");
	scanf_s("%d", &n);
	Table(n);
	return 0;
}