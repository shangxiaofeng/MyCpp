#include<stdio.h>

#include<string.h>

void main01(){
	char dest[20] = "xiaofeng";
	char *src = "xuan";
	printf("dest = %s\n", dest);
	//strcpy();
	memcpy(dest, src, 4);
	printf("dest = %s\n", dest);
}

void main(){
	int ar[10];
	int br[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	memcpy(ar, br, sizeof(int) * 10);
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); ++i){
		printf("%d ", *(ar+i));
	}
	printf("\n");
}