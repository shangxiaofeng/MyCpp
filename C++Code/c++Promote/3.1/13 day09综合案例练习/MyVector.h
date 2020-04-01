#include<iostream>
using namespace std;

template <typename T>
class MyVector{
public:
	friend ostream& operator<< <T>(ostream & out, MyVector& obj);
	MyVector(int size = 0);
	MyVector(const MyVector& obj);
	~MyVector();
	int getlen();
public:
	T& operator[] (int index);
	MyVector& operator=(const MyVector &obj);
protected:
private:
	T *m_space;
	int m_len;
};