#include<stdio.h>
#define ROW 5
#define COL 5

int main01 (){
	int i = 0;
	int j = 0;
	int arr[ROW][COL] = { 0 };
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			arr[i][j] = i + j;
			//printf("%d ", *(*(arr + i) + j));//二维数组指针访问
			printf("%d ", arr[i][j]);//二维数组，下标访问
		}
		printf("\n");
	}
	return 0;
}

void PrintArray3(int (*pa)[COL], int row, int col){
	for (int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}

void PrintArray2(int pa[ROW][COL], int row, int col){
	for (int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}
int main02(){
	int ar[ROW][COL] = { 0 };
	for (int i = 0; i<ROW; ++i){
		for (int j = 0; j<COL; ++j){
			ar[i][j] = i + j;
		}
	}
	PrintArray2(ar, ROW, COL);
	PrintArray3(ar, ROW, COL);
	return 0;
}

void test(int arr[])//ok?
{}
void test1(int arr[10])//ok?
{}
void test2(int *arr)//ok?
{}
void test3(int *arr[])//ok?  //Error  int **arr
{}
void test4(int **arr)
{}
void main(){
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);
	test(ar);
	test1(ar);
	test2(ar);
	//test3(&ar);error
	//test3(ar);error
	int *br[10] = { 0 };
	test4(br);
}