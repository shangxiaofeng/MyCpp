#include"common.h"

class Goods{
public:
	Goods();
	Goods(const char* name);
	Goods(const char* name,  float price, float count);
	//拷贝构造函数 	//深拷贝构造函数
	Goods(const Goods &obj);
	//赋值构造函数
	Goods& operator = (const Goods &obj);

public:
	float getPrice();
	float getGlobalPrice();
	float getCount();

	
public:
	void GoodsShow();
public:
	~Goods();
private:
	char* m_name;
	float m_price;
	float m_globalPrice;
	float m_count;
	int m_lenght;
};

void objPlay(Goods obj);
Goods wayFour();
