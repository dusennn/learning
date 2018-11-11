#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW 0
#define MAX_SIZE 20

typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType data;
}Node;
typedef struct{
	Node n[MAX_SIZE];
	int len;
}SqList;

Status init(SqList *l){
	//int data[8] = {12, 2, 3, 34, 23, 6, 4, 9};
	int data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	l->len = 8;
	for(int i=0; i<l->len; i++){
		l->n[i].data = data[i];
	}
	return OK;
}

void print(SqList l){
	printf("========== LIST: ==========\n");
	for(int i=0; i<l.len; i++){
		printf("%d  ", l.n[i].data);
	}
	printf("\n");
}

//bubble sort 1
Status bubble_1(SqList *l){
	printf("========== BUBBLE: ==========\n");
	int c1=0, c2=0;

	for(int i=0; i<l->len; i++){
		for(int j=i; j<l->len; j++){
			c1++;
			if(l->n[i].data > l->n[j].data){
				c2++;
				ElemType temp;
				temp = l->n[i].data;
				l->n[i].data = l->n[j].data;
				l->n[j].data = temp;
			}
		}
	}

	printf("Bubble_1: %d次比较，%d次移动.\n", c1, c2);

	return OK;
}

//bubble sort 2 (正版)
Status bubble_2(SqList *l){
	printf("========== BUBBLE: ==========\n");
	int c1=0, c2=0;

	for(int i=0; i<l->len; i++){
		for(int j=l->len-1; j>i; j--){
			c1++;
			if(l->n[j].data < l->n[j-1].data){
				c2++;
				ElemType temp;
				temp = l->n[j].data;
				l->n[j].data = l->n[j-1].data;
				l->n[j-1].data = temp;
			}
		}
	}

	printf("Bubble_2: %d次比较，%d次移动.\n", c1, c2);
	return OK;
}

//bubble sort3 (正版加强)
Status bubble_3(SqList *l){
	printf("========== BUBBLE: ==========\n");
	int c1=0, c2=0, flag = TRUE;

	for(int i=0; i<l->len && flag; i++){
		flag = FALSE;
		for(int j=l->len-1; j>i; j--){
			c1++;
			if(l->n[j].data < l->n[j-1].data){
				c2++;
				ElemType temp;
				temp = l->n[j].data;
				l->n[j].data = l->n[j-1].data;
				l->n[j-1].data = temp;
				flag = TRUE;
			}
		}
	}

	printf("Bubble_3: %d次比较，%d次移动.\n", c1, c2);
	return OK;
}

int main(){
	SqList l;
	init(&l);
	print(l);
	
	bubble_1(&l);
	print(l);
	
	init(&l);
	bubble_2(&l);
	print(l);

	init(&l);
	bubble_3(&l);
	print(l);

	return 0;
}
