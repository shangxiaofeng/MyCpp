#include<stdio.h>
/*
假设：用户名就是a：
密码：123456
*/
int main(){
	char name[32];
	char password[16];
	
	printf("请输入用户账号:");
	//fgets// 第一个参数：地址，第二个是大小，第三个是从哪里输入，题目是键盘输入
	fgets(name,sizeof(name),stdin);//scanf("%s",name)数组名本身是一个地址，不需要加&
	printf("请输入密码：");
	fgets(password,,sizeof(password),stdin);//gets函数读取一行 可能会越界，不是很安全
	//以下是测试信息
	printf("账号是:%s \n",name);
	printf(" 密码是:%s\n,password");
	//判断账号和密码是否正确。。。
	
	printf("---交换机后台管理---\n");
	printf("1、登录\n");
	printf("2、创建账号\n");
	printf("3、删除账号\n");
	printf("4、退出\n");
	
	return 0;
}