#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct Test{
	char* name;//没有分配内存空间
	int age;
	char sex[3];
}Test, *pTest;

int main(){
	pTest t = (Test*)malloc(sizeof(Test));
	assert(t != NULL);
	t->age = 28;
	strcpy(t->sex, "a");
	t->name = (char*)malloc(sizeof(char)*10);
	assert(t->name != NULL);
	strcpy(t->name, "xiaofeng");
	free(t);
	free(t->name);
	return 0;
}