#include<iostream>
using namespace std;

int main(){
	int a = 10;
	int b = a--;
	int c = --a;
	printf("%d %d \n", b, c);

	int d = a++;
	int e = ++a;
	printf("%d %d \n", d,e);

	int bb = (int)3.14;//强制类型转换 将3.14 转化成int类型

	return 0;
}