/*
打印水仙花数
求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/

#include <stdio.h>
#include <math.h>
int main(){
	int i = 0;
	for (i = 0; i < 100000; i++){
		int sum = 0;
		int n = 1;
		//1、判断是几位数
		int temp = i;
		while (temp /= 10){
			n++;
		}
		//2、得到数字i的每一位，计算每一位的次方数
		temp = i;
		while (temp){
			double tp = temp % 10;
			sum += pow(tp, n);
			temp /= 10;
		}
		//3. 判断
		if (sum == i){
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}