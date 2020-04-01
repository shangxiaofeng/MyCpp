/*
递归实现n的k次方

编写一个函数实现n的k次方，使用递归实现。
*/

#include<stdio.h>

int Function(int n, int k){
	if (k == 0)
		return 1;
	else if (k >= 1)
	{
		return n*Function(n, k - 1);
	}
}
int main(){
	int n,k;
	printf("请输入一个整数n：\n");
	
	scanf_s("%d", &n);
	printf("请输入一个整数k：");
	scanf_s("%d", &k);
	printf("Function = %d\n", Function(n, k));


	return 0;
}