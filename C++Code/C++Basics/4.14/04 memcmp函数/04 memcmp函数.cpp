#include<stdio.h>
#include<string.h>
#include<assert.h>

#define BUFFER_SIZE 256
void main01(){
	char *str1 = "Hello";
	char *str2 = "Hello";
	int ar1[] = { 1, 2, 3, 4, 50, 6, 7, 8 };
	int ar2[] = { 1, 2, 3, 4, 6, 8, 9, 0 };
	int res = strcmp(str1, str2);  //string
	printf("%d\n", res);
	int res1 = memcmp(str1, str2, 5);
	printf("%d\n", res1);
	//int res2 = strcmp(ar1, ar2);
	int res2 = memcmp(ar1, ar2, sizeof(int) * 8);
	printf("%d\n", res2);
}

void main02(){
	int ar1[] = { 1, 2, 3, 4, 50, 6, 7, 8 };
	int ar2[] = { 1, 2, 3, 4, 6, 8, 9, 0 };
	int res2 = memcmp(ar1, ar2, sizeof(int) * 5);
	printf("res = %d\n", res2);
}

//模拟实现memcmp函数
int my_memcmp(const void *buf1, const void *buf2, size_t count){
	assert(buf1 != NULL && buf2 != NULL);
	const char *pbuf1 = (char*)buf1;
	const char *pbuf2 = (char*)buf2;
	int res = 0;
	while (count-- != 0){
		if ((res = *pbuf1 - *pbuf2) != 0)
			break;
		pbuf1++;
		pbuf2++;
	}
	if (res > 0)
		res = 1;
	else if (res < 0)
		res = -1;
	return res;
}
int myMemcmp(const int* ar1, const int* ar2, int count){
	assert(ar1 != NULL&& ar2 != NULL);
	int res = 0;
	while (count-- != 0){
		if ((res = *ar1 - *ar2) != 0){
			break;
		}
		ar1++;
		ar2++;
	}
	if (res>0){
		res = 1;
	}
	else{
		res = -1;
	}
	return res;
}

void main(){
	int ar1[] = { 1, 2, 3, 4, 80, 6, 7, 8 };
	int ar2[] = { 1, 2, 3, 4, 60, 8, 9, 0 };
	int res2 = my_memcmp(ar1, ar2, sizeof(int) * 5);
	printf("res2 = %d\n", res2);
	int res3 = myMemcmp(ar1, ar2, sizeof(int) * 5);
	printf("res3 = %d\n", res3);
}