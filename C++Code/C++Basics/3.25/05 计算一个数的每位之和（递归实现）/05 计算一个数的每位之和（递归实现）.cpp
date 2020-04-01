/*
计算一个数的每位之和（递归实现）

写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
输入：1729，输出：19
*/
#include<stdio.h>

int DigitSum(int m){
	if (m < 10){
		return m;
	}
	else{
		return  m % 10 + DigitSum(m / 10);
	}
}
int main(){
	int n;
	printf("请输入一个非负整数：");
	scanf_s("%d", &n);
	printf("DigitSum = %d\n", DigitSum(n));


	return 0;
}