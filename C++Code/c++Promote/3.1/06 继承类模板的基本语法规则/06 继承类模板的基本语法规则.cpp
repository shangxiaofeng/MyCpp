#include<iostream>
using namespace std;
//模板类 
template <typename T>
class A{
public:
	A(int a = 0){
		this->a = a;
	}
public:
	void printA(){
		cout << "a :" << a << endl;
	}
protected:
	T a;
private:

};
//子模板类派生时，需要具体化模板类，c++编译器需要知道，
//父类的数据类型具体是什么样子的 ，要知道父类所占的数据内存大小是多少，只有数据类型固定下来，才知道如何分派内存
class B :public A<int>{
public:
	B(int a = 10, int b = 30) :A <int>(a){
		this->b = b;
	}
	void printB(){
		cout << "a :" << a << ",b :" << b << endl;
	}
private:
	int b;
protected:
};

void UseA(A<int>& a){
	a.printA();
}

int main(){
	/*A <int> a1(520);
	a1.printA();
	UseA(a1);*/
	B b1(20, 40);
	b1.printB();
	return 0;
}