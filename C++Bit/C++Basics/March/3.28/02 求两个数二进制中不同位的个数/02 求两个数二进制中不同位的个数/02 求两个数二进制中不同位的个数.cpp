
#include <stdio.h>
int different(int m, int n){
	int tmp = m^n;
	int count = 0;
	while (tmp){
		
		tmp = tmp&(tmp - 1);//这一步骤，为什么这么做？不理解，帮忙解答一下。
		count++;
	}
	return count;
}

int main(){
	int m, n;
	printf("请输入两个数m n：");
	scanf_s("%d %d", &m, &n);
	printf("%d\n", different(m, n));
	return 0;
}
