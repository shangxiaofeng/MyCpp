#include<stdio.h>
#include<stdlib.h>
int main(){
	int* arr = (int *)malloc(sizeof(int) * 10);
	if (!arr){
		printf("分配内存失败！\n");
		return 1;
	}
	FILE *file = fopen("test.txt", "rb");
	if (!file){
		printf("打开文件失败！\n");
		return 1;
	}
	fread(arr, sizeof(int), sizeof(arr) / sizeof(arr[0]), file);
	free(arr);
	fclose(file);
	return 0;
}