#include<iostream>
using namespace std;
struct Teacher{
	char name[64];
	int age;
};

int test01(const Teacher *pT){
	//pT->age = 10;// error //指针所指向的内存空间,不能被修改
	return pT->age;
}

int test02(Teacher * const pT)
{
	pT->age = 10;//指针所指向的地址不能修改，内存空间是可以修改的
	//pT = NULL; // ERROR
	return 0;
}

int test03(const Teacher *const pT){
	//pT->age = 10;// error 指针所指向的地址不能修改，内存空间是可以修改的
	//pT = NULL;// ERROR
	return 0;
}

int main(){
	Teacher t1;
	t1.age = 28;
	test01(&t1);
	test02(&t1);
	test03(&t1);

	const int a = 90;
	// a = 89;//error  const 修饰的变量 内容不可变
	int *p = NULL;
	p = (int *)&a;
	*p = 20;  //间接赋值 
	return 0;
}