#include <stdio.h>

void fn(void)
{
	int n = 10;

	printf("n=%d\n", n);
	n++;
	printf("n++=%d\n", n);
}

void fn_static(void)
{
	static int n = 10;

	printf("static n=%d\n", n);
	n++;
	printf("n++=%d\n", n);
}

int main(void)
{
	fn();
	printf("--------------------\n");
	fn_static();
	printf("--------------------\n");
	fn();
	printf("--------------------\n");
	fn_static();

	return 0;
}
