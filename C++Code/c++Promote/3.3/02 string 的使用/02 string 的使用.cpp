#include<iostream>
#define  D_SCL_SECURE_NO_WARNINGS
#include"string"
#include"algorithm"
using namespace std;

//void stringofuse01(){
//	string s1 = "shangxiaofeng";
//	string s2 = "shixuanyu";
//	string s3 = s2; //通过拷贝构造函数 来初始化对象s3
//	string s4(10, 'a');//表示10个‘a'
//	cout << "s1= " << s1 << endl;
//	cout << "s2= " << s2 << endl;
//	cout << "s3= " << s3 << endl;
//	cout << "s4= " << s4 << endl;
//}
////string的遍历
//
//void stringofuse02(){
//	string s1 = "shangxiaofeng";
//	//数组遍历
//	for (int i = 0; i < s1.length(); i++){
//		cout << "s1[i]= " << s1[i] << " ";
//	}
//	cout << endl;
//	//迭代器 遍历
//	for (string::iterator it = s1.begin(); it != s1.end(); it++){
//		cout << "*iT=" << *it << " ";
//	}
//	cout << endl;
//	try{
//		for (int i = 0; i < s1.length()+3; i++){
//			cout << s1.at(i) << " ";//抛出异常
//		}
//	}
//	catch (...){
//		cout << "发生异常！" << endl;
//	}
//	cout << endl;
//}
//
////字符指针和string的转换
//void stringofuse03(){
//	string s1 = "shangxiaofeng";
//	//s1--->char*
//	cout << s1.c_str() << endl;//利用c_str（）函数，返回内存的首地址
//	//char* --->string
//
//	//s1的内容拷贝到buf中,往buf所指向的内存空间拷贝数据
//	char buf[128];
//	s1.copy(buf, 3, 0);//从0开始只拷贝3个字符串
//	cout << buf << endl;
//}

//字符串的 +连接
void stringofuse04(){
	string s1 = "shangxiaofeng";
	string s2 = "shixuanyu";
	s1 = s1 + s2;
	cout << s1 << endl;
	string s3 = "xiaoxiao";
	string s4 = "xuanyu";
	s3.append(s4);
	cout << "s3 = " << s3 << endl;
}

//字符串的查找和替换
void stringofuse05(){
	string s1 = "i am a good people,yes good sure good!";
	int index = s1.find("good", 0);//位置下标从0开始，查找good 字符串 s1.find("good",0);
	cout << "index= " << index << endl;
	//案例1 ：求good 的出现次数 和出现的下标 属于字符串的查找
	int offindex = s1.find("good ",0);
	while (offindex != string::npos){
		cout << "offindex:" << offindex << endl;
		offindex = offindex + 1;
		offindex = s1.find("good", offindex);
	}
	cout << "s1 = " << s1 << endl;
	//案例2 把小写的good——》替换成GOOD
	int offindex02 = s1.find("good ", 0);
	while (offindex02 != string::npos){
		cout << "offindex02:" << offindex02 << endl;
		s1.replace(offindex02, 3, "GOOD");//把good 删除后，用GOOD替换 利用函数replace

		offindex02 = offindex02 + 1;
		offindex02 = s1.find("good", offindex02);
	}
	cout << "s1替换后的结果：" << s1 << endl;

	string s3 = "shanGxiaofengshangshang";
	s3.replace(0, 3, "SHA");//从0开始到3个字符，换成SHA  属于字符串的替换  
	cout << "s3= " << s3 << endl;
} 

//截断（区间的删除和插入）
void stringofuse06(){
	//需要删除字符串中的l
	string s1 = "hello01 hello02 hello03 world!";
	string::iterator it = find(s1.begin(), s1.end(), 'l');//通过find算法 扫描这个字段串 返回迭代器
	if (it != s1.end()){
		s1.erase(it);
	}
	cout << "删除后的结果：" << s1 << endl;

	//头插法
	s1.insert(0, "SSS");
	cout << "s1 插入之后：" << s1 << endl;
	//尾插法
	s1.insert(s1.length(), "ccc");
	cout << "s1尾插法的结果为：" << s1 << endl;
	cout << "s1 的长度为：" << s1.length() << endl;
	s1.erase(s1.begin(), s1.end());
	cout << "s1 全部删除后为： " << s1 << endl;
	cout << "s1 的长度为：" << s1.length() << endl;
}

//通过transform 变化大小写 如下：
void stringofuse07(){
	string s1 = "AAAAbbbb";
	//1、函数的入口地址 2函数对象 3 预定义的函数对象
	transform(s1.begin(), s1.end(),s1.begin(),toupper);
	cout << "s1 = " << s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(),s2.begin(),tolower);
	cout << "s2 =" << s2 << endl;
	


}

int main(){

	//stringofuse01();
	//stringofuse02();
	//stringofuse03();
	//stringofuse04();
	stringofuse05();
	//stringofuse06();
	//stringofuse07();
	return 0;
}