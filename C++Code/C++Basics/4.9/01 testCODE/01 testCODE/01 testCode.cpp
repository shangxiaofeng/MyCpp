#include<stdio.h>
void print_arr1(int arr[3][5], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++){
		for (j = 0; j<col; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
}

void print_arr2(int(*arr)[5], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++){
		for (j = 0; j<col; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main04(){
		int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		print_arr1(arr, 3, 5);
		//数组名arr，表示首元素的地址
		//但是二维数组的首元素是二维数组的第一行
		//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
		//可以数组指针来接收
		print_arr2(arr, 3, 5);
		return 0;
	}

int main03(){
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int(*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p
	//但是我们一般很少这样写代码
	return 0;
}
int main02(){
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);
	printf("&arr= %p\n", &arr);
	printf("arr+1 = %p\n", arr + 1);
	printf("&arr+1= %p\n", &arr + 1);
	return 0;
}

int main01(){
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr);
	return 0;
}

int main06(){
	char ch = 'w';
	char* p = &ch;
	*p = 'w';
	return 0;
}

int main07(){
	char* ptr = "hello bit.";
	printf("%s\n", ptr);
	return 0;
}


int main08(){
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	return 0;
}


//void test(int arr[])//ok?ok
//{}
//void test(int arr[10])//ok?ok
//{}
//void test(int *arr)//ok?ok
//{}
void test2(int *arr[20])//ok?ok
{}
//void test2(int **arr)//ok?ok
//{}
int main09(){
	int arr[10] = { 0 };
	int *arr2[20] = { 0 };//指针数组 
	//test(arr);
	//test2(arr2);
	return 0;
}




//void test(int *arr)//ok？
//{}
//void test(int* arr[5])//ok？no
//{}
//void test(int arr[][])//ok？no
//{}
//void test(int **arr)//ok？no
//{}
//void test(int arr[3][5])//ok？
//{}
//void test(int(*arr)[5])//ok？ok
//{}
//void test(int arr[][5])//ok？ok
//{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。 //这样才方便运算。
//int main10(){
//	int arr[3][5] = { 0 };
//	test(arr);
//	return 0;
//}

//void printY(int *p, int sz){
//	int i = 0;
//	for (i = 0; i < sz; i++){
//		printf("%d\n", *(p + i));
//	}
//}
//int main11{
//		int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//		int *p = arr;
//		int sz = sizeof(arr) / sizeof(arr[0]);     //一级指针p，传给函数
//		printY(p, sz);
//		return 0;
//}

//#include <stdio.h>
//void test(int** ptr){
//	printf("num = %d\n", **ptr);
//}
//int main12(){
//	int n = 10;
//	int*p = &n;
//	int **pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}


#include <stdio.h>
void test(){
	printf("hehe\n");
}
int main13(){
	printf("%p\n", test);
	printf("%p\n", &test);
	return 0;
}
//首先，signal是函数名，它有两个参数（int ， void(*)(int)），
//一个是int型参数，一个是函数指针（返回类型为void，参数为int），
//这个函数的返回值是一个指针*signal(int, void(*)(int)) 指向函数，
//指向的这个函数返回类型为void成为函数指针的类型，

//void test(const char* str){
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针pfun
//	void(*pfun)(const char*) = test;
//	//函数指针的数组pfunArr
//	void(*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//指向函数指针数组pfunArr的指针ppfunArr
//	void(*(*ppfunArr)[10])(const char*) = &pfunArr;
//	return 0;
//}

#include <stdio.h>

int int_cmp(const void * p1, const void * p2){
	return (*(int *)p1 - *(int *)p2);
}

void _swap(void *p1, void * p2, int size){
	int i = 0;
	for (i = 0; i< size; i++){
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bubble(void *base, int count, int size, int(*cmp)(void *, void *)){
	int i = 0;
	int j = 0;
	for (i = 0; i< count - 1; i++){
		for (j = 0; j<count - i - 1; j++){
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0){
				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

int main(){
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"};
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}