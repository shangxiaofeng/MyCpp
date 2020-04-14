#include<iostream>
#include"algorithm"
#include"vector"
#include"string"
#include"set"
#include"functional"
#include"list"
using namespace std;


//plus<int> 预定义好的函数对象 能实现不同类型的加法运算
//实现了数据类型和算法的分离 -》通过函数对象的技术实现的
//思考：怎么样知道的plus<type> 是两个参数的？ 我们应该追踪源码
void main51(){
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y);
	cout << "z = " << z << endl;

	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = " bbb";
	string s3 = stringAdd(s1, s2);
	cout << "s3 = " << s3 << endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("ddd");
	sort(v1.begin(), v1.end(), greater<string>());
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << *it << endl;
	}
	//求ccc出现分个数
	string sc= "ccc";
	//equal_to<string>()有两个参数 left参数来自左容器 right参数来自sc 
	//bind2nd 函数适配器,作用是把预定义函数对象和第二个参数绑定
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
	cout << "num = " << num << endl;
}


class IsGreat{
public: 
	IsGreat(int i){
		m_num = i;
	}
	bool operator()(int &num){
		if (num > m_num){
			return true;
		}
		else{
			return false;
		}
	}
private:
	int m_num;
};
//函数适配器综合案例
void main52(){
	vector<int> v1;
	for (int i = 0; i < 10; i++){
		v1.push_back(i+1);
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//求大于3 的个数
	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1:" << num1 << endl;
	//通过谓词求大于2 的个数
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2:" << num2 << endl;

	//通过预定义的函数对象求大于2的个数
	//great<int>() 有两个参数 左参数来自容器的元素，右参数固定成2，（通过bind2nd做的） 
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),2));
	cout << "num3= " << num3 << endl;

	//求奇数的个数 bind2nd(modulus<int>(), 2)
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "奇数num4= " << num4 << endl;

	//求偶数的个数 
	int num5= count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "偶数num5= " << num5 << endl;
}
int main(){
	//main51();
	main52();

	return 0;
}