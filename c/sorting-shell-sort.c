#include <stdio.h>

#define ERROR -1
#define OK 1

typedef int Status;

Status shell(int list[], int len){
	int i, j, temp, gap=len;
	
	//使序列基本有序
	do{
		gap = gap / 3 + 1; 
		for(i=gap; i<len; i++){
			if(list[i] < list[i-gap]){
				temp = list[i];
				list[i] = list[i-gap];
				list[i-gap] = temp;
			}
		}
	}while(gap > 1);

	//调用直接插入排序，完成最后一步
	for(i=1; i<len; i++){
		if(list[i] < list[i-1]){
			temp = list[i];
			for(j=i-1; temp < list[j]; j--) list[j+1] = list[j];
			list[j+1] = temp;
		}
	}

	return OK;
}

void print(int list[], int len){
	printf("========== LIST: ==========\n");
	for(int i=0; i<len; i++){
		printf("%d  ", list[i]);
	}
	printf("\n\n");
}

int main(){
	int len=10, list[10] = {12, 1, 3, 34, 5, 2, 8, 20, 14, 90};
	print(list, len);
	shell(list, len);
	print(list, len);

	return 0;
}
