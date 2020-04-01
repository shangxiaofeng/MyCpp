#include<iostream>
using namespace std;

void compareSize(int * x, int * y){
	if (x < y){
		cout << "a与b两数相比，大值为a=：" << *x << endl;
	}
	else{
		cout << "a与b两数相比，大值为b=：" << *y << endl;
	}
}

int main(){
	int a = 0;
	int b = 0;
	cout << "请输入数值a:";
	cin >> a;
	cout << "请输入数值b:";
	cin >> b;
	compareSize(&a, &b);
	return 0;
}