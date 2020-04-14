//C语言中的变量都必须在作用域开始的位置定义！！
//C++中更强调语言的“实用性”，所有的变量都可以在需要使用时再定义。
//register关键字 请求编译器让变量a直接放在寄存器里面，速度快
//C语言中无法取得register变量地址
//在C++中依然支持register关键字

#include<iostream>
using namespace std;


int main(){
	register int a = 0;
	printf("&a: %d \n", &a); //c语言中是，不能在寄存器变量上取地址
	for (int i = 0; i<1000; i++) //不使用register也可能做优化
	{
		printf("i:%d \n", i);
	}
	system("pause");

	return 0;
}