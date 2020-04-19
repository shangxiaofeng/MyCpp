#include <stdio.h>

int main(void) {
	FILE *file1;
	char name[32];
	int age;
	char c;

	file1 = fopen("info.txt", "w");
	if (!file1){
		printf("打开文件失败！");
		return 1;
	}
	while (1) {
		printf("请输入学员姓名：");
		scanf("%s", name);
		printf("请输入%s的成绩: ", name);
		scanf("%d", &age);

		fprintf(file1, "姓名:%s\t\t年龄:%d\n", name, age);

		printf("还需要继续输入吗？ Y/N\n");

		//fflush(stdin);
		while ((c = getchar()) != '\n');  //直到读到回车符为止！ 

		scanf("%c", &c);
		if (c == 'Y' || c == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	fclose(file1);
	return 0;
}
