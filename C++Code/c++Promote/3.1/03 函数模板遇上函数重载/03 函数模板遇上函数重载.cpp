#include<iostream>
using namespace std;
//函数模板遇上函数重载
//myswap 是函数重载
template <typename T>
void myswap(T &a, T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "我是函数模板！！" << endl;
}
void myswap(int a, char c){
	cout << "a = " << a << ",c = " << c << endl;
	cout << "我是普通函数,欢迎您！" << endl;
}


int main(){
	int a = 10;
	char c = 'z';

	myswap(a, c);	//严格的匹配函数模板，本质：类型参数化
	cout << "----------------" << endl;
	myswap(a, a);	//可以进行影式的类型转化，
	cout << "----------------" << endl;
	myswap(c, a);
	cout << "----------------" << endl;
	return 0;
}