#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


void* my_realloc(void *memblock, size_t size){
	//1 申请一个更大的空间
	void *new_memblock = malloc(size);
	if (new_memblock == NULL)
		return NULL;
	//2 把原来的数据进行拷贝
	memcpy(new_memblock, memblock, size);
	//3 释放原有空间
	free(memblock);

	//4 返回新的空间地址
	return new_memblock;
}


void main(){
	int *ptr1 = (int *)malloc(sizeof(int) * 5);
	assert(ptr1 != NULL);
	for (int i = 0; i<5; ++i)  
		ptr1[i] = i + 1;
	//很容易出错
	int *tmp = (int*)my_realloc(ptr1, sizeof(int) * 10);
	if (tmp != NULL){
		ptr1 = tmp;
	}
	else{
		free(ptr1);
		return;
	}
	for (int i = 5; i<10; ++i)  //1 2 3 4 5
		ptr1[i] = i + 1;
	for (int i = 0; i<10; ++i)
		printf("%d ", ptr1[i]);
	printf("\n");
}