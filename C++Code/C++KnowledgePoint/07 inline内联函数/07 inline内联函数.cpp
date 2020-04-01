#include<iostream>
using namespace std;
//2 C++编译器直接将函数体插入在函数调用的地方
//3 内联函数省去了普通函数调用时压栈，跳转和返回的开销 
inline void function(int &x,int &y){
	x = x^y;
	y = x^y;
	x = x^y;
}

int main(){
	int a = 10; 
	int b = 20;
	function(a,b);
	cout << "a = " << a << ",b = " << b << endl;
	return 0;
}