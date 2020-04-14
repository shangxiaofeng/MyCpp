////接受一个整型值（无符号），按照顺序打印它的每一位。 例如： 输入：1234，输出 1 2 3 4.

#include<stdio.h>

void Print(unsigned n){
	if (n > 9){
		unsigned m = n / 10;
		Print(m);
	}
		printf("%d ", n%10);
}

int main(){
	unsigned int num = 0;
	printf("请输入您要打印的数字：");
	scanf_s("%d", &num);
	Print(num);
	return 0;
}