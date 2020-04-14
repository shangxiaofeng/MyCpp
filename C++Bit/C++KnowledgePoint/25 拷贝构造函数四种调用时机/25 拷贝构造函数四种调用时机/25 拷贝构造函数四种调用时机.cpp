#include "iostream"
using namespace std;

//class First{
//public:
//	//无参构造函数 默认构造函数
//	First() {
//		m_a = 0;
//		cout << "我是构造函数，自动被调用了" << endl;
//	}
//	//有参构造函数 默认构造函数
//	First(int a) {
//		m_a = a;
//	}
//	First(const First &obj2){
//		cout << "我也是构造函数，我是通过另外一个对象obj2，来初始化我自己" << endl;
//		m_a = obj2.m_a + 10;
//	}
//	~First(){
//		cout << "我是析构函数，自动被调用了" << endl;
//	}
//	void getA(){
//		printf("a:%d \n", m_a);
//	}
//protected:
//private:
//	int m_a;
//};
//
////创建一个函数实现第一种调用方法
//void ObjPlay01(){
//	First a1; //变量定义'
//	a1.getA();
//	//用对象1 初始化 对象2 
//	First a2 = a1; //定义变量并初始化 //初始化法
//	a2.getA();
//	a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
//}
//int main(){
//	ObjPlay01();
//	return 0;
//}




//class Second{
//public:
//	//无参构造函数 默认构造函数
//	Second() {
//		m_b = 0;
//		cout << "我是构造函数，自动被调用了" << endl;
//	}
//	//有参构造函数 默认构造函数
//	Second(int b) {
//		m_b = b;
//	}
//	Second(const Second &obj2){
//		cout << "我也是构造函数，我是通过另外一个对象obj2，来初始化我自己" << endl;
//		m_b = obj2.m_b + 10;
//	}
//	~Second(){
//		cout << "我是析构函数，自动被调用了" << endl;
//	}
//	void getB(){
//		printf("b:%d \n", m_b);
//	}
//protected:
//private:
//	int m_b;
//};
//
////创建一个函数实现第二种调用方法
//void ObjPlay02(){
//	Second b1(20); //变量定义
//	//赋值构造函数的第一个应用场景
//	//用对象1 初始化 对象2 
//	Second b2(b1); //定义变量并初始化 //括号法
//	//a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
//	b2.getB();
//}
//int main(){
//	ObjPlay02();
//	return 0;
//}


//
////第三种应用场景
//class Third {
//public:
//	Third(int xx = 0, int yy = 0) {
//		X = xx;
//		Y = yy;
//		cout << "Constructor Object.\n";
//	}
//	//复制构造函数
//	Third(const Third & p){
//		X = p.X; 
//		Y = p.Y;
//		cout << "Copy_constructor called." << endl;
//	}
//	~Third() {
//		cout << X << "," << Y << " Object destroyed." << endl;
//	}
//	int  GetX() {
//		return X;
//	}
//	int GetY() {
//		return Y;
//	}
//private:
//	int  X, Y;
//};
//
//void f(Third  p)   {
//	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl;
//}
//
//void objplay03(){
//	Third A(1, 2);  //形参是一个元素，函数调用，会执行实参变量初始化形参变量
//	f(A);
//}
//
//int main(){
//	objplay03();
//	return 0;
//}


//第四种应用场景
class Forth {
public:
	Forth(int xx = 0, int yy = 0) {
		X = xx;  Y = yy;
		cout << "Constructor Object.\n";
	}
	//赋值构造函数
	Forth(const Forth & p) 	    {
		X = p.X;  Y = p.Y;
		cout << "Copy_constructor called." << endl;
	}
	~Forth(){
		cout << X << "," << Y << " Object destroyed." << endl;
	}
	int  GetX() {
		return X;
	}
	int GetY() {
		return Y;
	}
private:
	int  X, Y;
};

void f(Forth  p)   {
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl;
}

Forth g(){
	Forth A(1, 2);
	return A;
}
//对象初始化操作 和 “=”等号操作 是两个不同的概念
//匿名对象的去和留，关键看，返回时如何接
void mainobjplay(){
	//若返回的匿名对象，赋值给另外一个同类型的对象，那么匿名对象会被析构
	//Forth B;
	//B = g();  //用匿名对象 赋值 给B对象，然后匿名对象析构

	//若返回的匿名对象，来初始化另外一个同类型的对象，那么匿名对象会直接转成新的对象
	Forth B = g();
	cout << "传智扫地僧测试" << endl;
}

int main(){
	mainobjplay();
	return 0;
}
