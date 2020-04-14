#include<stdio.h>
#include<string.h>
#include<assert.h>
char * MyStrcpy(char*  c1, const char * c2){
	assert(c1 != NULL);
	assert(c2 != NULL);
	char* result =c1;
	while (*c1++ = *c2++){
		;
	}
	return result;
}
int main(){
	char c1[] = "bit science and konwledge";
	char c2[] = "BIT SAK";
	strcpy_s(c1,c2);
	printf("%s\n", c1);
	printf("%s\n", MyStrcpy(c1, c2));
	return 0;
}