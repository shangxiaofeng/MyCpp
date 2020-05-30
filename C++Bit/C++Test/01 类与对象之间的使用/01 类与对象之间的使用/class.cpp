#include"class.h"
//Goods() 这个函数内部真实是这样的 Goods（Goods *const this ）
Goods::Goods(const char* name){
	m_lenght = strlen(name);
	m_name = new char[m_lenght + 1];
	strcpy(m_name, name);
	m_price = 0;
	m_count = 0;
	m_globalPrice = m_count* m_price;
}
Goods::Goods(){
	m_name = new char[1];
	m_name = '\0';
	m_lenght = strlen(m_name);
	m_price = 0;
	m_count = 0;
	m_globalPrice = m_count* m_price;
}
Goods::Goods(const char* name, float price, float count){
	m_lenght = strlen(name);
	m_name = new char[m_lenght + 1];
	strcpy(m_name, name);
	m_price = price;
	m_count = count;
	m_globalPrice = m_count* m_price;
}

float Goods::getPrice(){
	return m_price;
}
float Goods::getGlobalPrice(){
	return m_globalPrice;
}
float Goods::getCount(){
	return m_count;
}

//深拷贝
Goods::Goods(const Goods &obj){
	m_name = new char[obj.m_lenght+ 1];
	strcpy(m_name, obj.m_name);
	m_count = obj.m_count;
	m_price = obj.m_price;
	m_globalPrice = obj.m_globalPrice;
	m_lenght = obj.m_lenght;
	
}
Goods& Goods::operator = (const Goods &obj){
	cout << "赋值操作符重载：" << endl;
	//如果当前的指针不等于 obj 发生赋值
	//判断当前对象是否是给自己赋值
	//第一步释放旧的内存空间 Ball03
	if (this->m_name != nullptr){
		delete[] m_name;
		m_name = nullptr;	
	}

	//第二步 根据Ball01分配内存空间
	this->m_lenght = obj.m_lenght;
	this->m_name = new char[m_lenght + 1];
	this->m_count = obj.m_count;
	this->m_price = obj.m_price;
	this->m_globalPrice = obj.m_globalPrice;

	//第三步 将Ball01 的值赋 Ball03
	strcpy(m_name, obj.m_name);

	return *this;
}

Goods::~Goods(){
	cout << "析构函数的实现：" << endl;
	delete[] m_name;
	m_name = nullptr;
	m_lenght = 0;
	m_count = 0;
	m_globalPrice = 0;
	m_price = 0;
}


void Goods::GoodsShow(){
	cout << "商品名称:" << m_name << ",价格:" 
		<< m_price << ",数量:" << m_count << ",总价："<<m_globalPrice<<endl;
}

void objPlay(Goods obj){
	cout << "第三种方法的实现 ,ob对象初始化完毕" << endl;
}

Goods wayFour(){
	cout << "方法4的实现" << endl;
	Goods football("BeKeHanMu");
	return football;
}
