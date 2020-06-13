#include<iostream>
using namespace std;

//模板类 
template <class T>
class A{
public:
	A(T a){
		this->a = a;
	}
	void printfA(){
		cout << "a = " << this->a << endl;
	}
public:
	T a;
};
//从模板类派生了普通类
//模板类派生时, 需要具体化模板类. C++编译器需要知道,父类的数据类型具体是什么样子的
//要知道父类所占的内存大小是多少，只有数据类型固定下来,才知道如何分配内存 

class B:public A<int>{
public:
	B(int b) :A<int>(a){
		this->b = b;
	}
	void printfB(){
		cout << "b = " << this->b << endl;
	}
private:
	int b;
};

//从模板类 派生 模板类
template<typename T>
class C :public A <T> {
public:
	C(T c,T a): A<T>(a){
		this->c = c;
		this->a = a;
	}
	void printfC(){
		cout << "c = " << this->c << endl;
		cout << "a = " << this->a << endl;
	}
private:
	T c;
};
//类模板 做函数参数
//参数 ,C++编译器要求具体的类，所以要 A<int> &a 
void UseA(A<int> &a){
	a.printfA();
}

int  main(){
	A<int> a1(10);//模板类是抽象的  ====>需要进行类型具体,编译器才可以分配内存空间
	a1.printfA();
	UseA(a1);

	B b1(20);
	b1.printfB();

	C<int> c1(12, 24);
	c1.printfC();
	return 0;
}