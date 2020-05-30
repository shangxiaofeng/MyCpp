#include"class.h"

int main(){
	Goods Ball01("Basketball",120, 2);
	//拷贝构造函数有四种调用时机（用一个对象初始化另一个对象）
	//第一种调用的方法 Goods  Ball02 = Ball01
	//第二种调用的方法 Goods  Ball02(Ball01)
	//第三种调用的方法 对象做函数的参数  实参初始化形参 
	//第四种调用的方法 对象位于函数体内 返回类对象  （调用拷贝构造函数 生成匿名对象）
	Goods Ball02(Ball01); //方法 1 2 
	objPlay(Ball01);//方法3
	wayFour();//方法4 

	Goods Ball03("Basketball", 120, 2);
	Ball03 = Ball01;//用Ball01 赋值给Ball03 等价于Ball03.operator=(Ball01)  深拷贝  
	Ball03.GoodsShow();

	return 0;
}