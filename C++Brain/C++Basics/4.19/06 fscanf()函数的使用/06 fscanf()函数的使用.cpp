#include<stdio.h>

int main(){
	FILE* file;
	file = fopen("info.txt", "r");
	if (!file){
		printf("打开失败！\n");
		return 1;
	}
	char name[32];
	int age;
	int ret;
	//scanf("姓名：%s,年龄：%d", name, &age);
	while (1){
		ret = fscanf(file, "姓名：%s 年龄：%d\n", name, &age);
		if (ret == EOF){
			break;
		}
		printf("%s,%d\n", name, age);
	}
	fclose(file);
	return 0;
}