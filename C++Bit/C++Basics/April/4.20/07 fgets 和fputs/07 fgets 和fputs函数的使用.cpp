
#include<stdio.h>

int main(){
	FILE *file = fopen("test.txt", "r");
	if (!file){
		printf("打开失败！\n");
		return 1;
	}
	FILE* fp = fopen("test02.txt", "w");
	if (!fp){
		fclose(file);//打开文件失败，将file文件关闭 以免造成浪费
		printf("打开失败！\n");
		return 1;
	}
	char ch[128] = { 0 };
	char *res = fgets(ch,128,file);//从硬盘文件读到 写入内存数据
	while (res != NULL){
		fputs(ch, fp);//从内存数据写出到fp的硬盘文件中去
		res = fgets(ch, 128, file);
	}
	fclose(file);
	fclose(fp);
	return 0;
}