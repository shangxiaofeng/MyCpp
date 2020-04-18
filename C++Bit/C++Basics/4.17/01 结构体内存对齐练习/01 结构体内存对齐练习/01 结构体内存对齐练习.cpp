#include<iostream>
#include<stdio.h>
#include<malloc.h>

//1
typedef struct{
	int a; //4
	char b;//1+1
	short c;//2
	short d;//2+2
}AA_t;

//2
struct A
{
	int a;//4
	short b;//2+2
	int c;//4
	char d;//1+3
};//16
struct B
{
	int a;//4
	short b;//2
	char c;//1+1
	int d;//4
};//12


#pragma pack(4)
int main01(int argc, char* argv[]){
	struct tagTest1{
		short a;//2
		char d;//1=1
		long b;//4
		long c;//4
	};//12
	struct tagTest2{
		long b;//4
		short c;//2+
		char d;//1+1
		long a;//4
	};//12
	struct tagTest3{
		short c;//2+2
		long b;//4
		char d;//1+3
		long a;//4
	};//16
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;

	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;
}



//3
int A = 2;
int B = 3;
struct _Record_Struct{
	unsigned char Env_Alarm_ID : 4;//8
	unsigned char Para1 : 2;//
	unsigned char state;//8
	unsigned char avail : 1;//8
}*Env_Alarm_Record;
struct _Record_Struct *pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * A+B);
//当A=2， B=3时，pointer分配（ ）个字节的空间。



//4

int main(){
	unsigned char puc[4];//4个字节
	struct tagPIM{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;//2个字节

	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}