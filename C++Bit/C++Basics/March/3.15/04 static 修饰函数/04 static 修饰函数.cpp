#include<iostream>
using namespace std;

class Add{
private:
	int m_a1, m_a2;
	static int m_sum;
public:
	Add(int a1,int a2){
		this->m_a1 = a1;
		this->m_a2 = a2;
		m_sum += (this->m_a1 * this->m_a2);
	}
	static void getSum(){
		cout << "sum = " << m_sum << endl;
	}
};

int Add::m_sum = 0;  //在类的外部初始化

int main(){
	cout << "sizeof(Add)=" << sizeof(Add) << endl;
	Add *dd1 = new Add(5, 4);
	dd1->getSum();
	cout << "sizeof(dd1)=" << sizeof(*dd1) << endl;
	Add dd2(1, 3);
	dd2.getSum();
	cout << "sizeof(dd2)=" << sizeof(dd2) << endl;
	Add::getSum();////也可以可以用类名::函数名访问
	return 0;
}