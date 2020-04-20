#include<iostream>
using namespace std;

void GJZ(){
	static int b = 10;//static 修饰的全局变量 只能在所在.cpp内使用 其他的.cpp内是无法使用的
	cout << b << endl;
}

