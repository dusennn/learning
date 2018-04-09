#include <stdio.h>

void test(){
	int *point;
	int var = 10;

	point = &var;

	printf("%p\n", point);
	printf("%p\n", &point);
	printf("%d\n", *point);

	printf("%s\n", "-------------------------------------------");

	point += 1;
	printf("%p\n", point);
	printf("%p\n", &point);
	printf("%d\n", *point);

}

void test2(){
	unsigned char c = 1;
	unsigned char *point = &c;
	unsigned char **point2 = &point;

	printf("%p\n", &c);
	printf("%p\n", &point);
	printf("%d\n", *point);
	printf("%p\n", &point2);
	printf("%d\n", **point2);
}

void test3(){
	unsigned int n = 257;
	unsigned int *point = &n;
	unsigned char *c = (unsigned char*)&n;

	printf("%d\n", n);
	printf("%p\n", &point);
	printf("%p\n", &c);
	printf("%d\n", *c);
	printf("%s\n", c);
}

void test4(){
	int arr[5] = {1, 2, 3, 4, 5};

	int i, *p;

	p = arr;

	printf("%p\n", arr);
	printf("%p\n", &p);

	for(i = 0; i < 5; ++i){
		printf("%d\n", *p);
		printf("%p\n", p);

		p++;		
	}
}

void test5(){
	int arr[5] = {1, 2, 3, 4, 5};

	int i, *p;

	// init
	p = &arr[4];

	while(p >= &arr[0]){
		printf("%p\n", p);
		printf("%d\n", *p);

		p --;
	}

}

int main(){
	// test();
	// test2();
	// test3();
	// test4();
	test5();

	return 0;
}