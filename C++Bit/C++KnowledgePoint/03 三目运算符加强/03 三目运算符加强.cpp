#include<iostream>
using namespace std;
//C语言中的三目运算符返回的是变量值，不能作为左值使用
//C++中的三目运算符可直接返回变量本身，因此可以出现在程序的任何地方
int main(){
	int a = 10;
	int b = 20;
	(a < b ? a : b) = 90;
	cout << a << endl;

	int z = 0;
	z = (a < b ? a : b);
	cout << z << endl;
	return 0;
}