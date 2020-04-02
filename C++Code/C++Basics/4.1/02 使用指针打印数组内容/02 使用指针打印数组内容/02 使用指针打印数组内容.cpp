#include<stdio.h>

void printfArr(int *p, int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%d ", *(p + i));
	}
	printf("\n");
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8.9, 10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printfArr(arr, length);

	return 0;
}
