#include<iostream>
#include"set"
#define _CRT_SECURE_NO_WARNINGS
#include<functional>
using namespace std;
//集合元素唯一 不能按照【】方式插入元素  自动排序 默认情况下是从小到大的
//红黑树
void SetOfUse01(){
	set<int> s1;
	for (int i = 0; i < 5; i++){ 
		int tmp = rand();
		s1.insert(tmp);
	}
	s1.insert(100);
	s1.insert(100);
	s1.insert(100);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//删除集合
	while (!s1.empty()){
		set<int>::iterator it = s1.begin();
		cout << *it << " ";
		s1.erase(s1.begin());
	}
}

//对基本的数据类型set能自动排序
void SetOfUse02(){
	set<int> s1;
	set<int, less<int>> s2;// 默认情况下 
	set<int, greater<int>> s3; // 从大到小
	for (int i = 0; i < 5; i++){
		int tmp = rand();
		s3.insert(tmp);
	}
	//从大到小
	for (set<int>::iterator it = s3.begin(); it != s3.end(); it++){
		cout << *it << " ";
	}
}

//如果对于复杂的数据类型 Teacher， Student
class Student{
public:
	Student(char* name, int age){
		strcpy(this->name, name);
		this->age = age;
	}
public:
	int age;
	char name[64];
private:
};

struct FuncStruct{
	bool operator()(const Student& left, const Student& right){
		if (left.age < right.age){
			return true;
		}
		else{
			return false;
		}
	}
};
void SetOfUse03(){
	Student s1("s1", 31);
	Student s2("s2", 32);
	Student s3("s3", 33);
	Student s4("s4", 34);
	set<Student, FuncStruct> S1;
	S1.insert(s1);
	S1.insert(s2);
	S1.insert(s3);
	S1.insert(s4);
	//遍历
	for (set<Student, FuncStruct>::iterator it = S1.cbegin(); it != S1.end(); it++){
		cout << it->age << "\t"<<it->name << endl;
		
	}
}
void SetOfUse05(){
	set<int> s1;
	
	for (int i = 0; i < 10; i++){
		s1.insert(i+1);
	}  
	//从大到小
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	set<int>::iterator it0 = s1.find(5);
	cout << "it0:" << *it0 << endl;

	int num1 = s1.count(5);
	cout << "num1:" << num1 << endl;
	set<int>::iterator it1 = s1.lower_bound(5);//大于等于5的迭代器的位置
	cout << "it1:" << *it1 << endl;
	set<int>::iterator it2 = s1.lower_bound(5);//大于5的迭代器的位置
	cout << "it2:" << *it2 << endl;

}

int main(){
	//SetOfUse01();
	//SetOfUse02();
	//SetOfUse03();
	SetOfUse05();

	return 0;
}