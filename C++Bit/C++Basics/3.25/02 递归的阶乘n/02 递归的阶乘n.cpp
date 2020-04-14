#include<stdio.h>


//利用递归的方法求解阶乘
int factorial(int m){
	if (m > 1)
		return factorial(m - 1) * m;
	return 1;
}

//利用循环的方式
int Factorial(int m){
	int result = 1;
	for (int i = 1; i <= m; i++){
		 result = i*result;
	}
	return result;
}
int main(){
	int n;
	printf("请输入数字n：");
	scanf_s("%d\n",&n);
	int x = factorial(n);
	printf(" x =%d\n",x);
	int y = Factorial(n);
	printf(" y =%d\n", y);
	return 0;
}