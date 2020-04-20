#include<stdio.h>



typedef struct Test{
	char a;
	double b;
	int c;
}Test,*pTest;
int main01(){
	Test t = { 'a', 12.34, 100 };//在c++中，等号可以不写
	pTest pT = &t;
	printf("a = %c,b = %f,c = %d\n", t.a, t.b, t.c);
	printf("a = %c,b = %f,c = %d\n", pT->a, pT->b, pT->c);
	return 0;
}

//默认对齐值是最大的值是8个字节
//1、基本数据类型有一个对齐值(就是int char double 等类型的字节空间)
//2、自定义类型也有一个对齐值，是内部成员的最大值
//3、程序指定对齐值 #pragma pack（n） n = 2的幂次方
//4、程序的有效对齐值，程序指定对齐值和数据类型对齐值得较小值

typedef struct Test01{
	char a;//1+7
	double b;//8
	int c;//4+4
}Test01;

void main02(){
	Test01 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test01 size = %d\n", sizeof(Test01));
}


//最大的默认是值是8
typedef struct Test02{
	char a;//1+3
	int c;//4+0
	double b;//8
	
}Test02;

void main03(){
	Test02 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test02 size = %d\n", sizeof(Test02));
}



//#pragma pack(8)//指定默认的字节数
typedef struct Test04{
	char a;
	int c;
	double b;

}Test04;

void main04(){
	Test04 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test04 size = %d\n", sizeof(Test04));
}





//#pragma pack(2)//指定默认的字节数
typedef struct Test05{
	double b;//8
	char a;//2+2
	int c;//4

}Test05;

void main05(){
	Test05 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test05 size = %d\n", sizeof(Test05));
}

typedef struct Test06{
	double b;//8
	char a;//2+2
	int c;//4
	char d;//1+7
}Test06;

void main06(){
	Test06 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test05 size = %d\n", sizeof(Test06));
}




typedef struct Test07{
	char a;//1+1
	short b;//2
	int c;//4
	double d;//8
}Test07;

void main07(){
	Test07 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test07 size = %d\n", sizeof(Test07));
}



//#pragma pack(1)
typedef struct Test08{
	char a;//1
	short b;//2
	int c;//4
	double d;//8
}Test08;

void main08(){
	Test08 t;
	t.a = 'a';
	t.b = 90.3;
	t.c = 90;
	printf("Test08 size = %d\n", sizeof(Test08));
}



typedef struct Test09{
	char a;        //1+3
	struct {      
		int b;  //4
		int c;  //4
		char d; //1+3
	};//12
	int e;//4
}Test09;

void main09(){
	Test09 t;
	printf("Test09 size = %d\n", sizeof(Test09));
}



typedef struct Test10{
	char a;      //1+7
	struct {
		int b;//4
		char c;//2+2
		double d;//8
	};//16
	short e;//2+8
}Test10;

void main10(){
	Test10 t;
	printf("Test10 size = %d\n", sizeof(Test10));
}




typedef struct Test11{
	short a;      //2+6
	struct {
		int b[5];//20+4
		double c;//8
		char d;//1+7
	};//40
	int e;//4+4
}Test11;

void main11(){
	Test11 t;
	printf("Test11 size = %d\n", sizeof(Test11));
}


//位域的存储两个限制条件
//1 不能跨字节存储
//2 不能跨类型存储

struct A{
	int _a : 2; // 00000000000000  0000000000  00000   00 
	int _b : 5; // 0000 0000 0000 0000 0000000000000000 
	int _c : 10;
	int _d : 30;
};

int main12(){
	printf("%d\n", sizeof(struct A));
	return 0;
}

typedef struct S{
	char a : 3;//一个字节8个比特位   0000 0000
	char b : 4;
	char c : 5;
	char d : 4;
}S;
int main13(){
	printf("S size	= %d\n", sizeof(struct S));//求的字节空间的大小
	S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}


typedef enum Testt{
	ADD = -90,
	SUB,
	DIV = 90,
	MOL
}Testt;

int main14(){

	printf("ADD= %d\n", ADD);
	printf("SUB= %d\n", SUB);
	printf("DIV= %d\n", DIV);
	printf("MOL= %d\n", MOL);
	printf("sizeof ADD = %d\n", sizeof(ADD));
	return 0;
}

//联合类型的声明
//开辟空间依据最大的类型开辟空间 因此该联合体的空间为 8个字节
//联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为
//联合至少得有能力保存最大的那个成员）。
union Un{
	char c;
	int i;
	double b;
};
int main(){
	//联合变量的定义
	union Un un;
	//计算连个变量的大小
	printf("%d\n", sizeof(un));// 
	printf("%d\n", &(un.i));//同一个地址 同一个空间
	printf("%d\n", &(un.b));
	printf("%d\n", &(un.c));
	printf("%x\n", un.i);
	printf("%x\n", un.c);
	printf("%x\n", un.b);
}
