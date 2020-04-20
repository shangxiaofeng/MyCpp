/*打印整数二进制的奇数位和偶数位
获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
*/
#include<stdio.h>
void printNum(int num){
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main(){
	int m;
	printf("请输入一个整数：");
	scanf_s("%d", &m);
	printNum(m);
}