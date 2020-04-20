#include"game.h"

void game(){
	//存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//0表示没有雷 
	//存放排查出的信息
	char show[ROWS][COLS] = { 0 };//* 表示 没有排查的位置
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisPlayBoard(mine,ROW,COL);
	//DisPlayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);
	DisPlayBoard(show, ROW, COL);	
	//排查雷
	FindMine(mine,show, ROW, COL);
}
void menu(){
	printf("     (*￣︶￣)     \n");
	printf(" *** 1.play ***   \n");
	printf("  ** 0.exit **    \n");
	printf("     (*￣︶￣)    \n");

}
void test(){
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误！");
		}
	} while (input);
}

int main(){
	test();
	return 0;
}