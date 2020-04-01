#include<iostream>
using namespace std;

template <typename T>
class Complex{
public:
	Complex(T a = 0, T b = 0);
	void printCom();
	Complex<T> operator+(Complex<T> &c2);
	friend ostream& operator<< <T>(ostream &out, Complex<T> &c3);
protected:
private:
	T a;
	T b;
};
