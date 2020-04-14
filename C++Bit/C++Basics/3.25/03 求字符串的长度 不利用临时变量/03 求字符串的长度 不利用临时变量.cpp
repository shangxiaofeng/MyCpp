#include<stdio.h>
//方法1 利用临时变量
int my_String01(char* arr){
	int count = 0;
	while (*arr != '\0'){
		count++;
		arr++;
	}
	return count;
}

//方法2 利用递归的方法 不需要临时变量
int my_String02(char* str){
	if (*str != '\0'){
		return 1 + my_String02(str + 1);
	}
	else{
		return 0;
	}
}
int main(){
	char arr[] = "shangxiaofeng";
	int len01 = my_String01(arr);
	int len02 = my_String02(arr);
	printf("1字符串的长度为：%d\n", len01);
	printf("2字符串的长度为：%d\n", len02);

	return 0;
}


