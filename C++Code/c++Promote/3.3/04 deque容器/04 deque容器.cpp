#include<iostream>
#include"deque"
#include"algorithm";
using namespace std;

void printD(deque<int>& d){
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
void DequeOfUse01(){
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_front(-1);
	d1.push_front(-2);
	d1.push_front(-3);
	cout << "头部元素：" << d1.front() << endl;
	cout << "尾部元素：" << d1.back() << endl;
	printD(d1);
	d1.pop_front();
	d1.pop_back();
	//根据数组元素求数组下标 如：查找-1 的数组下标
	deque<int>::iterator it = find(d1.begin(), d1.end(), -1);//返回一个迭代器的值，即为数组的下标
	if (it != d1.end()){
		cout << "-1的数组下标：" << distance(d1.begin(), it) << endl;
	}
	else{
		cout << "没有找到！" << endl;
	}
	
}
int main(){
	DequeOfUse01();


	return 0;
}