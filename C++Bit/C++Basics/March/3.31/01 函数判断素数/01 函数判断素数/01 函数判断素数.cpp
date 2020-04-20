
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int sushu(){
	int i, leap = 1;
	int m;
	scanf("%d", &m);
	for (i = 2; i<m; i++){
		/*判断条件为真时，即表示m存在1和自身以外的其他因数。
		判断条件是为假时，即不会执行此if下的语句，leap值不变，仍为1，程序继续向下执行*/
		if (m%i == 0){
			leap = 0;
			break;
		}
	}
	if (leap == 1){
		return leap;
	}
}
int main(){
	switch (sushu()){
	case 1:
		printf("Prime!\n");
		break;
	case 0:
		printf("Not Prime!\n");
		break;
	}
	return 0;
}