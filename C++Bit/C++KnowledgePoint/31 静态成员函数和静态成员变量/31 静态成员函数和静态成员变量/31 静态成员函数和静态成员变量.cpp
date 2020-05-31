#include<iostream>
using namespace std;
/*
1. 静态成员为所有类对象所共享，不属于某个具体的实例
2. 静态成员变量必须在类外定义，定义时不添加static关键字
3. 类静态成员即可用类名::静态成员或者对象.静态成员来访问
4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
5. 静态成员和类的普通成员一样，也有public、protected、private3种访问级别，也可以具有返回值

【问题】
1. 静态成员函数可以调用非静态成员函数吗？
2. 非静态成员函数可以调用类的静态成员函数吗？


1、静态成员不属于任何对象 可以被任何对象使用 仅有一份空间  静态成员不需要对象驱动 
2、静态函数只能访问静态成员
3、普通成员函数可以访问静态成员
4、普通方法是可以调用静态成员函数的
5、静态的成员函数是不可以调用普通方法的  因为静态的是没有this指针的 因此没有const const 是修饰this指针的


*/
class Test{
public:
	Test(int x){
		m_x = x;
		cout << "我是构造函数，x=" << m_x <<",m_y = "<<m_y<< endl;
	}
	~Test(){
		cout << "我是析构函数" << endl;
	}
public:
	int getX(){
		return m_x;
	}
	int getY(){
		return m_y;
	}
	static int getCount(){
		//return getY(); error 静态是不能调用普通的
		return m_count;
	}
private:
	int m_x;
	static int m_y;
	static int m_count;
};

int Test::m_y = 90;
int Test::m_count = 100;

int main(){
	Test t1(11);
	Test t2(22);
	Test t3(33);
	cout << "t3.M-Y = " << t3.getX() << endl;
	cout << "t3.M-Y = " << t3.getY() << endl;

	return 0;
}