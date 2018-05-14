#include <stdio.h>

/*
	题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
*/

int main(){
	int x, y, z;

	int total = 0;

	for(x = 1; x <= 4; x ++){
		for(y = 1; y <= 4; y ++){
			for(z = 1; z <= 4; z ++){
				if(x != y && x != z && y != z){
					total += 1;
					printf("%d%d%d\n", x, y, z);
				}
			}
		}
	}

	printf("共能组成 %d \n", total);

	return 0;
}