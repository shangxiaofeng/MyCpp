#include<stdio.h>
#include<assert.h>
int myStrncmp(const char * ch1, const char * ch2, int n){
	assert(ch1 != NULL && ch2 != NULL);
	return 0;
}
int myStrcmp(const char *ch1, const char* ch2){
	assert(ch1 != NULL && ch2 != NULL);
	int result = 0;
	while (*ch1 != 0 || *ch2 != 0){
		//通过减法的方式完成 比较	
		if ((result = *ch1 - *ch2) != 0){
			break;
		}
		ch1++;
		ch2++;
	}
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	return result;
}

int main(){
	char ch1[] = { "shang" };
	char ch2[] = { "shi" };
	printf("%d\n", myStrcmp(ch1, ch2));
	printf("%d\n", myStrncmp(ch1, ch2,3));
	return 0;
}