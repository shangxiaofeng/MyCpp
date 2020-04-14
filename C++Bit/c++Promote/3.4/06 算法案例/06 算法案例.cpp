//常用遍历的算法
#include<iostream>
#include"algorithm"
#include"vector"
#include"string"
#include"set"
#include"functional"
#include"list"
using namespace std;

void printT(vector<int> &v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void printList(list<int> &v){
	for (list<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void showElement(int &n){
	cout << n << " ";
}

class CMyShow{
public:
	CMyShow(){
		num = 0;
	}
	void operator()(int &n){
		n++;
		cout << n << " ";
	}
	void printBNum(){
		cout << "num:" << num << endl;
	}
protected:
private:
	int num;
};
void main61_foreach_transform(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	printT(v1);
	//利用for_each()的方法遍历这个容器中的所有的元素
	//函数对象，回调函数的入口地址
	for_each(v1.begin(), v1.end(), showElement);//showvector 是函数的入口地址
	cout << endl;
	for_each(v1.begin(), v1.end(), CMyShow());
	cout << endl;
	CMyShow my1 = for_each(v1.begin(), v1.end(), CMyShow());
	my1.printBNum();
}
int increase(int i){
	return i + 100; 
}
void main62(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	printT(v1);
	cout << endl;
	//使用回调函数
	transform(v1.begin(), v1.end(), v1.begin(), increase);
	printT(v1);
	cout << endl;
	//使用预定义函数对象  negate<int>()变成了负数
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printT(v1);
	cout << endl;

	//使用函数适配器
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(), v1.end(), mylist.begin(), bind2nd(multiplies<int>(),10));
	printList(mylist);
	cout << endl;

	//transform也可以把运算结果直接输出到屏幕
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout," "),negate<int>(),negate<int>());
	cout << endl;
}

int showElement02(){
	cout << n << " ";
	return n;
}
void main07_transform_vs_for_each(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	vector<int> v2 = v1;
	for_each(v1.begin(), v1.end(), showElement);
	transform(v2.begin(), v2.end(),v2.begin(),showElement);
}
int main(){
	//main61_foreach_transform();
	//main62();
	main07_transform_vs_for_each();
	return 0;
}