#include <stdio.h>

void main(){
	float num, result;

	printf("请输入摄氏温度(36.7):\n");
	scanf("%f", &num);
	printf("正在为您转换为华氏温度,请稍等...\n\n\n");
	result = (5.0 / 9.0) * (num - 32);
	printf("%.2f\t=>\t%.2f\n", num, result);
}
