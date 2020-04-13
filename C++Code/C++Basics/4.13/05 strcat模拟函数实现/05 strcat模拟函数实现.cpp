#include<stdio.h>
#include<assert.h>

char *myStrcat(char* ch1, const char* ch2){
	assert(ch1 != NULL&& ch2 != NULL);
	char* temp = ch1;
	while (*temp != '\0'){
		temp++;
	}
	while (*ch2 != '\0'){
		*temp++ = *ch2++;
	}
	*temp = '\0';
	return ch1;
}

int  main(){
	char ch1[] = { "shang" };
	char ch2[] = { "xiaofeng" };
	printf("%s\n",myStrcat(ch1, ch2));
	return 0;
}