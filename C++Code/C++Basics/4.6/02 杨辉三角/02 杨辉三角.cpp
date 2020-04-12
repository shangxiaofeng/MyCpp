/*
在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
*/

#include <stdio.h>
int main(){
	int i;
	int j;
	int CowCol;
	/*printf("请输入CowCol:");
	scanf_s("%d", &CowCol);*/
	int a[10][10];
	a[0][0] = 1; //第一行，第一列为1
	for (i = 0; i<10; i++){
		a[i][0] = 1;
		for (j = 0; j <= i; j++){
			//判断是否为第一列，如果是设置为1
			if (j == 0) 
				a[i][j] = a[0][0];
			//判断是否为中间，不是第一列，也不是最后一列，
			else if (i >= 1 && j >= 1 && i != j)
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			//判断是否为最后一列
			else if(j == i) 
				a[i][j] = a[i - 1][j - 1];
		}
	}
	//输出杨辉三角
	for (i = 0; i<10; i++){
		for (j = 0; j <= i; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
