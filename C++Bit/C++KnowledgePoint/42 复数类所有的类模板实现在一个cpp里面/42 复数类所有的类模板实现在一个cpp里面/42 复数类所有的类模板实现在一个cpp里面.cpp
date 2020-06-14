#include<iostream>
using namespace std;

template <typename T>
class Complex{
public:
	friend ostream& operator<<<T>(ostream& out, const Complex& obj);//注意这里的声明 只需要在《 后面加 模板类型
	Complex(T a, T b);
	void ComplexShow();
public:
	Complex<T> operator+(const Complex<T>& obj);
private:
	T a;
	T b;
};

////////////////////////////////////////////////////////////////
//构造函数的实现 写在了类的外部
//运算符重载<<
template <typename T>
ostream& operator<<(ostream& out, const Complex<T>& obj){
	out << "a = " << obj.a << ",b = " << obj.b;
	return out;
}

//类成员 运算符重载+ 
template <typename T>
Complex<T> Complex<T>:: operator+(const Complex<T>& obj){
	Complex<T> temp(a + obj.a, b + obj.b);
	return temp;
}

//构造函数
template <typename T>
Complex<T>:: Complex<T>(T a, T b){
	this->a = a;
	this->b = b;
}


//类的成员函数 
template <typename T>
void Complex<T>::ComplexShow(){
	cout << "a = " << a << " b = " << b << endl;
}
//////////////////////////////////////////////////////////////////

int main(){
	//需要把模板类进行具体化以后,才能定义对象,C++编译器要分配内存
	Complex<int> c1(10, 30);
	Complex<int> c2(20, 30);
	Complex<int> c3 = c1 + c2;

	cout << "c3: " << c3 << endl;
	c3.ComplexShow();
	return 0;
}