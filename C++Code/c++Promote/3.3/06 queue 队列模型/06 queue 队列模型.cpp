#include<iostream>
#include"queue"
using namespace std;

//先进先出 队列模型
void QueueOfUse01(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "获队列的头部元素：" << q.front() << endl;
	cout << "队列的大小：" << q.size() << endl;
	while (!q.empty()){
		int tmp = q.front();//获取头部元素
		cout << tmp<< " ";
		q.pop(); //弹出元素
	}
	cout << endl;
}

//队列的算法和数据类型的分离,先进先出的特点
class Teacher{
public:
	int age;
	char name[64];
public:
	void printT(){
		cout << "age= " << age << endl;
	}
protected:
private:
}; 


void QueueOfUse02(){
	Teacher t1, t2, t3;
	t1.age = 20;
	t2.age = 30;
	t3.age = 40;
	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);
	while (!q.empty()){
		Teacher tmp = q.front();
		tmp.printT();
		q.pop();
	}
}

void QueueOfUse03(){
	Teacher t1, t2, t3;
	t1.age = 22;
	t2.age = 33;
	t3.age = 55;
	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);
	while (!q.empty()){
		Teacher *p = q.front();
		p->printT();
		q.pop();
	}
}
int main(){
	//QueueOfUse01();
	QueueOfUse02();
	QueueOfUse03();

	return 0;
}