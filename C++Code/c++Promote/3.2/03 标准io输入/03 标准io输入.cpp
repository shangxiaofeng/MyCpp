#include<iostream>
using namespace std;

int  main01(){
	char myBuf[1024];
	int myInt;
	int myLong;
	cin >> myInt;
	cin >> myLong;
	cin >> myBuf;
	cout << "myInt:" << myInt << ",myLong=" << myLong<< ",myBuf=" << myBuf << endl;
	return 0;
}
int main02 (){
	char ch;
	while ((ch = cin.get()) != EOF){
		cout << ch
			<< endl;
	}
	return 0;
}
int main03(){
	char a, b, c;
	cout << "如果缓冲区没有数据，则程序done！" << endl;
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << b << c << endl;
	cin.get(a).get(b).get(c);
	cout << a << b << c;
	return 0;
}

int main(){
	char buf01[256];
	char buf02[256];
	cout << "请输入一个字符串含有多个空格，例如aa  bbccdd "<<endl;
	cin >> buf01; 
	cin.ignore(2);//收纳两个空格
	cin.getline(buf02,256);
	cout << "buf01:" << buf01 << ",buf02=" << buf02 << endl;


	return 0;
}