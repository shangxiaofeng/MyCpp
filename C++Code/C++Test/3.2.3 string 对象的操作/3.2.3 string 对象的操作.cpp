
#include<iostream>
#include<string>
using namespace std;

int main01(){
	/*string line;
	while (getline(cin, line)){
		cout << line << endl;
	}
*/
	string line("shang xiao feng");
	cout << "您输入字符串的长度为："<<line.size() << endl;
	cout << "size() 与 length()的区别：" << line.length() << endl;//两个实现的功能是一样的
	return 0;
}

int main(){
	string s1("shangxiaofeng");
	string s2("shangyafeng");
	if (s1.size() == s2.size()){
		cout << "s1 与s2 相等！" << endl;
	}
	else if(s1.size()>s2.size()){
		cout << "s1 大于s2！";
	}
	else{
		cout << "s2大于s1！" << endl;
	}
}