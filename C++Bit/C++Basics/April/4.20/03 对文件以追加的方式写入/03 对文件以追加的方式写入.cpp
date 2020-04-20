#include<stdio.h>

int main(){
	int arr[] = { 1,2,3,4,5,6 };
	FILE *file = NULL;
	file = fopen("test.txt", "a");
	if (!file){
		printf("打开文件失败！\n");
		return 1;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		fprintf(file, "%d", arr[i]);
	}
	fclose(file);
	return 0;
}