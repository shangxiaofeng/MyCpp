#include<stdio.h>
//FILE *fopen( const char *fname, const char *mode );//fname 表示文件名（可以含有路径信息），第二个参数是打开的方式
int main(){
	FILE* file;
	file =  fopen("C:\\DuringWinterVacation\\BrainCollege\\BrainCode\\4.16\\05 fopen的使用\\xiaofeng.txt","r");
	if (!file){//等价于 file == NULL
		printf("打开xiaofeng.txt文件失败！\n");
	}
	else{
		printf("打开xiaofeng.txt文件成功！\n");
	}
	printf("=====================\n");

	FILE* file01;
	file01 = fopen("C:\\DuringWinterVacation\\BrainCollege\\BrainCode\\4.16\\05 fopen的使用\\xiaofeng.txt", "rb+");
	if (!file01){
		printf("打开xiaofeng.txt文件失败！\n");
	}
	else{
		printf("打开xiaofeng.txt文件成功！\n");
	}
	return 0;
}