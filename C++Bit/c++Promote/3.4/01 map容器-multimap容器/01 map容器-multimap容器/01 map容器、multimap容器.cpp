#include<iostream>
#include<map>
#include"string"
using namespace std;

//map 元素的添加  删除 遍历

void MapUse01(){
	map<int, string> m1;
	//map元素的添加
	//方法1、以名值对的方式添加
	m1.insert(pair<int,string>(1,"Teacher01"));
	m1.insert(pair<int, string>(2, "Teacher02"));
	m1.insert(pair<int, string>(3, "Teacher03"));
	//方法2、
	m1.insert(make_pair(4, "Teacher04"));
	m1.insert(make_pair(5, "Teacher05"));
	//方法3、
	m1.insert(map<int, string>::value_type(6, "Teacher06"));
	//方法4、
	m1[7] = "Teacher07";
	m1[8] = "Teacher08";

	//map元素的遍历
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "遍历结束" << endl;
	//容器的删除,利用徒步删法
	while (!m1.empty()){
		map<int, string>::iterator it = m1.begin();
		cout << it->first << "\t" << it->second << endl;
		m1.erase(it);
	}
}


//四种插入方法的异同
//前三种方法返回的是pair<iterator,bool> 返回<迭代器的位置，结果> 若key存在，则报错
//如通过方法4 若key相同已经存在，则修改value的值
void MapUse02(){
	map<int, string> m1;
	//map元素的添加
	//方法1、以名值对的方式添加
	pair<map<int,string>::iterator,bool>  mypair01 = m1.insert(pair<int, string>(1, "Teacher01"));
	m1.insert(pair<int, string>(2, "Teacher02"));
	m1.insert(pair<int, string>(3, "Teacher03"));
	//方法2、
	pair<map<int, string>::iterator, bool>  mypair04 =  m1.insert(make_pair(4, "Teacher04"));
	m1.insert(make_pair(5, "Teacher05"));
	//方法3、
	pair<map<int, string>::iterator, bool>  mypair06 =  m1.insert(map<int, string>::value_type(6, "Teacher06"));
	//方法4、
	m1[7] = "Teacher07";
	m1[8] = "Teacher08";

	//map元素的遍历
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "遍历结束" << endl;
	//如何判读插入是否成功呢?
	pair<map<int, string>::iterator, bool>  mypair07 = m1.insert(map<int, string>::value_type(7, "Teacher07"));
	if (mypair07.second != true){
		cout << "插入失败！" << endl;
	}
	else{
		cout << mypair07.first->first << "\t" << mypair07.first->second << endl;
	}		
}

void MapUse03(){
	map<int, string> m1;
	//map元素的添加
	//方法1、以名值对的方式添加
	pair<map<int, string>::iterator, bool>  mypair01 = m1.insert(pair<int, string>(1, "Teacher01"));
	m1.insert(pair<int, string>(2, "Teacher02"));
	m1.insert(pair<int, string>(3, "Teacher03"));
	//方法2、
	pair<map<int, string>::iterator, bool>  mypair04 = m1.insert(make_pair(4, "Teacher04"));
	m1.insert(make_pair(5, "Teacher05"));
	//方法3、
	pair<map<int, string>::iterator, bool>  mypair06 = m1.insert(map<int, string>::value_type(6, "Teacher06"));
	//方法4、
	m1[7] = "Teacher07";
	m1[8] = "Teacher08";

	//map元素的遍历
	for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++){
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "遍历结束" << endl;
	//map的查找
	map<int, string>::iterator it01 = m1.find(100); 

	//如何判断查找的成功与否,也就是异常的处理
	if (it01 == m1.end()){
		cout << "key值100 不存在！" << endl;
	}
	else{
		cout << it01->first << "\t" << it01->second << endl;
	}

	//map的equal_range
	pair<map<int,string>::iterator,map<int,string>::iterator> mypair = m1.equal_range(5);//返回两个迭代器 形成一个pair
	//第一个迭代器是大于等于5的位置
	//第二个迭代器是大于5的位置
	//获取结果
	if (mypair.first == m1.end()){
		cout << "第一个大于等于5 的位置不存在！" << endl;
	}
	else{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	//使用第二个迭代器
	if (mypair.second == m1.end()){
		cout << "第一个大于5 的位置不存在！" << endl;
	}
	else{
		cout << mypair.second->first << "\t" << mypair.second->second << endl;
	}

}
int main(){
	//MapUse01();
	//MapUse02();
	MapUse03();
	return 0;
}