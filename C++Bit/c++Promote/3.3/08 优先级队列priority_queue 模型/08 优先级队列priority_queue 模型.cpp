#include<iostream>
#include<functional>
#include"queue"

using namespace std;

void PriorityQueue01(){
	priority_queue<int> p1;//默认情况下是最大值优先队列
	priority_queue<int, vector<int>, less < int >> p2; //提前定义好的预定义函数 
	priority_queue<int, vector<int>, greater <int>> p3; //最小值优先队列
	p1.push(33);
	p1.push(55);
	p1.push(66);
	p1.push(22);
	cout << "队头元素：" << p1.top() << endl;
	cout << "队列的大小:" << p1.size() << endl;
	while (p1.size()>0){
		cout << p1.top() << " ";
		p1.pop();
	}
	cout << endl << endl;
	cout << "测试最小优先队列" << endl;
	p3.push(33);
	p3.push(55);
	p3.push(66);
	p3.push(22);
	cout << "队头元素：" << p3.top() << endl;
	cout << "队列的大小:" << p3.size() << endl;
	while (p3.size()>0){
		cout << p3.top() << " ";
		p3.pop();
	}
	cout << endl;

}
int main(){
	PriorityQueue01();


	return 0;
}