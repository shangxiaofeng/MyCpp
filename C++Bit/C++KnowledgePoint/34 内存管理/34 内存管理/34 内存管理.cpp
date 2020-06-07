#include<iostream>
#include<assert.h>
using namespace std;

/*
class String;
ostream& operator<<(ostream &out, const String &s);
class String{
	friend ostream& operator<<(ostream &out, const String &s);

public:
	//构造函数 注意赋值的动作
	String(const char *str = ""){
		//首先判断是否为空 如果是空  则申请一个字节的空间 赋值为空
		if (str == nullptr){
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else{
			//不为空 则申请赋值空间的大小+1
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}

	String(const String &s){
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}

	String& operator=(const String &s){
		if (this != &s){
			delete[]m_data;
			m_data = new char[strlen(s.m_data) + 1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String(){
		if (m_data != nullptr){
			delete[]m_data;
			m_data = nullptr;
		}
	}
public:
	String operator+(const String &s){
		int total_size = strlen(m_data) + strlen(s.m_data) + 1;
		char *new_data = new char[total_size];
		strcpy(new_data, m_data);
		strcat(new_data, s.m_data);

		String tmp;
		delete[]tmp.m_data;
		tmp.m_data = new_data;
		return tmp;
	}
	String& operator+=(const String &s){
		int tatalSize = strlen(m_data) + strlen(s.m_data) + 1;
		char* newData = new char[tatalSize];
		strcpy(newData, m_data);
		strcat(newData, s.m_data);

		delete m_data;
		m_data = nullptr;
		m_data = new char[tatalSize];
		strcpy(m_data, newData);
		return *this;

	}
	int operator==(const String &s){
		return strcmp(m_data, s.m_data);
	}
	int operator>(const String &s){
		return strcmp(m_data, s.m_data);
	}
	int operator<(const String &s){
		return strcmp(m_data, s.m_data);
	}

private:
	char *m_data;
};
ostream& operator<<(ostream &out, const String &s){
	out << s.m_data;
	return out;
}
void main(){
	String s("Hello");
	String s1(s);   //nullptr  ""
	String s2(" Bit.");
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	String s3 = s1 + s2;   //Hello Bit.
	cout << "s3 = " << s3 << endl;
	s1 += s2;
	cout << "s1 = " << s1 << endl;
	if(!(s1 == s2)){
		cout << "s1 与 s2 相等！" << endl;
	}
	else if(s1 > s2){
		cout << "s1>s2" << endl;
	}
	else if(s1 < s2){
		cout << "s1<s2" << endl;
	}
}

*/

/*
class memoryMangement;
ostream& operator<<(ostream&out, const memoryMangement& obj);

class memoryMangement{
public:
	friend ostream& operator<<(ostream&out, const memoryMangement& obj);
	memoryMangement(int data = 0):m_data(data){}
	memoryMangement(const memoryMangement& obj){
		m_data = obj.m_data;
	}
	memoryMangement& operator= (const memoryMangement& obj){
		m_data = obj.m_data;
		return *this;
	}
	~memoryMangement(){
		m_data = 0;
	}
public:
	 memoryMangement operator+ (const memoryMangement& obj){
		 return (m_data + obj.m_data);
		
	 }
	 memoryMangement& operator+=(const memoryMangement& obj){
		 m_data = m_data + obj.m_data;
		 return *this;
		
	 }
private:
	int m_data;
};

ostream& operator<<(ostream&out, const memoryMangement& obj){
	out << obj.m_data;
	return out;
}
int main(){
	memoryMangement m1(10);
	memoryMangement m2(m1);
	memoryMangement m3(0);
	m3 = m1 + m2;
	cout << "m3 = " << m3 << endl;
	m3 += m1;
	cout << "m3 = " << m3 << endl;

	return 0;
}
*/

class memoryMangement;

//操作符重载new 关键字
void* operator new(size_t obj){
	void* ptr = malloc(obj);
	assert(obj != NULL);
	return ptr;
}
void operator delete(void* ptr){
	if (ptr != NULL){
		free(ptr);
	}
}
void* operator new[](size_t obj){
	void* ptr = malloc(obj);
	assert(ptr != NULL);
	return ptr;
}
void operator delete[](void*ptr){
	if (ptr != NULL){
		free(ptr);
	}
}

class memoryMangement{
public:
	memoryMangement(int data):m_data(data){
		cout << "创建对象" << this << endl;
	}
	~memoryMangement(){
		m_data = 0;
		cout << "析构函数释放空间" << endl;
	}
public:
	//操作符重载new 关键字
	void* operator new(size_t obj){
		void* ptr = malloc(obj);
		assert(obj != NULL);
		return ptr;
	}
		void operator delete(void* ptr){
		if (ptr != NULL){
			free(ptr);
		}
	}
	void* operator new[](size_t obj){
		void* ptr = malloc(obj);
		assert(ptr != NULL);
		return ptr;
	}
		void operator delete[](void*ptr){
		if (ptr != NULL){
			free(ptr);
		}
	}
public:
	int getData()const{
		return m_data;
	}
private:
	int m_data;
};


int main(){
	memoryMangement *pm = new memoryMangement;
	memoryMangement *pm1 = (memoryMangement*)::operator new(sizeof(memoryMangement));
	memoryMangement *pm2 = new memoryMangement[10];
	delete pm;
	delete pm1;
	delete [] pm2;
	return 0;
}