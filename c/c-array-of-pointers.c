#include <stdio.h>

void test(){
	int num[5] = {1, 2, 3, 4, 5};
	int *arr[5];

	for(int i = 0; i < 5; i ++){
		arr[i] = &num[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		printf("Arr pointers: %p\n", &arr[i]);
		printf("Arr values: %d\n", *arr[i]);
	}

}

int main(){
	test();

	return 0;
}