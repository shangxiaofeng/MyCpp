#include <fstream>
#include <iostream>

using namespace std;

void move(int n, char i ,char j){
	cout << "把" << n << "号从" << i << "移动到" << j << endl;
}

void Hannoi(int n, char a,char b,char c){
	if (n == 1){
		move(n,a, c);
	}
	else{
		Hannoi(n - 1, a, c, b);
		move(1, a, c);
		Hannoi(n - 1, b, a, c);
	}
}
int main(){
	cout << "以下是10层汉诺塔的问题：" << endl;
	Hannoi(3, 'a', 'b', 'c');
	ofstream close();
	cout << "程序运行over！" << endl;

	return 0;
}