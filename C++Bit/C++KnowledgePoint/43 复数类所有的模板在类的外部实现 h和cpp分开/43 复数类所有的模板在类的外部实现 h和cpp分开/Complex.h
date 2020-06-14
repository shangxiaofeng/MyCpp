#ifndef __COMPLEX_H_
#define __COMPLEX_H_

#include<iostream>
using namespace std;

template <typename T>
class Complex{
public:
	friend ostream& operator<< <T>(ostream& out, const Complex<T>& obj);//注意这里的声明 需要在《 后面加 模板类型
	Complex(T a, T b);
	void ComplexShow();
public:
	Complex<T> operator+(const Complex<T>& obj);
private:
	T a;
	T b;
};

#endif //__COMPLEX_H_



