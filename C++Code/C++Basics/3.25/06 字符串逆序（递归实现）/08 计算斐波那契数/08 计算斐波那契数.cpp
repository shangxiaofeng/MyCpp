/*
计算斐波那契数
n>1，F(n)=F(n-1)+F(n-2);
F(0)=0;
F(1)=1;
求第n个斐波那契数

递归和非递归分别实现求第n个斐波那契数
例如：
输入：5,输出：5
输入：10,输出：55
输入：2,输出：1
*/

#include<stdio.h>
//递归实现
int Fibonacci01(int num){
	if (num == 1 || num == 2){
		return 1;
	}
	return Fibonacci01(num - 1) + Fibonacci01(num - 2);
}
//非递归实现
int Fibonacci02(int num){
		int n1 = 1,
			n2 = 2,
			result = 1;
		for (int i = 3; i <= num; i++){
			result = n1 + n2;
			n1 = n2;
			n2 = result;
		}
		return result;
}

int main(){
	int n;
	printf("请输入一个数：");
	scanf_s("%d", &n);
	printf("Fibonacci01 = %d\n", Fibonacci01(n));
	printf("Fibonacci02 = %d\n", Fibonacci02(n));
	return 0;
}