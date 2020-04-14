
#include<iostream>
#include<string>
using namespace std;


int main01(){
	int n = 9;
	string s2("shangxiaofeng");
	string m(n, 'a');//初始化为n个‘a'
	string s1(s2); //将s1初始化为s2的一个副本
	string s3;//s3是一个空的字符串
	return 0;
}

int main02(){
	string world;
	while (cin >> world){
		cout << world << endl;
	}
	return 0;
}

int main(){
	string line;
	while (getline(cin,line)){
		cout << line << endl;
	}
	return 0;
}