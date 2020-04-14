#include<iostream>
#include"vector"
using namespace std;


class Teacher{
public:
	Teacher(char* name, int age){
		m_pname = new char[strlen(name) + 1];
		strcpy(m_pname, name);
		m_age = age;
	}
	~Teacher(){
		if (m_pname != NULL){
			delete[] m_pname;
			m_pname = NULL;
			m_age = 0;
		}
	}
	//t2 = t1 t1初始化t2
	Teacher(const Teacher& obj){
		m_pname = new char[strlen(obj.m_pname) + 1];
		strcpy(m_pname, obj.m_pname);
		m_age = obj.m_age;
	}
	//重载等号操作符t3 = t2 = t1
	Teacher & operator=(const Teacher& obj){
		//先把t2的旧的内存释放掉 根据t1 的大小分配内存空间 然后拷贝数据 
		if (m_pname != NULL){
			delete[] m_pname;
			m_pname = NULL;
			m_age = 0;
			//根据t1内存大小分配空间
			m_pname = new char[strlen(obj.m_pname) + 1];
			strcpy(m_pname, obj.m_pname);
			m_age = obj.m_age;
			return *this;
		}
 	}

public:
	void printT(){
		cout << m_pname << "\t" << m_age << endl;
	}

protected:
private:
	char *m_pname;
	int  m_age;
};

void VectorUse01(){
	Teacher t1("t1", 31);
	vector<Teacher> v1;
	v1.push_back(t1);//把t1 拷贝到容器内，引起深拷贝问题 程序done掉
	t1.printT();
}
int main(){
	VectorUse01();
	return 0;
}