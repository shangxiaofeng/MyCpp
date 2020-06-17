#include<iostream>
using namespace std;

#include"MyVector.cpp"

int main(){
	MyVector<int> v1(10);
	for (int i = 0; i < v1.getLen(); ++i){
		v1[i] = i+1;
		cout << v1[i] << " ";
	}
	cout << endl;
	MyVector<int> v2(10);
	v2 = v1;
	cout << " v2 = " << v2 << " ";
	cout << endl;

	return 0;
}
