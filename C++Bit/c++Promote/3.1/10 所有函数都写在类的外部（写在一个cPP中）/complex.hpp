#include<iostream>
#include"complex.h"
using namespace std;


//构造函数的实现,写在了类的外部
template <typename T>
Complex<T>::Complex(T a = 0, T b = 0){
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::printCom(){
	cout << "a = " << a << ",b = " << b << endl;
}
//成员函数实现+好运算符重载
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2){
	Complex tmp(a + c2.a, b + c2.b);
	return tmp;
}
//友元函数实现<<运算符重载
template <typename T>
ostream& operator<< (ostream &out, Complex<T> &c3){
	out << c3.a << "+" << c3.b << "i" << endl;
	return out;
}