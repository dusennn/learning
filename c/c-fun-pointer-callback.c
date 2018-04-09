#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

void test(){
	int a, b, c;

	printf("%s\n", "请输入三个数字：");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	printf("MAX: %d\n", max(max(a, b), c));
}

void test2(){
	int a, b, c;
	int(*p)(int, int) = max;

	printf("%s\n", "请输入三个数字：");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	printf("MAX: %d\n", p(p(a, b), c));
}

int main(){
	test2();

	return 0;
}