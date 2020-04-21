
#ifndef CONTACT_H_
#define CONTACT_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>



#define MAX_NAME_SIZE 20
#define MAX_ADDRESS_SIZE 128
#define MAX_TEL_SIZE 12
#define MAX 1000

typedef enum{
	EXIT,
	ADD,
	DEL,
	FIND,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
}OPER_ENUM;;

typedef struct PerInfo{
	char name[MAX_NAME_SIZE];
	char sex[3];
	short age;
	char tel[MAX_TEL_SIZE];
	char addr[MAX_ADDRESS_SIZE];
}PerInfo;

typedef struct Contact{
	PerInfo data[MAX];//存放真实数据的空间
	int count;//记录有效数据的个数
}Contact;

void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void DelContact(Contact* pcon);
void FindContact(Contact* pcon);
void ModifyContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void ClearContact(Contact* pcon);
void SortContact(Contact* pcon);

#endif /* _CONTACT_H_ */