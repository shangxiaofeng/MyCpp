
#include<stdio.h>
#include<assert.h>
int main(){
	FILE * file = fopen("test.txt", "r");
	assert(file != NULL);
	char buf[128];
	char * p;
	//while (1){
	//	p = fgets(buf, sizeof(buf), file);//最多读取参数2 - 1个 stdin键盘输入
	//	if (!p){
	//		break;
	//	}
	//	printf("%s ", buf);
	//}
	while (fgets(buf, sizeof(buf), file)){
		printf("%s ", buf);
	}
	printf("\n");
	fclose(file);
	return 0;
}