#include<iostream>
using namespace std;
#define MAX 1000

enum Sex{
	MALE,
	FEMALE,
	SAVE

};
int main(){
	//1、常量 （1）字面常量 300 是不可修改的 
	//const修饰的常变量，const 修饰不可以改变
	const int num = 20;
	//num = 10; error 
	printf("num = %d\n", num);
	//2、#define 定义的标识符常量
	int a = MAX;
	printf("a = %d\n", a);
	//3、枚举常量
	int  b = 90;
	enum Sex s = MALE;
	printf("%d\n", MALE);



	return 0;
}