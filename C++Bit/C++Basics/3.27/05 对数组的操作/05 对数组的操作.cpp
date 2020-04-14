#include<stdio.h>

//实现函数init() 初始化数组为全0
void initArr(int * arr, int len){
	int i = 0;
	for (i = 0; i < len; i++){
		arr[i] = 0;
	}
}

//实现print()  打印数组的每个元素
void printArr(int * arr, int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//实现reverse()  函数完成数组元素的逆置。
void reverseArr(int * arr, int len){
	int mid = len / 2;
	int i = 0;
	for (i = 0; i < mid; i++){
		int temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}
}
int main(){
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(arr)/sizeof(arr[0]);
	initArr(arr,length);
	printArr(arr, length);
	reverseArr(arr, length);
	return 0;
}