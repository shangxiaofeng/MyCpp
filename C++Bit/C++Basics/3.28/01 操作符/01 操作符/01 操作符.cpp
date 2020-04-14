//不使用地第三个变量 交换两个数
#include<stdio.h>
int main(){
	int a = 90;
	int b = 100;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("%d,%d\n", a, b);
	printf("%d,%d\n", b, a);
}