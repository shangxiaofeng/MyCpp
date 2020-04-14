#include<iostream>
using namespace std;

class Parent{
public:
	void print(){
		cout << "Parent:print() do..." << endl;
	}
};

class Child : public Parent{
	public:
		void print(){
			cout << "Child:print() do..." << endl;
		}
};

void howToPrint(Parent* p){
	p->print();
}

void run(){
	Child child;
	Parent* pp = &child;
	Parent& rp = child;

	child.print();//打印子类的函数，也就是执行子类的函数

	//通过指针
	pp->print();
	//通过引用
	rp.print();
	howToPrint(&child);
}
int main(){
	run();
	system("pause");
	return 0;
}

int main02(){
	Child child;
	Parent *p = NULL;
	p = &child;
	child.print();
	child.Parent::print();//子类对象通过作用域分辨符::可以访问到父类中被隐藏的函数
	system("pause");
	return 0;
}


/*
函数重写
在子类中定义与父类中原型相同的函数
函数重写只发生在父类与子类之间

父类中被重写的函数依然会继承给子类
默认情况下子类中重写的函数将隐藏父类中的函数
通过作用域分辨符::可以访问到父类中被隐藏的函数

*/