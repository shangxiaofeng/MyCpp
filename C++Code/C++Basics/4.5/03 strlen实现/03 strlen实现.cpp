/*
03 strlen实现:模拟实现库函数strlen
*/

#include<stdio.h>
#include<string.h>
#include<assert.h>

int MyStrlen(const char * s){
	assert(s != NULL);
	int count = 0;
	while (*s !='\0'){
		s++;
		count++;
	}
	return count;
}
int main(){
	char c1[] = "hello SLAM!";
	int len = strlen(c1);
	printf("len = %d\n", len);
	printf("length = %d\n", MyStrlen(c1));
	return 0;
}