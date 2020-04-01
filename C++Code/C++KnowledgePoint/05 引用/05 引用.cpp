#include<iostream>
using namespace std;

void swap01(int* x,int* y){
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap02(int &x, int &y){
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

void swap03(int &x, int &y){
	x = x^y;
	y = x^y;
	x = x^y;
}

int main(){
	int a = 90;
	int b = 100;
	//swap01(&a, &b);
	//cout << "a = " << a << " b = " << b << endl;
	//swap02(a, b);
	//cout << "a = " << a << " b = " << b << endl;
	swap03(a, b);
	cout << "a = " << a << " b = " << b << endl;
	return 0;
}