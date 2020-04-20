/*
统计二进制中1的个数
写一个函数返回参数二进制中 1 的个数。比如： 15    0000 1111    4 个 1
*/

#include<stdio.h>
void allNumber(int n){
	int count = 0;
	for (int i = 0; i < 31; i++){
		if ((n >> i)& 1 == 1){
			count++;
		}
	}
	printf("count = %d\n", count);
}

int main(){
	int m;
	printf("请输入一个整数：");
	scanf_s("%d", &m);
	allNumber(m);

	return 0;
}