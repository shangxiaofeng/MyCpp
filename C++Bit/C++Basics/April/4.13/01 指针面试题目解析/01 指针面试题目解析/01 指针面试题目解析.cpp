#include<stdio.h>
#include<string.h>

int main01(){
	//一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a + 0));//16? 
	printf("%d\n", sizeof(*a)); //4
	printf("%d\n", sizeof(a + 1)); //???
	printf("%d\n", sizeof(a[1])); //4
	printf("%d\n", sizeof(&a));//4
	printf("%d\n", sizeof(*&a));//4
	printf("%d\n", sizeof(&a + 1));//16
	printf("%d\n", sizeof(&a[0])); //4
	printf("%d\n", sizeof(&a[0] + 1));//4
	return 0;
}

int main02(){
	//字符数组
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr + 0));//4？？？
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4？？？
	printf("%d\n", sizeof(&arr + 1));//4？？？
	printf("%d\n", sizeof(&arr[0] + 1));//4？？？
	printf("%d\n", strlen(arr));//随机值
	printf("%d\n", strlen(arr + 0));//随机值
	/*printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));*/
	printf("%d\n", strlen(&arr[0] + 1));//随机值
	return 0;
}
int main(){
	//字符数组
	char arr01[] = "abcdef";
	printf("%d\n", sizeof(arr01));//7
	printf("%d\n", sizeof(arr01 + 0));
	printf("%d\n", sizeof(*arr01));
	printf("%d\n", sizeof(arr01[1]));
	printf("%d\n", sizeof(&arr01));
	printf("%d\n", sizeof(&arr01 + 1));
	printf("%d\n", sizeof(&arr01[0] + 1));
	printf("%d\n", strlen(arr01));
	printf("%d\n", strlen(arr01 + 0));
	/*printf("%d\n", strlen(*arr01));
	printf("%d\n", strlen(arr01[1]));
	printf("%d\n", strlen(&arr01));
	printf("%d\n", strlen(&arr01 + 1));*/
	printf("%d\n", strlen(&arr01[0] + 1));
	return 0;
}

int main03(){
	//字符数组
	char *p = "abcdef";
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));
	printf("%d\n", strlen(p)); 
	printf("%d\n", strlen(p + 1));
	/*printf("%d\n", strlen(*p));
	printf("%d\n", strlen(p[0])); 
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(&p + 1)); */
	printf("%d\n", strlen(&p[0] + 1));
	return 0;
}

int main04(){
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a)); 
	printf("%d\n", sizeof(a[0][0])); 
	printf("%d\n", sizeof(a[0])); 
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1))); 
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1))); 
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));
	return 0;
}