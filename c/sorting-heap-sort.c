#include <stdio.h>

#define ERROR -1
#define OK 1

typedef int Status;

void heapAdjust(int list[], int i, int len){
	int	j, temp;

	temp = list[i];
	for(j=2*i; j<=len; j*=2){
		if(j<len && list[j] < list[j+1]) j++;

		if(temp >= list[j]) break;
		
		list[i] = list[j];
		i = j;
	}
	list[i] = temp;
}

Status heap(int list[], int len){
	int i, temp;

	//构建大顶堆
	for(i=len/2; i>0; i--){
		heapAdjust(list, i, len);
	}

	//堆顶元素放入列表尾部
	for(i=len; i>1; i--){
		temp = list[i];
		list[i] = list[1];
		list[1] = temp;

		//调整堆
		heapAdjust(list, 1, i-1);
	}

	return OK;
}

void print(int list[], int len){
	printf("========== LIST: ==========\n");
	for(int i=1; i<=len; i++){
		printf("%d  ", list[i]);
	}
	printf("\n\n");
}

int main(){
	int len=9, list[10] = {-1, 1, 3, 34, 5, 2, 8, 20, 14, 90};
	print(list, len);
	heap(list, len);
	print(list, len);

	return 0;
}
