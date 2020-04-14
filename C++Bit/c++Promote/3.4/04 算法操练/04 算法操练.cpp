#include<iostream>
#include"algorithm"
#include"vector"
#include"string"
#include"set"
#include"functional"
#include"list"
using namespace std;
//函数对象的概念：重载函数调用操作符的类，其对象常称为函数对象
//类重载了函数调用的操作符（） 就是函数对象
template <typename T>
class ShowElemt{
public:
	ShowElemt(){
		n = 0;
	}
	void  operator()(T &t){
		n++;
		cout << t << endl;
	}
	void printN(){
		cout << "n:" << n << endl;
	}
protected:
private:
	int n;
};

//函数对象和普通函数的区别
//函数模板
template <typename T>
void ShowfuncElemt01(T &t){
	cout << t << endl;
}

//普通函数
void ShowfuncElemt02(int &t){
	cout << t << endl;
}

void main41(){
	int a = 90;
	ShowElemt<int> showelemt;
	showelemt(a);
	ShowfuncElemt01<int>(a);
	ShowfuncElemt02(a);
}

//函数对象的好处
void main42(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3); 
	v1.push_back(5);
	//匿名函数对象 匿名仿函数
	for_each(v1.begin(), v1.end(), ShowElemt<int>());
	//利用普通函数做回调函数，回调函数实现了任务的编辑者和使用者的分离，谁调用for_each()这个函数，就写这个回调函数的入口地址
	for_each(v1.begin(), v1.end(), ShowfuncElemt02);
	ShowElemt<int> show1;
	//for_each算法的函数对象的传递 是元素值传递，不是引用传递
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();
	cout << "通过for_each算法的返回值看调用的次数！" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);
	show1.printN();
}

template <typename T>
class IsDiv{
public:
	IsDiv(const T &divisor){
		this->divisor = divisor;
	}
	bool operator()(T& t){
		return  (t%divisor == 0);
	}
protected:
private:
	T divisor;
};

//一元函数对象和一元函数谓词
void main43(){
	vector<int> v2;
	for (int i = 10; i < 33; i++){
		v2.push_back(i);
	}
	int a = 4;
	IsDiv<int> myDiv(a);
	find_if(v2.begin(), v2.end(), myDiv);
	vector<int>::iterator it;
	it = find_if(v2.begin(), v2.end(), IsDiv<int>(a));
	if (it == v2.end()){
		cout << "容器中没有值是4 的元素!" << endl;
	}
	else{
		cout << "第一个是被4整除的元素 " << *it << endl;
	}

}

template <typename T>
class SumAdd{
public:
	T operator() (T t1,T t2){
		return t1 + t2;
	}
protected:
private:
};
//二元函数对象和二元函数谓词
void main45(){
	//v3 = v1+v2 
	vector<int> v1, v2;
	vector<int> v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++){
		cout << *it <<" "; 
	}
	cout << endl;
}

bool MyCompare(const int&a,const int& b){
	return a < b;
}
//二元谓词
void main46(){
	vector<int> v1(10);
	for (int i = 0; i < 10; i++){
		int tmp = rand() % 100;
		v1[i] = tmp;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//遍历这个容器 通过算法遍历
	for_each(v1.begin(), v1.end(), ShowfuncElemt02);
	cout << endl;

	sort(v1.begin(), v1.end(), MyCompare);
	for_each(v1.begin(), v1.end(), ShowfuncElemt02);
	cout << endl;

}
struct CompareNoCase{
	bool operator()(const string &str1, const string &str2){
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(),str1.end(),str1_.begin(),tolower);//定义函数对象

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);//定义函数对象
		return (str1_ < str2_);//从小到大进行排序
	}
};
void main47(){
	set<string> set1;
	set1.insert("aaa");
	set1.insert("bbb");
	set1.insert("ccc");
	set<string>::iterator it2 = set1.find("aaa");//find函数默认情况下是区分大小写的
	if (it2 == set1.end()){
		cout << "没有查找到aaa" << endl;
	}
	else{
		cout << "不区分大小写的查到aaa" << endl;
	}
	set<string, CompareNoCase> set2;
	set2.insert("bbbb");
	set2.insert("cccc");
	set2.insert("dddd");
	set2.insert("aAa");
	set<string, CompareNoCase>::iterator it = set2.find("aAa");
}
//函数对象是属于类对象，能突破函数的概念 能保持 调用状态信息
int main(){
	//main41();//函数对象的（）的执行 很像一个函数  也称为仿函数
	//main42();
	//main43();//一元谓词
	//main45();
	//main46();
	main47();
	return 0;
}