#include<iostream>
using namespace std;

int main(){
	char arr01[] = "#############";
	char arr02[] = "shang";
	strcpy_s(arr01, arr02);//strcpy时字符串拷贝函数的使用
	printf("%s\n", arr01);
	memset(arr02, '*', 5);
	printf("%s\n", arr02);
	return 0;
}