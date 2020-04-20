#include<iostream>
using namespace std;

//二维数组的使用
int main(){
	int arr[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			printf("&arr[%d][%d] = ]%P\n ", &arr[i][j]);
		}
		cout << endl;
	}

	return 0;
}