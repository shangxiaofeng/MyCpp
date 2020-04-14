#include <iostream>
using namespace std;

class Parent01{
public:
	Parent01(int a = 0){
		this->a = a;
	}
	void print(){
		cout << "我是爹" << endl;
	}
private:
	int a;
};

class Parent02{
public:
	Parent02(int a = 0){
		this->a = a;
	}
	//parent02 添加了virtual关键字
	virtual void print(){
		cout << "我是爹" << endl;
	}
private:
	int a;
};

void main(){
	printf("sizeof(Parent01):%d sizeof(Parent02):%d \n", sizeof(Parent01), sizeof(Parent02));
	system("pause");
	return;
}
