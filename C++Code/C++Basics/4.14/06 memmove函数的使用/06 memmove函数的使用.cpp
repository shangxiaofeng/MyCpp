#include<stdio.h>
#include<string.h>
#include<assert.h>

void main01(){
	char dest[20] = "xiaofeng";
	char src[] = "xuan";
	printf("dest = %s\n", dest);
	memmove(dest, src, 4);
	memmove(dest + 2, src, 4);
	//memcpy();
	printf("dest = %s\n", dest);
}

void *my_memmove(void *dest, const void *src, size_t count){
	assert(dest != NULL && src != NULL);
	char *pdest = (char*)dest;
	const char *psrc = (char*)src;
	//1 无覆盖
	if (psrc >= pdest || pdest >= psrc + count){
		while (count-- != 0){
			*pdest++ = *psrc++;
		}
	}
	//2 有覆盖
	else{
		pdest = pdest + count - 1;
		psrc = psrc + count - 1;
		while (count-- != 0){
			*pdest-- = *psrc--;
		}
	}
	return dest;
}

void main(){
	char dest[20] = "abcdefghijkl";
	printf("dest = %s\n", dest);
	memmove(dest+2, dest, 4); //内存覆盖的情形
	printf("dest = %s\n", dest);
}