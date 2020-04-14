#include<iostream>
#include"list"
using namespace std;

void ListOfUse01(){
	list<int> l;
	for (int i = 0; i < 10; i++){
		l.push_back(i);//尾插入法 尾插法
	}
	cout << "list的大小：" << l.size() << endl;
	//迭代器遍历
	list<int>::iterator it = l.begin();
	while (it != l.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//list是不能随机访问的
	it = l.begin();
	it++;
	it++;
	it++;
	//it + 5;//error  不支持随机的访问
	//请问100插入到什么位置 结论：链表的节点index序号，是从0号位置开始的，
	//在3号位置插入元素，让原来的3号位置变成4号位置，原来的4号位置变成5号位置，
	l.insert(it, 100);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void ListOfUse02(){
	list<int> l;
	for (int i = 0; i < 10; i++){
		l.push_back(i);//尾插入法 尾插法
	}
	cout << "list的大小：" << l.size() << endl; 
	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;
	l.erase(it1, it2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		cout << *it << " ";
	}
	cout << endl;


}

int main(){
	//ListOfUse01();
	ListOfUse02();


	return 0; 
}