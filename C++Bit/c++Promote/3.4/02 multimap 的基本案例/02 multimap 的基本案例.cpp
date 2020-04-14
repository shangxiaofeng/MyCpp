#include<iostream>
#include"map"
#include"string"
using namespace std;
//1个key值可以对应多个valude  =分组 
//公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人） 
//人员信息有：姓名，年龄，电话、工资等组成
//通过 multimap进行 信息的插入、保存、显示
//分部门显示员工信息 
class Person{
public:
	string name;
	int age;
	string tel;
	double sal;
public:

protected:
private:

};
void MultimapUse01(){
	Person p1, p2, p3, p4, p5;
	p1.name = "shangxiaofeng";
	p2.name = "shixuanyu";
	p3.name = "shangyafeng";
	p4.name = "shangxiaoli";
	p5.name = "chenqiang";
	p1.age = 28;
	p2.age = 26;
	p2.age = 26;
	p4.age = 30;
	p5.age = 29;
	multimap<string, Person> map2;
	//sale 销售部门
	map2.insert(make_pair("sale", p1));
	map2.insert(make_pair("sale", p2));
	//develop 部门
	map2.insert(make_pair("develop", p3));
	map2.insert(make_pair("develop", p4));
	//financial 财务部门
	map2.insert(make_pair("financial", p5));

	for (map<string, Person>::iterator it = map2.begin(); it != map2.end(); it++){
		cout << it->first << "\t" << it->second.name << endl;
	}
	cout << "遍历结束！" << endl;
	int num2 = map2.count("develop");
	cout << "develop 部门人数：" << num2<< endl;
	//打印开发部门员工的信息
	cout << "打印develop开发部门员工的信息" << endl;
	int tag = 0;
	map<string, Person>::iterator it2 = map2.find("develop");
	while (it2 != map2.end()&& tag<num2){
		cout << it2->first << "\t" << it2->second.name << endl; 
		it2++;
		tag++;	
	}
}

//如何修改容器 age = 28 的修改成18
void MultimapUse02(){
	Person p1, p2, p3, p4, p5;
	p1.name = "shangxiaofeng";
	p2.name = "shixuanyu";
	p3.name = "shangyafeng";
	p4.name = "shangxiaoli";
	p5.name = "chenqiang";
	p1.age = 28;
	p2.age = 26;
	p2.age = 26;
	p4.age = 30;
	p5.age = 29;
	multimap<string, Person> map2;
	//sale 销售部门
	map2.insert(make_pair("sale", p1));
	map2.insert(make_pair("sale", p2));
	//develop 部门
	map2.insert(make_pair("develop", p3));
	map2.insert(make_pair("develop", p4));
	//financial 财务部门
	map2.insert(make_pair("financial", p5));
	//按照条件 检索数据 进行修改
	cout << "按照条件 检索数据 进行修改" << endl;
	for (map<string, Person>::iterator it = map2.begin(); it != map2.end(); it++){
		//cout << it->first << "\t" << it->second.name << endl;
		if (it->second.age == 28){
			it->second.name = "shangshang";
		}
	}
	for (map<string, Person>::iterator it = map2.begin(); it != map2.end(); it++){
		cout << it->first << "\t" << it->second.name << endl;
		}
	
	cout << "遍历结束！" << endl;
}
int main(){
	//MultimapUse01();
	MultimapUse02();
	return 0;
}