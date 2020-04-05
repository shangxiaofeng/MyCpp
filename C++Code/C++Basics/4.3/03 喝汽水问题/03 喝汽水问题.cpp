/*
喝汽水问题:喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int money = 20;
	int sum = money;
	int temp = 20;
	int yushu = 0;
	int i = 0;
	int arr[10] = { 0 };//记录每一轮不能换的瓶子数
	while (1){
		++i;
		temp = temp / 2;//10,5,2,1
		yushu = temp % 2;//0,0,1,0
		arr[i] = yushu;
		sum = temp + sum;//30,35,37,38,39
		//将最后一次换瓶子单独判断，因为还要考虑前几轮剩余瓶子的问题
		if (1 == temp){
			yushu = 0;
			for (i = 0; i < 10; ++i){
				yushu += arr[i];//统计所有的不能换的瓶子
			}
			yushu %= 10;
			temp = (temp + yushu) / 2;//去换瓶子
			sum = sum + temp;//所有能换到的瓶子数
			break;
		}
	}
	printf("%d", sum);
	system("pause");
	return 0;
}