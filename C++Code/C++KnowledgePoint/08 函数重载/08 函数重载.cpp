#include<iostream>
using namespace std;

//1 当函数名和不同的参数搭配时函数的含义不同
//2 函数重载的判断标准
	//名称 参数 返回值
	//名称相同 参数不一样(个数/类型/)
//3 返回值 不是 判断函数重载的标准 
//4 重载函数的调用标准

void function01(int a, int b){
	cout << "a = " << a << ".b = " << b << endl;
}
void function01(int x){
	cout << "x = " << x << endl;
}
void function01(double y){
	cout << " y = " << y << endl;
}
int main(){
	int a = 90;
	int b = 20;
	function01(a,b);
	function01(a);
	function01(b);


	return 0;
}