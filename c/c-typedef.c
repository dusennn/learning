#include <stdio.h>
#include <string.h>

typedef int myint;
typedef char mychar;

int main(){
	myint a = 10;
	mychar c[20] = "Hello world!";

	printf("%d\n", a);
	printf("%s\n", c);

	return 0;
}