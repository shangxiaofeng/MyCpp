#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void main(){
	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
	int n = sizeof(ar) / sizeof(ar[0]);
	FILE *fp = fopen("Test1.txt", "wb");//wb以二进制写出  
	if (NULL == fp){
		printf("Open File Failed.\n");
		return;
	}
	fwrite(ar, sizeof(int), n, fp);//写出到文本文档，写出到磁盘  
	fclose(fp);
}