#include<iostream>
using namespace std;

void myswap(int &a,int &b){
	int c = 0; 
	c = a;
	a = b;
	b = c;
}

void myswap02(char &a, char &b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}
//函数的业务逻辑一样
//函数的参数类型不一样   有没有一种机制 方便程序员编程 即为：泛型编程（函数模板）
template <typename T>
void myswap(T &a,T &b){
	T c = 0;
	c = a;
	a = b;
	b = c;
	cout << "我是函数模板！！" << endl;
}
int main01(){
		{
			int x = 10;
			int y = 20;
			myswap(x, y);
			cout << "x= " << x << ",y=" << y << endl;
		}
	{
		char a = 'a';
		char b = 'b';
		myswap02(a, b);
		cout << "a= " << a << ",b=" << b << endl;
	}
	return 0;
}

//函数模板的调用
//自动类型的推导
int main(){
	{
		int x = 90;
		int y = 89;
		myswap<int>(x, y);//方法1、函数模板显示类型调用
		myswap(x,y);//方法2、自动类型推导(用的较少)
	}
	{
		char a = 'a';
		char b = 'b';
		myswap<char>(a, b);
		myswap(a,b);//方法2、自动类型推导(用的较少)
		cout << "a= " << a << ",b=" << b << endl;

	}
}