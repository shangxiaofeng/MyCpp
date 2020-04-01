#include<iostream>
using namespace std;

void test(){
	static int a = 1;//static关键字增加了局部变量的生命周期 具有全局的使用范围
	a++;
	cout << a << "";
	cout << endl;
}

int main(){
	int i = 0;
		while (i < 10){
		test();
		i++;
		}

	return 0;
}