#include<iostream>
using namespace std;


class animal{
public:
	animal(const char * name){
		_len = strlen(name);
		_name = new char[_len + 1];
		strcpy(_name, name);
		cout << "name:" << _name << endl;
	}
	
	~animal(){
		if (_name != NULL){
			delete[] _name;
			_name = nullptr;
			_len = 0;
		}
	}
private:
	char * _name;
	int  _len;
};

class person{
public:

	person(const char* name,const char* sex) :m_sex("boy"),pig("Pig"),dog("Dog"),cat("Cat"){
		m_len =strlen(name);
		m_name = new char[m_len + 1];
		strcpy(m_name, name);
	}
~person(){
		if (m_name != NULL){
			delete[] m_name;
			m_name = nullptr;
			m_sex = nullptr;
			m_len = 0;
		}
	}
public:
	void personShow(){
		cout << "name:" << m_name <<", sex:"<< m_sex << endl;
	}
private:
	 char* m_name;
	 const char* m_sex;	//第一种情况：属性有const 成员必须在初始化列表里面初始化
	 int m_len;
	 animal pig;//第二种情况就是 类的内部有类对象  初始化的时候必须使用参数初始化列表  pig dog
	 animal dog;
	 const animal& cat;//第三种情况就是 类的内部有类对象 & 
	 
};


int main(){
	person p1("xiaofeng","boy");
	p1.personShow();
	return 0;
}