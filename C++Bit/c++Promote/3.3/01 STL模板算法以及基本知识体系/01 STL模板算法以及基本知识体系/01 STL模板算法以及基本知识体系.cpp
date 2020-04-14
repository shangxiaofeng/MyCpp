#include<iostream>
#include"vector";
#include"algorithm";
using namespace std;

class Teacher{
public:
	int age;
	char name[64];
public:
	void printT(){
		cout << "age=" << age << endl;
	}
protected:
private:
};

int main(){
		{
			//容器中不仅可以装基础的数据类型，也可以装类
			Teacher t1, t2, t3;
			t1.age = 90;
			t2.age = 44;
			t3.age = 89;
			vector<Teacher> v2;
			v2.push_back(t1);
			v2.push_back(t2);
			v2.push_back(t3);
			for (vector<Teacher>::iterator it = v2.begin(); it != v2.end(); it++){
				cout << "it->age:" << it->age << endl;
			}

		}
	cout << "=========================" << endl;
	{
		//容器中不仅可以装基础的数据类型，也可以装指针
		//容器中把t1，t2，t3内存的首地址 放入到容器中
		Teacher t1, t2, t3;
		t1.age = 90;
		t2.age = 44;
		t3.age = 89;
		Teacher *p1, *p2, *p3;
		p1 = &t1;
		p2 = &t2;
		p3 = &t3;
		vector<Teacher*> v3;
		v3.push_back(p1);
		v3.push_back(p2);
		v3.push_back(p3);
		for (vector<Teacher* >::iterator it = v3.begin(); it != v3.end(); it++){
			cout << "（*it）->age:" << (*it)->age << endl;
		}
	}

	cout << "=========================" << endl;
	//容器 把你的元素拷贝到容器中，
	vector<int> v1;
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);
	//迭代器相当于一个指针 
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << "*it=" << *it << endl;
	}
	//算法的基本概念
	//count 函数：统计这个数出现的次数
	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1=" << num1 << endl;
	cout << "=========================" << endl;
	return 0;
}