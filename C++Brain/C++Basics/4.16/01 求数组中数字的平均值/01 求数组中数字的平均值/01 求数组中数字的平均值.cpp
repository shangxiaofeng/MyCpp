#include<stdio.h>
int main(){
	int arr[5] = { 0 };
	int temp;
	int sum = 0;
	int average;
	for (int i = 0; i < 5; ++i){
		printf("请输入%d位整数：",i);
		scanf_s("%d", &temp);
		arr[i] = temp;
		sum += temp;
	}
	average = sum / 5;
	printf("average = %d\n", average);
	return 0;
}