#include<Contact.h>

//初始化通讯录
void InitContact(Contact* pcon)
{
	assert(pcon);
	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));
}
​
//1、添加联系人信息
void AddContact(Contact* pcon)
{
	assert(pcon);

	//录入信息
	printf("请输入名字:>");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pcon->data[pcon->sz].age));
	printf("请输入性别:>");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pcon->data[pcon->sz].addr);
	​
		pcon->sz++;
	printf("增加成功\n");
}
​
//查找指定条目下标
static int FindByName(Contact* pcon, char name[])
{
	int i = 0;
	assert(pcon);
	for (i = 0; i<pcon->sz; i++)
	{
		if (0 == strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
	//找不到
	return -1;
}
​
//2、删除指定联系人信息
void DelContact(Contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);

	if (pcon->sz == 0) //空的就不用删了
	{
		printf("通讯录已空，无法删除\n");
		return;
	}
	//删除
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找（删除之前需要先查找）
	pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要删除的条目不存在\n");
		return;
	}
	//移除
	for (i = pos; i<pcon->sz; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->sz--;
	printf("删除成功\n");
}
​
//3、查找指定联系人信息
void FindContact(Contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);

	if (pcon->sz == 0) //空的就不用删了
	{
		printf("通讯录已空，无法查找\n");
		return;
	}
	​
		//查找
		printf("请输入要查找人的名字:>");
	scanf("%s", name);
	​
		pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要查找的条目不存在\n");
		return;
	}

	printf("%15s\t%5d\t%5s\t%12s\t%20s\n",
		pcon->data[pos].name,
		pcon->data[pos].age,
		pcon->data[pos].sex,
		pcon->data[pos].tele,
		pcon->data[pos].addr);
}
​
//4、修改指定联系人信息
void ModifyContact(Contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);

	if (pcon->sz == 0) //空的就不用找
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
		scanf("%s", pcon->data[pos].tele);
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
​
//5、显示所有联系人信息
void ShowContact(const Contact* pcon)
{
	int i = 0;
	assert(pcon);
	printf("%15s\t%5s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i<pcon->sz; i++)
	{
		printf("%15s\t%5d\t%5s\t%12s\t%20s\n", pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}
​
//6、清空所有联系人信息
void ClearContact(Contact* pcon)
{
	InitContact(pcon);
}
​
//7、按照名字排序
void SortContact(Contact* pcon)
{
	int i, j;
	PeoInfo tmp;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		for (j = 0; j < pcon->sz - 1 - i; j++)
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