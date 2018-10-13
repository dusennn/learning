#include <stdio.h>

#define ERROR -1
#define OK 1
#define MAX_SIZE 10

typedef int Status;

//递归实现
Status merge_1(int list[], int len){
	if(len > 1){
		// 递归方式切成小块
		int *list1 = list;
		int list1_size = len / 2;
		int *list2 = list + (len / 2);
		int list2_size = len - (len / 2);

		merge_1(list1, list1_size);
		merge_1(list2, list2_size);

		//比较每个小块
		int i, j, k;
		int temp[MAX_SIZE];
		i = j = k = 0;
		while(i < list1_size && j < list2_size){
			if(list1[i] < list2[j]){
				temp[k++] = list1[i++];
			}else{
				temp[k++] = list2[j++];
			}
		}
		while(i < list1_size){
			temp[k++] = list1[i++];
		}
		while(j < list2_size){
			temp[k++] = list2[j++];
		}

		//排序后的数据放入list
		for(int m=0; m<(list1_size + list2_size); m++){
			list[m] = temp[m]; 
		}
	}

	return OK;
}

//迭代排序
Status merge_2(int list[], int len){
	int i, j, temp;
	
	for(i=0; i<len; i+=2){
		for(j=0; j<len; j+=2){
			if(list[j+1] < list[j]){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
				//UNDO
			}
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
	int len=10, list[10] = {20, 1, 3, 34, 5, 2, 8, 20, 14, 90};
	print(list, len);
	//merge_1(list, len);
	//print(list, len);

	merge_2(list, len);
	print(list, len);

	return 0;
}
