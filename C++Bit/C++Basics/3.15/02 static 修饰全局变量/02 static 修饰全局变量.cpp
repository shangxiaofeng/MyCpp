#include<iostream>
#include"static.h";
using namespace std;

static int a = 0;//static 修饰的全局变量 只能在所在.cpp内使用 其他的.cpp内是无法使用的
int main(){

	cout << a << endl;
	GJZ();
	return 0;
}