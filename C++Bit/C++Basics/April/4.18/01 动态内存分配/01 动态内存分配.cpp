#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(){
	int n ;
	int arr[10] = { 0 };
	printf("请输入一个整数n>");
	scanf_s("%d", &n);
	int* ptr = NULL;
	ptr = (int*)malloc(sizeof(int) * n);
	assert(ptr != NULL);
	for (int i = 0; i < n; ++i){
		
		ptr[i] = i + 1;
		printf("%d ", ptr[i]);
	}
	printf("\n");
	free(ptr);
	ptr = NULL;
	return 0;
}