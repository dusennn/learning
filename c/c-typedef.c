#include <stdio.h>
#include <string.h>

#define True 1
#define False 0

typedef int myint;
typedef char mychar;

typedef struct Book{
	char number[10];
	char name[32];
	float price;
} Book;


void test(){
	myint a = 10;
	mychar c[20] = "Hello world!";

	printf("%d\n", a);
	printf("%s\n", c);
}

void test2(){
	Book book;
	book.price = 100.01;
	strcat(book.name, "我是一本书");
	printf("%s\n", book.name);
	printf("%f\n", book.price);
}

void test3(){
	printf("True: %d\n", True);
	printf("False: %d\n", False);
}

int main(){
	// test2();
	test3();

	return 0;
}