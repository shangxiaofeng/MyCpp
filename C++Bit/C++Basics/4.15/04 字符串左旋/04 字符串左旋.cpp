/*
实现一个函数，可以左旋字符串中的k个字符。例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/

#include<stdio.h>
#include<string.h>

void leftRound(char * ch, int time){
	int i, j;
	char temp;
	int len = strlen(ch);
	time %= len;
	for (i = 0; i < time; ++i){
		temp = ch[0];
		for (j = 0; j < len - 1; ++j){
			ch[j] = ch[j + 1];
		}
		ch[j] = temp;
	}
}


void leftRound02(char * src, int time){
	int len = strlen(src);
	int pos = time % len; //断开位置的下标
	char tmp[256] = { 0 }; //更准确的话可以选择malloc len + 1个字节的空间来做这个tmp
	strcpy(tmp, src + pos); //先将后面的全部拷过来
	strncat(tmp, src, pos); //然后将前面几个接上
	strcpy(src, tmp); //最后拷回去
}
int main(){
	char ch[32] = {"xiaofeng"};
	int k = 2;
	/*printf("请输入您要旋转的字符串和k个字符：");
	scanf_s("%s", ch);
	scanf_s("%d", &k);*/
	//leftRound(ch,k);
	leftRound02(ch, k);
	printf("%s\n", ch);
	return 0;
}