#include<stdio.h>
int main(){
	int arr[] = { 10, 45, 67, 54, 6, 78, 9, 9, 56, 57, 89, 100 };
	int n = sizeof(arr) / sizeof(arr[0]);
	FILE* file = NULL;
	file = fopen("test.txt", "wb");//"w"   wb  wb+ 三者有什么区别？
	if (!file){
		printf("打开文件失败！");
		return 1;
	}
	int i = 0;
	for (i = 0; i < n; ++i){
		printf("%d ", arr[i]);//标准输出至屏幕
	}
	printf("\n");


	for (i = 0; i < n; ++i){
		//格式化输出至文件，写入文件 重定向
		fprintf(file, "数字为：%d ", arr[i]);
	}
	fclose(file);
	return 0;
}