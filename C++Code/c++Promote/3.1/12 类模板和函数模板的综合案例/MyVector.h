#include<iostream>
using namespace std;

template <typename T>
class MyVector{
public:
	friend 	ostream & operator<< <T>(ostream& out, MyVector &obj);
	MyVector(int size = 0);//构造函数
	MyVector(const MyVector &obj);//拷贝构造函数
	~MyVector();//析构函数
	int getlen();
public: 
	//重载【】符号
	T& operator[](int index);
	//重载=符号
	MyVector& operator=(const MyVector &obj);
protected:
	//数组需要确定长度和首地址
	T *m_space;
	int m_len;
};