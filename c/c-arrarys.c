#include <stdio.h>

int t[4];

int main(){
	int temp[6];
	int temp1[5];
	int temp2[4] = {1,2,3,12};
	// int temp[] = {12,1,3,12,32,413};

	for(int i = 0; i < 5; ++i){
		temp1[0] = 23;
		temp1[1] = 23423;
		temp1[2] = 2341;
		temp1[3] = 231324;
		temp1[4] = 232413;

	}
	// for (int i = 0;i < 5; ++i)
	// {
	// 	/* code */
	// 	printf("Temp1[%d] = [%d]\n", i, temp1[i]);
	// }

	// 局部未初始化的数组竟然是随机值，脏值
	printf("Temp[0] = [%d]\n", temp[0]);
	printf("Temp[1] = [%d]\n", temp[1]);
	printf("Temp[2] = [%d]\n", temp[2]);
	printf("Temp[3] = [%d]\n", temp[3]);

	// 全局未初始化的数组，值为0
	printf("T[0] = [%d]\n", t[1]);
}	