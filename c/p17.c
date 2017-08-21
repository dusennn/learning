#include <stdio.h>

int sum(int x, int b){
	return x + b;
}

void main(){
	int a , b;
	printf("请输入两个数字: \n");
	scanf("%d, %d", &a, &b);
	printf("sum: %d", sum(a, b));
}
