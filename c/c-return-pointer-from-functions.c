#include <stdio.h>
#include <stdlib.h>

int * getRandomArrs(){
	static int arr[5];

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		arr[i] = rand();
	}

	return arr;
}

int main(){
	int *arr = getRandomArrs();

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		printf("%d\n", arr[i]);
	}
}