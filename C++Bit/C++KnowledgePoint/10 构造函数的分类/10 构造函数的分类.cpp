#include<iostream>
using namespace std;
class Test{
public:
	Test(){
		this->a = 0;
		this->b = 0;
		cout << "我是无参数构造函数!" << endl;
	}
	Test(int x, int y){
		this->a = x;
		this->b = y;
		cout << "我是有参数的构造函数！" << endl;
	}
	Test(int z){
		this->a = z;
		this->b = 0;
		cout << "我是一个参数的构造函数！" << endl;
	}
	Test(const Test& obj){
		cout << "我是copy构造函数！" << endl;
	}
protected:
private:
	int a;
	int b;
};
int main(){
	Test t1(90);
	Test t2(89, 56);
	Test t3 = t2;
	return 0;
}