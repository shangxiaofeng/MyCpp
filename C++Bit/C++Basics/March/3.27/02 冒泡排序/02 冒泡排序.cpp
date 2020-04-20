#include<iostream>
#include<stdio.h>
using namespace std;

//从前往后排，排成升序

void BubbleSort01(int * arr,int len){
	for (int i = 0; i < len; i++){
		int flag = 1;
		for (int j = 0; j < len - 1 - i; j++){
			if (arr[j] > arr[j + 1]){
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1){
			break;
		}
	}
}


void printF(int * arr,int len){
	for (int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//从后往前排，排成升序
void BubbleSort02(int * arr,int len){
	for (int i = len-1; i > 0; i--){
		int flag = 1;
		for (int j = len - 1; j > 0; j--){
			if (arr[j] <arr[j - 1]){
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1){
			break;
		}
	}
}

int main(){
	int arr[] = { 11, 22, 33, 42, 50, 6, 7, 8, 9, 10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	BubbleSort01(arr,length);
	printF(arr, length);
	BubbleSort02(arr, length);
	printF(arr, length);

	return 0;
}