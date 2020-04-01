#include<iostream>
using namespace std;
//Ä£°åÀà 
template <typename T>
class A{
public:
	A(int a = 0){
		this->a= a;
	}
public:
	void printA(){
		cout << "a :" << a << endl;
	}
protected:
private:
	T a;
};
void UseA(A<int>& a){
	a.printA();
}
int main(){
	A <int> a1(520);
	a1.printA();
	UseA(a1);
	return 0;
}