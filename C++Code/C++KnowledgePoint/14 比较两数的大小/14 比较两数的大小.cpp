#include<iostream>
#include<stdlib.h>
using namespace std;

int compareSize(int x, int y){
	int c = (x > y ? x : y);
	return c;
}

int main(){
	int a = 0;
	int b = 0;
	cout << "请输入数值a:";
	cin >> a;
	cout << "请输入数值b:";
	cin >> b;
	cout<<"两数相比较大值为："<<compareSize(a, b)<<endl;
	return 0;
}