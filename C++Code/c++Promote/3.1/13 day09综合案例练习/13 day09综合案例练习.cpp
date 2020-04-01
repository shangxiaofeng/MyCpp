#include<iostream>
#include"MyVector.h"
#include"MyVector.cpp"
using namespace std;

int main(){
	MyVector<int> m1(12);
	for (int i = 0; i < m1.getlen(); i++){
		m1[i] = i + 1;
		cout << m1[i] << " ";
	}

	MyVector<int> m2 = m1;
	for (int i = 0; i < m2.getlen(); i++){
		cout << m2[i] << " ";
	}
	cout << endl;



	return 0;
}