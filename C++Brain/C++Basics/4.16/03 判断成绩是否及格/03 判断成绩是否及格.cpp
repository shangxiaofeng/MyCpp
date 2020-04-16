#include<stdio.h>

int main(){
	int a;
	printf("请输入您的成绩：");
	scanf_s("%d", &a);
	if (a < 60){
		printf("没有及格\n");
	}
	else if( a < 80){
		printf("您的成绩是一般！\n");
	}
	else if (a < 90){
		printf("您的成绩是良好\n");
	}
	else {
		printf("您的成绩是优秀！\n");
	}

	return 0;
}