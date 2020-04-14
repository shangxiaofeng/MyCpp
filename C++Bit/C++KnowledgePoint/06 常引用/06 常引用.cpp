#include<iostream>
using namespace std;

int main(){
	int a = 10;
	int &b = a;
	b = 20;
	cout << "a= " << a << endl;
	const int &c = a;	//用a变量去初始化 常引用c
	//c = 90;//error 因为：常引用是 让变量 引用只读属性 不能通过c去修改a了，c拥有只读的属性



	return 0;
}