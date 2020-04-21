#include "Contact.h"

//初始化通讯录
void InitContact(Contact* pcon){
	assert(pcon != NULL);
	pcon->count = 0;
	memset(pcon, 0, sizeof(pcon->data));
}

//添加联系人
void AddContact(Contact* pcon){
	assert(pcon!= NULL);
	//录入联系人的信息
	printf("请输入姓名:>");
	scanf("%s", &pcon->data[pcon->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pcon->data[pcon->count].age));
	printf("请输入性别:>");
	scanf("%s", pcon->data[pcon->count].sex);
	printf("请输入电话:>");
	scanf("%s", pcon->data[pcon->count].tel);
	printf("请输入地址:>");
	scanf("%s", pcon->data[pcon->count].addr);
	pcon->count++;
	printf("联系人信息录入成功！\n");
}

//在已经录入的联系人中，查找指定目标
static int FindByName(Contact* pcon, char name[]){
	assert(pcon != NULL);
	for (int i = 0; i < pcon->count; ++i){
		if (strcmp(pcon->data[i].name, name) == 0){
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelContact(Contact* pcon){
	assert(pcon);
	char name[MAX_NAME_SIZE];
	if (pcon->count == 0){
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入您要删除的姓名：>");
	scanf("%s", name);
	//删除之前需要查找该姓名是否存在
	int pos = FindByName(pcon, name);
	if (pos == -1){
		printf("您需要删除的联系人不存在！\n");
	}
	for (int i = 0; i < pcon->count; ++i){
		pcon->data[i] = pcon->data[i + 1];
		printf("删除成功\n");
	}
}

void FindContact(Contact* pcon){
	assert(pcon);
	char name[MAX_NAME_SIZE];
	int pos = FindByName(pcon, name);
	if (pcon->count == 0){
		printf("联系人为空！\n");
		return;
	}
	printf("请输入您要查找的姓名：>");
	scanf("%s", name);
	if (pos == -1){
		printf("您查找的联系人不存在！\n");
	}
	printf("%15s\t%5d\t%5s\t%12s\t%20s\n", pcon->data[pos].name,
		pcon->data[pos].age,
		pcon->data[pos].sex,
		pcon->data[pos].tel,
		pcon->data[pos].addr);
}



void ModifyContact(Contact* pcon){
	int i = 0;
	char name[MAX_NAME_SIZE] = { 0 };
	int pos = 0;
	assert(pcon);

	if (pcon->count == 0) //空的就不用找
	{
		printf("通讯录已空，无法修改信息\n");
		return;
	}
	//修改
	printf("请输入要修改条目的姓名:>");
	scanf("%s", name);
	//查找（修改之前需要先查找）
	pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要修改的条目不存在\n");
		return;
	}
	//询问要改什么
	printf("请输入要修改什么信息（1-名字，2-年龄，3-性别，4-电话，5-住址）:>");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入新的姓名:>");
		scanf("%s", pcon->data[pos].name);
		break;
	case 2:
		printf("请输入新的年龄:>");
		scanf("%d", &pcon->data[pos].age);
		break;
	case 3:
		printf("请输入新的性别:>");
		scanf("%s", pcon->data[pos].sex);
		break;
	case 4:
		printf("请输入新的电话:>");
		scanf("%s", pcon->data[pos].tel);
		break;
	case 5:
		printf("请输入新的地址:>");
		scanf("%s", pcon->data[pos].addr);
		break;
	default:
		printf("输入有误，修改失败\n");
		return;
	}
	printf("修改成功\n");
}
void ShowContact(const Contact* pcon){
	assert(pcon != NULL);
	printf("**************************************************\n");
	printf("*%-10s%-8s%-8s%-12s%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i<pcon->count; ++i)
	{
		printf("*%-10s%-8s%-8d%-12s%-30s\n", pcon->data[i].name,
			pcon->data[i].sex,
			pcon->data[i].age,
			pcon->data[i].tel,
			pcon->data[i].addr);
	}
	printf("**************************************************\n");
}

void ClearContact(Contact* pcon){
	InitContact(pcon);
}
void SortContact(Contact* pcon){
	int i, j;
	PerInfo tmp;
	for (i = 0; i < pcon->count - 1; i++)
	{
		for (j = 0; j < pcon->count - 1 - i; j++)
		{
			if (0 < strcmp(pcon->data[j].name, pcon->data[j + 1].name))
			{
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
	}
}

