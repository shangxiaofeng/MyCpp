#include<stdio.h>
#include<assert.h>

//方法1 模拟实现strlen函数
int myStrlen01(const char* arr){
	assert(arr != NULL);
	int count = 0;
	while (*arr != '\0'){
		arr++;
		count++;
	}
	return count;
}

//方法2 模拟实现 strlen（）函数 ，利用递归
int myStrlen02(const char* arr){
	assert(arr != NULL);
	int count = 0;
	if (*arr == '\0'){
		return 0;
	}
	else{
		return count = 1 + myStrlen02(arr + 1);
	}
}
int main(){
	char arr[] = { "shangxiaofeng" };
	printf("len = %d\n",myStrlen01(arr));
	printf("len = %d\n", myStrlen02(arr));
	return 0;
}