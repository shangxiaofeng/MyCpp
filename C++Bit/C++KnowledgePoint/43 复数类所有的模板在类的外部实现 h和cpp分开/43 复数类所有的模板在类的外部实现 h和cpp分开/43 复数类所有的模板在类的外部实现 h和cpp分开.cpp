#include"Complex.cpp"//类模板的函数机制导致这里必须用  .cpp才能找到函数体


int main(){
	//需要把模板类进行具体化以后,才能定义对象,C++编译器要分配内存
	Complex<int> c1(10, 30);
	Complex<int> c2(20, 30);
	Complex<int> c3 = c1 + c2;

	cout << "c3: " << c3 << endl;
	c3.ComplexShow();
	return 0;
}