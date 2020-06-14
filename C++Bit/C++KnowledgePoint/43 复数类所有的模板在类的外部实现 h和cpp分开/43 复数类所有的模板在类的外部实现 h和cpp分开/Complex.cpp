#include"Complex.h"

//类成员 运算符重载 +
template <typename T>
Complex<T> Complex<T>:: operator+(const Complex<T>& obj){
	Complex<T> temp(a + obj.a, b + obj.b);
	return temp;
}

//运算符重载<<
template <typename T>
ostream& operator<< (ostream& out, const Complex<T>& obj){
	out << "a = " << obj.a << ",b = " << obj.b;
	return out;
}

//构造函数
template <typename T>
Complex<T>::Complex<T> (T a, T b){
	this->a = a;
	this->b = b;
}


//类的成员函数 
template <typename T>
void Complex<T>::ComplexShow(){
	cout << "a = " << a << " b = " << b << endl;
}