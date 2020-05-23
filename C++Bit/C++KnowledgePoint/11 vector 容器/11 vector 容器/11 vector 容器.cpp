#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//void printfV(vector<int> &v){
//	for (int i = 0; i < v.size(); i++){
//		cout << v[i]<< " ";
//	}
//	cout << endl;
//}

int main(){
	//vector 的四种初始化类型
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3(3, 6);
	vector<int> v4(8);

	//vector 的容器中压入元素
	v1.push_back(1);
	v1.push_back(9);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	//利用迭代器遍历vector中的元素 
	/*for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;*/
	//利用auto自动类型的推导
	for (auto it = v1.begin(); it != v1.end(); ++it){
	cout << *it << " ";
	}
	cout << endl;
	//这两种输出方式的不同 c++11 标准 ：遍历v1中的元素 用x表示
	for (auto x : v1){
		cout << x << " ";
	}
	cout << endl;
	//利用迭代器逆序遍历
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++){
		cout << *rit << " ";
	}
	cout << endl;
	//在vector中插入元素
	v1.insert(v1.begin()+1, 66);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	v1.insert(v1.begin(), 3, 17);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	v1.insert(v1.begin(), v3.begin(), v3.end());

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	//vector 容器的大小
	cout << "length:" << v1.size() << endl;
	//vector 容器的首尾元素
	cout << "首元素：" << v1.front() << endl;
	cout << "尾元素：" << v1.back() << endl;
	//vector 删除尾部元素
	v1.pop_back();
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	cout << v1.at(0) << endl;//如果下标越界, 使用at（）会抛出异常。 使用【】用报错 
	//vector的遍历 通过数组的方式 
	//printfV(v1);
	//查找元素
	auto pos = find(v1.begin(), v1.end(), 17);
	if (pos != v1.end()){
		cout << "pos = " << *pos << endl;
	}
	else{
		cout << "没有找到！" << endl;
	}
	

	//删除元素
	auto ps = v1.begin() + 3;//指向第四个元素
	v1.erase(ps);
	for (auto x : v1){
		cout << x << " ";
	}
	cout << endl;
	//排序
	cout << "默认升序排序：" << endl; 
	sort(v1.begin(), v1.end());//sort默认是升序
	for (auto x : v1){
		cout << x << " ";
	}
	cout << endl;
	cout << "降序排序" << endl;
	return 0;
}