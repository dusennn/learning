#include <stdio.h>

/*
	输入三个整数x,y,z，请把这三个数由小到大输出。
*/

int main(){
	int nums[3], temp;

	printf("请输入三个整数：\n");
	scanf("%d", &nums[0]);
	scanf("%d", &nums[1]);
	scanf("%d", &nums[2]);

	//print origin nums
	for(int i = 0; i < 3; i++){
		printf("%d\t", nums[i]);
	}
	printf("\n");

	//冒泡排序
	// for(int i = 0; i < 3; i++){
	// 	for(int j = 0; j < 3 - i; j++){
	// 		if(nums[j] > nums[j + 1]){
	// 			int temp = nums[j];
	// 			nums[j] = nums[j + 1];
	// 			nums[j + 1] = temp;
	// 		}
	// 	}
	// }


	//直接插入排序
	for(int i = 0; i < 3; i ++){
		temp = nums[i];
		for(int j = 0; j < i; j++){
			if(temp < nums[j]){
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}

	//print sorted nums
	for(int i = 0; i < 3; i++){
		printf("%d\t", nums[i]);
	}
	printf("\n");

	return 0;
}