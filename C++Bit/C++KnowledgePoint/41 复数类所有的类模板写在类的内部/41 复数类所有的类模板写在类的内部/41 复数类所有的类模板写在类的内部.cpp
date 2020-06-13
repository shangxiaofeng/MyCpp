#include<iostream>
using namespace std;

template <typename T>
class Complex{
public:
	friend ostream& operator<<(ostream& out, const Complex& obj){
		out << "a = " << obj.a << ",b = " << obj.b;
		return out;
	}
	Complex(T a, T b){
		this->a = a;
		this->b = b;
	}
	void ComplexShow(){
		cout << "a = " << a << " b = " << b << endl;
	}
public:
	Complex operator+(const Complex& obj){
		Complex temp(a + obj.a, b + obj.b);
		return temp;
	}
private:
	T a;
	T b;
};

/*
ostream& operator<<(ostream& out, const Complex& obj){
	out << "a = " << obj.a << ",b = " << obj.b;
	return out;
}
*/
int main(){
	Complex<int> c1(10, 30);
	Complex<int> c2(20, 30);
	Complex<int> c3 = c1 + c2;
	
	cout << "c3: " << c3 << endl;
	c3.ComplexShow();
	return 0;
}