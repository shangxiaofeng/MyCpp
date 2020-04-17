#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[10];
	for (int i = 0; i < 10; ++i){
		cin >> a[i];
	}
	sort(a, a + 10, less<int>());          //范围，尾地址，最后一个元素的下一个位置。因此为a+20.排序方法就不需要传参数了
	for (int i = 0; i < 10; i++) {
		cout << a[i] <<" ";
	}
	cout << endl;
	return 0;
}