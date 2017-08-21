#include <stdio.h>

int max(int a, int b); /*函数说明*/

void main() /*主函数*/
{
	int x, y, z; /*变量说明*/
	int max(int a, int b); /*函数说明*/
	printf("input two numbers:\n");
	scanf("%d%d", &x, &y); /*输入x, y值*/
	z=max(x,y); /*调用max函数*/
	printf("maxnum=%d", z); /*输出*/

}

int max(int a, int b) /*定义max函数*/
{
	if(a > b)return a ;else return b; /*把结果返回主调函数*/
}
