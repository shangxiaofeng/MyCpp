#include"MyVector.h"

//构造函数的实现
template<typename T>
MyVector<T>::MyVector(int len = 0){
	m_len = len;
	m_space = new T[len];
	
}
//拷贝构造函数的实现
template<typename T>
MyVector<T>::MyVector(const MyVector& obj){ 
	//根据1 对象分配大小 
	m_len = obj.m_len;
	m_space = new T[m_len];

	//将1对象的内容拷贝=到分配内存的空间 也就是2
	for (int i = 0; i < m_len; ++i){
		m_space[i] = obj.m_space[i];
	}
}
//析构函数的实现
template<typename T>
MyVector<T>::~MyVector(){
	if (m_space != NULL){
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

//重载<<
template<typename T>
ostream& operator<<(ostream& out,  MyVector<T>& obj){
	for (int i = 0; i < obj.getLen(); ++i){
		out << obj.m_space[i] << " ";
	}
	cout << endl;
	return out;
}
//重载[]
template<typename T>
T& MyVector<T>:: operator[](T index){
	return m_space[index];
}

//重载等号=
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj){
	if (m_space != NULL){
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}

	m_len = obj.m_len;
	m_space = new T[m_len];

	for (int i = 0; i < m_len; ++i){
		m_space[i] = obj.m_space[i];
	}
	return *this;
}

//获取长度
template<typename T>
int MyVector<T>::getLen(){
	return m_len;
}

//输出
template<typename T>
void MyVector<T>::MyVectorShow( MyVector&obj){
	for (int i = 0; i < obj.getLen(); ++i){
		cout << obj.m_space[i] << " ";
	}
	cout << endl;
}

	