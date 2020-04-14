#include<iostream>
using namespace std;

int FIB(int n){
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2){
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main(){
	int n = 0;
	scanf_s("%d", &n);
	int result = FIB(n);
	printf("%d \n", result);
	return 0;
}