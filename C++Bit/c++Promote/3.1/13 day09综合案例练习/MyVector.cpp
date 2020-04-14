#include<iostream>
#include"MyVector.h"
using namespace std;


template <typename T>
MyVector<T>::MyVector(int size = 0){
	m_sapce = T new[size];
	m_len = size;
}

template <typename T>
MyVector<T>::MyVector(const MyVector& obj){
	m_space = T new[obj.m_len];
	m_len = obj.m_len;

	for (int i = 0; i < obj.m_len; i++){
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
MyVector<T>::~MyVector(){ 
	if (m_space != NULL){
		delete[] m_sapce;
		m_space = NULL;
		m_len = 0;
	}
}

template <typename T>
int getlen(){
	return m_len;
}

template <typename T>
T& MyVector<T>::operator[](int index){
	return m_space[index];
}

template <typename T>
ostream& MyVector<T>::operator<< (ostream& out, MyVector& obj){
	for (int i = 0; i < obj.m_len; i++){
		out << obj.m_sapce[i] << " ";
	}
	cout << endl;
	return out;
}

// m2 =m1
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj){
	//先把a2的旧内存释放
	if (m_space != NULL){
		delete[] m_space;
		m_len = 0;
	}
	//根据a1分配内存
	m_len = obj.m_len;
	m_sapce = new T[m_len];

	for (int = 0; i < m_len; i++){
		m_space[i] = obj[i];
	}
	return *this;
}