#include <stdio.h>

/*
	题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
*/

int main(){
	int x, y, z;

	int count = 0;
	
	for(x = 1; x < 5; x ++){
		for(y = 1; y < 5; y ++){
			for(z = 1; z < 5; z ++){
				if(x != y && x != z && y != z){
					printf("%d%d%d \n", x, y, z);
					count += 1;
				}
			}
		}
	}

	printf("能组成 %d 个互相不重复的三位数！\n", count);
}