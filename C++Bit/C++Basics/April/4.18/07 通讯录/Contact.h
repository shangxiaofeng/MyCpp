/*
实现一个通讯录；
通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
提供方法：
添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人
*/


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
​
enum Option{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
};
​
#define DEFAULT_SZ 3
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 25
​
//人的信息
typedef struct PeoInfo{
	char name[NAME_MAX];
	short age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
} PeoInfo;
​
//通讯录结构体​
typedef struct Contact{
	PeoInfo data[MAX];//存放真实数据的空间
	int sz;//记录有效数据的个数
}Contact;
​
void InitContact(Contact* pcon);
void AddContact(Contact* pcon);
void DelContact(Contact* pcon);
void FindContact(Contact* pcon);
void ModifyContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void ClearContact(Contact* pcon);
void SortContact(Contact* pcon);