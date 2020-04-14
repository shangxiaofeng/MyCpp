#include <iostream>
using namespace std;


int main01(){
	"abc" //直接写出来的字符串是字面字符串
		"";//空字符串
	char arr1[] = "abc";
	char arr2[] = { 'a', 'c','v','\0' };
	char arr3[] = { 'a', 'c', 'v' };
	//求字符串的长度 strlen();
	int len = strlen(arr1);
	int len2 = strlen(arr2);
	int len3 = strlen(arr3);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	cout << len << endl;
	cout << len2 << endl;
	cout << len3 << endl;//随机值
	return 0;
}

int main(){
	char arr[] = { "c:\test\32\test.c" };
	int len = strlen(arr);
	cout << len << endl;
	//转义字符 转换字符的意思  /t是水平制表符 table键
	printf("c:\test\32\test.c");//打印你会发现什么？
	printf("\a\a\a\a\a\a\a");//\a 是一个警告字符
	return 0;
}