#include<iostream>
#include"complex.h"
#include"complex.hpp"
using namespace std;

int main(){
	Complex<int> c1(2, 4), c2(3, 5);
	c1.printCom();
	Complex<int> c3 = c1 + c2;
	cout << "c3 = " << c3 << endl;
	return 0;
}