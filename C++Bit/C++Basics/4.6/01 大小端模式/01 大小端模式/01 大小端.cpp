#include<iostream>
#include<stdio.h>
using namespace std;

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}

int main(){
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i<1000; i++){
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
