#include<iostream>
using namespace std;
//其他编译器不一定支持在类的内部声明友元  一般情况下在类的外部先声明类 然后声明函数
//友元不是成员 没有this指针 因此也不能使用const

/*
友元函数可访问类的私有和保护成员，但不是类的成员函数
友元函数不能用const修饰
友元函数可以在类定义的任何地方声明，不受类访问限定符限制
一个函数可以是多个类的友元函数
友元函数的调用与普通函数的调用和原理相同

*/
class Goods;
void playBasketball(const Goods & pBall);

class Goods{
public:
	friend void playBasketball(const Goods & pBall);//友元函数的声明 可以访问类的私有属性
	friend class Business;
	Goods(const char* name,float price){
		m_len = strlen(name);
		m_name = new char[m_len + 1];
		m_price = price;		
	}
	~Goods(){
		if (m_name != NULL){
			delete[] m_name;
			m_name = NULL;
			m_price = 0;
			m_len = 0;
		}
	}
public:
	float getPrice(){
		return m_price;
	}
private:
	char * m_name;
	float m_price;
	int m_len;
};

class Business{
public:
	Business(const char *name, int count){
		_len = strlen(name);
		_name = new char[_len + 1];
		strcpy(_name, name);
		_count = count;
	}
	~Business(){
		if (_name != NULL){
			delete[] _name;
			_name = NULL;
			_count = 0;
			_len = 0;
		}
	}
public:
	//在Business的类中访问 Goods 的成员函数和成员属性 就利用友元类（将Business申请为Goods的友元类）
	void BuyBall( Goods& pBall){
		float BuyPrice = pBall.getPrice();
		cout << "商家的价格：" << BuyPrice << endl;
	}
private:
	char* _name;
	int _len;
	int _count;
};


void playBasketball(const Goods & pBall){
	float PlaBasketballOfprice = pBall.m_price;//可以直接访问私有数据
	cout << "篮球的价格" << PlaBasketballOfprice << endl;
}

int main(){
	Goods Ball("basketball", 360);
	playBasketball(Ball);	
	cout << "价格" << Ball.getPrice() << endl;
	Business BaiDu("HR", 400);
	BaiDu.BuyBall(Ball);
	
	return 0;
}