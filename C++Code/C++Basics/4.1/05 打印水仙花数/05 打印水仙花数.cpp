/*
打印水仙花数
求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。
*/


#include <stdio.h>
int main(){
	int i, j, k, l, g, count = 0;    
	printf("找到的水仙花数有：\n");    
	for (i = 0; i <= 9; i++){
		for (j = 0; j <= 9; j++){
			for (k = 0; k <= 9; k++){
				for (l = 0; l <= 9; l++){
					for (g = 0; g <= 9; g++){
						if (i * 10000 + j * 1000 + k * 100 + l * 10 + g == i*i*i*i*i + j*j*j*j + k*k*k + l*l + g){
							printf("%d ", i * 10000 + j * 1000 + k * 100 + l * 10 + g);    
							count++;    
							if (count % 5 == 0){
								printf("\n");
							}
						}
					}
				}
			}
		}
	}
	printf("\n共有%d个水仙花数\n", count);
	return 0;
}