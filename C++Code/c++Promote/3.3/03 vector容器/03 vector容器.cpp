#include<iostream>
#include"vector"
using namespace std;

//数组元素的首 尾 删除 和添加
void VectorOfUse01(){
	vector<int> v1;
	cout << "V1的长度：" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout << "V1的长度：" << v1.size() << endl;
	//获取头部或者尾部的元素
	cout << "头部元素：" << v1.front() << endl;
	cout << "尾部元素：" << v1.size() << endl;

	//修改头部元素的值
	v1.front() = 11;//front这个函数 返回的是一个引用 是可以当左值得 故：函数返回值要当左值，应返回一个引用
	v1.back() = 99;



	while (v1.size() > 0){
		v1.back();//获取尾部的元素
		cout << "v1.back() = " << v1.back() << endl;
		v1.pop_back();//删除尾部的元素

	}
}

//vector的初始化
void VectorOfUse02(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	vector<int> v2 = v1;//对象初始化
	vector<int> v3(v1.begin(), v1.begin() + 2);//对象初始化 
}

//vector的遍历
void VectorOfUse03(){
	//执行前，需要确定内存的大小 即为： v1（10）
	vector<int> v1(10);
	for (int i = 0; i < 10; i++){
		v1[i] = i + 1;
	}

	for (int i = 0; i < 10; i++){
		cout << v1[i] << " ";
	}
	cout << endl;
}

void printV(vector<int>& v){
	for (int i = 0; i < v.size(); i++){
		cout  << v[i] << " ";
	}
	cout << endl;

}
//push_back的强化记忆
void VectorOfUse04(){
	vector<int> v1(10);
	v1.push_back(10);
	v1.push_back(100);//会添加到尾部
	cout << "v1的长度：" << v1.size() << endl;
	printV(v1);
}

//通过迭代器的方式 遍历vector
void VectorOfUse05(){
	vector<int> v1(10);
	for (int i = 0; i < 10; i++){
		v1[i] = i + 1;
	} 
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//逆向的遍历
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++){
		cout << *rit << " ";
	}
	cout << endl;
}

//vector的删除操作
void VectorOfUse06(){
	vector<int> v1(10);
	for (int i = 0; i < 10; i++){
		v1[i] = i + 1;
	}
	//区间删除
	v1.erase(v1.begin(), v1.begin() + 3);
	printV(v1); 
	//指定位置删除
	v1.erase(v1.begin());//在头部删除元素
	printV(v1);
	//根据的元素的位置
	v1[1] = 2;
	v1[3] = 2;
	//删除里面的所有的2
	for (vector<int> ::iterator it = v1.begin(); it != v1.end(); it++){
		if (*it == 2){
			it = v1.erase(it);//迭代器删除所指向的元素的时候，erase删除函数会让it自动下移
		}
		else{
			it++;
		}
	}
	printV(v1);
	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	v1.insert(v1.begin() + 3, 6666);
	printV(v1);

}
int main(){
	//VectorOfUse01();
	//VectorOfUse02();
	//VectorOfUse03();
	//VectorOfUse04();
	//VectorOfUse05();
	VectorOfUse06();



	return 0;
}