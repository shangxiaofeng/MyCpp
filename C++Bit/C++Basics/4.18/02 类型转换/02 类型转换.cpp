#include <stdio.h>

int main(){
	char ch = 'a';
	int * p = (int*)&ch;
	double d = 3.14;
	void * r = &ch;//void * ∑∫–Õ÷∏’Î
	r = &d;
	*(double* )r;
	return 0;
}