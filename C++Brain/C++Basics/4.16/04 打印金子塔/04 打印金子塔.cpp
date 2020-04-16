#include<stdio.h>

int main(){
	int line;
	int i, j,k;
	printf("ÇëÊäÈë½ğ×ÖËşµÄline£º");
	scanf_s("%d", &line);
	for (i = 0; i < line; ++i){
		for (j = 0; j < line - i; ++j){
			printf(" ");
		}
		for (k = 0; k < i*2+1; ++k){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}