#include <stdio.h>

void test(){
	int num = 300;
	int *p = &num;
	int **pp = &p;

	printf("%d\n", num);
	printf("%p\n", &num);

	printf("%d\n", *p);
	printf("%p\n", &p);
	
	printf("%d\n", **pp);
	printf("%p\n", &pp);
}

int main(){
	test();

	return 0;
}
