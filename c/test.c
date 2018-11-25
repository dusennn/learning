#include <stdio.h>

void fun(int a, int b, int c, int d){
	static int data[100];
	int i;
	if(d==b){
		printf("%d=", b);
		for(i=0; i<a; i++){
			if(i) printf("+");
			printf("%d", data[i]);
		}
		printf("\n");
	}
	for(i=c; i<=b; i++){
		if(i+d>b) break;
		data[a] = i;
		fun(a+1, b, i, d+i);
	}
}

void bubble_sort(int *list, int len){
	int i, j, flag, temp;
	for(i=0; i<len; i++){
		flag = 0;
		for(j=len-1; j>i; j--){
			if(list[j-1] > list[j]){
				temp = list[j-1];
				list[j-1] = list[j];
				list[j] = temp;
				flag = 1;
			}
		}
		if(flag == 0){
			return ;
		}
	}
}

void bubble_sort2(int *list, int len){
	int i, j, flag=1, temp;
	for(i=0; flag; i++){
		flag = 0;
		for(j=len-1; j>i; j--){
			if(list[j-1] > list[j]){
				temp = list[j-1];
				list[j-1] = list[j];
				list[j] = temp;
				flag = 1;
			}
		}
	}
}

void print(int list[], int len){
	for(int i=0; i<len; i++){
		printf("%d\t", list[i]);
	}
	printf("\n");
}

int main(){

//	for(int i=0; i<10; i++){
//		printf("%d\n", i);	
//	}
	int n=3;
	fun(0, n, 1, 0);

	int list[] = {3, 7, 2, 1, 8};
	print(list, 5);
	//bubble_sort(list, 5);
	bubble_sort2(list, 5);
	print(list, 5);

	return 0;
}
