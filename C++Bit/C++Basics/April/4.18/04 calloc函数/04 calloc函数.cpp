#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int main(){
	int *p = (int*)calloc(10, sizeof(int));
	assert(p != NULL);
	for (int i = 0; i < 10; ++i){
		p[i] = i + 1;
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	p == NULL;

	return 0;
}