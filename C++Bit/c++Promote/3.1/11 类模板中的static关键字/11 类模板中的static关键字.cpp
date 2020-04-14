#include<iostream>
using namespace std;

template<typename T>
class AA{
public:
	static T m_a;//static 必须在类的外部初始化
protected:
private:
};

template<typename T>
T AA<T>::m_a = 0;
int main(){
	AA<int> a1, a2, a3;
	a1.m_a = 99;
	a2.m_a++;
	a3.m_a++;
	cout << "m_a=" << AA<int>::m_a << endl;

	AA<char> b1, b2, b3;
	b1.m_a = 'a';
	b2.m_a++;
	b3.m_a++;
	cout << AA<char>::m_a << endl;

	return 0;
}