#include <stdio.h>

int main(){
	int num;
	char c[4];

	// printf("%p\n", &num);
	// printf("%p\n", &c);

	int *point;
	int var = 10;

	point = &var;

	printf("%p\n", point);
	printf("%p\n", &point);
	printf("%d\n", *point);
}