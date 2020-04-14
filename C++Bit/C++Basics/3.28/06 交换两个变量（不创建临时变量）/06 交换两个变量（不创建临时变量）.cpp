

#include<stdio.h>

void swap01(int &x, int &y){
	x = x^y;
	y = x^y;
	x = x^y;
}

int main(){
	int n, m;
	printf("请输入两个数：");
	scanf_s("%d %d", &n, &m);
	printf("n = %d,m = %d\n",n,m);
	swap01(n, m);
	printf("n = %d,m = %d\n", n, m);
	return 0;
}

