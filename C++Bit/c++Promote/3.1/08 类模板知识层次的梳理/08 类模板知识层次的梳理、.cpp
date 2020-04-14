#include<iostream>
using namespace std;
template <typename T>
class Complex{
public:
	friend ostream& operator<< (ostream &out, Complex<int> &c3);
	Complex(T a = 0, T b = 0){
		this->a = a;
		this->b = b;
	}
	void printCom(){
		cout << "a = " << a << ",b = " << b << endl;
	}
	Complex operator+(Complex &c2){
		Complex tmp(a + c2.a, b + c2.b);
		return tmp;
	}
	
protected:
private:
	T a;
	T b;
};

ostream& operator<< (ostream &out, Complex<int> &c3){
	out << c3.a << "+" << c3.b << "i"<<endl;
	return out;
}
int main(){
	Complex<int> c1(2, 4), c2(3, 5);
	c1.printCom();
	Complex<int> c3 = c1 + c2;
	cout <<"c3 = " <<c3 << endl;

	return 0;
}