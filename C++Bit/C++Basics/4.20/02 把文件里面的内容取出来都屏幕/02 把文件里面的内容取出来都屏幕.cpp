#include<stdio.h>

int main(){
	int arr[20] = { 0 };
	FILE *file = NULL;
	char name[32];
	file = fopen("test.txt", "r");
	if (!file){
		printf("打开文件失败！\n");
		return 1;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
		fscanf_s(file, "姓名：%s   %d",name, arr[i]);
	}
	fclose(file);
	return 0;
}