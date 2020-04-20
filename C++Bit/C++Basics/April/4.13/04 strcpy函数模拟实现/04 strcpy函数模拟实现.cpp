#include<stdio.h>
#include<assert.h>
char *myStrcpy(char* ch1, const char* ch2){
	//先断言这个两个字符串是否为空，如有错误，这个函数可以实现错误的报出
	assert(ch1 != NULL&&ch2 != NULL);
	char *temp = ch1;//创建临时变量 保护原有的地址
	while (*ch2 != '\0'){
		*temp++ = *ch2++;
	}
	*temp = '\0';
	return ch1;
}
int main(){
	char ch1[] = { "shangxiaofeng" };
	char ch2[] = { "shixuanyu" };
	char *result = myStrcpy(ch1,ch2);
	printf("%s\n", result);
	return 0;
}