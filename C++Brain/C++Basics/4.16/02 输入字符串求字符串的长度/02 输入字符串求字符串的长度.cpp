#include<stdio.h>
#include<string.h>

int main(){
	char name[32];
	printf("ÇëÊäÈëÄúµÄÃû×Ö£º");
	fgets(name,sizeof(name),stdin);
	int len = strlen(name);
	printf("len = %d\n", len);
	return 0;
}