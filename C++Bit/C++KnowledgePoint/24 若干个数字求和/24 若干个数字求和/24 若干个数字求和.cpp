#include<iostream>
using namespace std;

//方法1
int addSum01(int n){
	int sum = 0;
	for (int i = 0; i <= n; i++){
		sum += i;
	}
	cout << "累积求和为：" << sum << endl;
	return 0;
}

//方法2
int addSum02(int n){
	int sum = 0;
	if (n>0)
	sum = (1 + n)*n / 2;
	cout << "累积求和为：" << sum << endl;
	return 0;
}

int addSum03(int n){
	int sum = 0;
}
int main(){
	int n;
	cout << "请输入您要求前n项和的n：";
	cin >> n;
	//addSum01(n);
	//addSum02(n);
	addSum03(n);
	return 0;
}
