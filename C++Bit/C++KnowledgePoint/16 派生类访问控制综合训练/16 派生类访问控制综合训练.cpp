#include <stdlib.h>
#include <iostream>
using namespace std;

class A{
private:
	int a;
protected:
	int b;
public:
	int c;
public:
	A(){
		a = 0;		b = 0;		c = 0;
	}

	void set(int a, int b, int c){
		this->a = a;		this->b = b;		this->c = c;
	}
	void printA(){
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
	}
};
class B : public A{
public:
	void printB(){
		//cout<<"a = "<<a; //err
		cout << "b = " << b; //ok
		cout << "c = " << endl; //ok
	}
};

class C : protected A{
public:
	void printC(){
		//cout<<"a = "<<a; //err
		cout << "b = " << b; // ok
		cout << "c = " << endl; //ok
	}
};

class D : private A{
public:
	void printD(){
		//cout<<"a = "<<a; //err
		cout << "b = " << b << endl;  //ok
		cout << "c = " << c << endl; // ok
	}
};

int main(){

	A aa;
	B bb;
	C cc;
	D dd;

	aa.c = 100;  //ok
	bb.c = 100; // ok
	//cc.c = 100; // err ±£»¤µÄ
	//dd.c = 100;  // err

	aa.set(1, 2, 3); //ok
	bb.set(10, 20, 30); //ok
	//cc.set(40, 50, 60); // err
	//dd.set(70, 80, 90);  //err


	bb.printA();
	bb.printB();
	
	//cc.printA();
	cc.printC();

	//dd.printA(); 
	dd.printD();


	/**/
	system("pause");
	return 0;
}
