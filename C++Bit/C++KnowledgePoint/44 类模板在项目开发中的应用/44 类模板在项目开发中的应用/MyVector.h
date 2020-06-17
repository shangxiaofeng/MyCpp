#ifndef __MYVECTOR_H_
#define __MYVECTOR_H_
#include<iostream>
using namespace std;

template<typename T>
class MyVector{
public:
	friend ostream& operator<< <T>(ostream& out,  MyVector<T>& obj);
	MyVector( int len = 0);
	MyVector(const MyVector& obj);
	~MyVector();
public:
	T& operator[](T index);
	MyVector& operator=(const MyVector&obj);
	void MyVectorShow( MyVector&obj);
	int getLen();
private:
	T *m_space;
	int m_len;
};

#endif //__MYVECTOR_H_
