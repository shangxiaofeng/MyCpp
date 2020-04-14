#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main01()
{
	//二级指针
	int a = 10;
	int* pa = &a;    //一级指针
	int** ppa = &pa; //ppa就是二级指针
	printf("%d\n", **ppa);
	**ppa = 200;
	//200
	printf("%d\n", **ppa);
	printf("%d\n", a);

	return 0;
}

//
//指针数组
int main()
{
	//int arr[10] = {0};//整形数组 - 存放整形数据
	//char ch[5] = { 0 };//字符数组 - 存放字符数据
	                   //指针数组 - 存放指针（地址）的
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int* arr2[4] = {&a, &b, &c, &d};//整形指针数组
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(arr2[i]));
	}

	//char* arr3[5];
	return 0;
}

//char short int long float double - 内置类型
//学生:名字+学号+年龄+性别
//书
//复杂对象-复杂类型
//C语言提供了一个：struct - 结构体关键字
//
//学生的类型
//struct Stu
//{
//	//描述学生的相关属性
//	char name[20];
//	char id[18];
//	short age;
//	char sex[5];
//}s2,s3,s4;//s2,s3,s4 就是创建的结构体变量-全局变量
//
//int main()
//{
//	//s1是局部变量
//	struct Stu s1;//学生对象s1
//
//	return 0;
//}
//
//struct S
//{
//	int a;
//	char c;
//	char arr[10];
//	double d;
//};
//
//typedef struct T
//{
//	char buf[20];
//	struct S s;
//	int *p;
//}T;
//
////typedef - 类型定义- 类型重定义
//
//int main()
//{
//	int a = 10;
//	//struct S s = {100, 'w', "bit", 3.14};
//	//
//	//结构体变量.成员名
//	//结构体指针->成员名
//	//
//	T st = { "hello bit", {1000, 'b', "abcdef", 4.4}, &a};
//	T* pt = &st;
//	printf("%s\n", pt->buf);
//	printf("%lf\n", pt->s.d);
//
//	//printf("%s\n", st.buf);
//	//printf("%d\n", st.s.a);
//	//printf("%c\n", st.s.c);
//	//printf("%s\n", st.s.arr);
//	//printf("%lf\n", st.s.d);
//	//printf("%d\n", *(st.p));
//
//	//struct T st2;
//
//	return 0;
//}
//struct Stu
//{
//	//描述学生的相关属性
//	char name[20];
//	char id[18];
//	short age;
//	char sex[5];
//};//s2,s3,s4 就是创建的结构体变量-全局变量
//
//void print1(struct Stu tmp)
//{
//	printf("%s\t%s\t%d\t%s\n", tmp.name, tmp.id, tmp.age, tmp.sex);
//}
//
//void print2(struct Stu* ps)
//{
//	printf("%s\t%s\t%d\t%s\n", ps->name, ps->id, ps->age, ps->sex);
//}
//
//int main()
//{
//	struct Stu s = {"张三", "2019010305", 20, "男"};
//	print1(s);
//	print2(&s);
//
//	return 0;
//}

int Add(int x, int y)
{
	int z = x + y;
	return z;
}

int main0()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d\n", c);
	return 0;
}