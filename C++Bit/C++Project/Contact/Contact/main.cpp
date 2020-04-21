#include"Contact.h"

void Menu(){
	printf("***********通讯录***************\n");
	printf("** 0、退出            1、增加 **\n");
	printf("** 2、删除            3、查找 **\n");
	printf("** 4、修改            5、显示 **\n");
	printf("** 6、清除            7、排序 **\n");
}

int main(){

	int input = 1;
	Contact con;
	InitContact(&con);
	system("cls");
	system("title 通讯录");
	system("mode con cols=50 lines=25");
	system("color 0B");
	system("date /T");
	system("TIME /T");
	while (input){
		Menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		if (input == EXIT)
			break;
		switch (input){
		case EXIT:
			printf("退出程序\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case FIND:
			FindContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	}
	return 0;
}