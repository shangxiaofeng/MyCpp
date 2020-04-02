//用C语言在屏幕上输出以下图案：
#include<iostream>

int main() {
	int i, j;
	int n, m;
	for (i = 0; i<7; i++) {
		for (j = 7; j>i; j--) {
			printf(" ");
		}
		for (j = 0; j<2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
		for (n = 0; n <6; n++){
			for (m = 0; m<n+2; m++){
				printf(" ");
			}
			for (m = 11-2*n; m>0; m--){
				printf("*");
			}
			printf("\n");
	}
		return 0;
}