#include <stdio.h>
#include <string.h>

void test(){
	char str[] = "Hello!";
	int len = strlen(str);

	printf("%s\n", str);
	printf("%d\n", len);
}

void test2(){
	char str[5] = "H";
	int len = strlen(str);

	printf("%s\n", str);
	printf("%d\n", len);
}

void test3(){
	char str1[12] = "Hello";
	char str2[12] = "World!";
	char str3[12];

	printf("%s\n", strlwr(str1));
}

int main(){
	// test2();
	test3();

	return 0;
}