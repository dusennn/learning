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
	int data[8] = {12, 2, 3, 34, 23, 6, 4, 9};
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

//sample insert sort
Status insert(SqList *l){
	printf("========== INSERT ==========\n");
	int i, j, temp, c1=0, c2=0;
	
	for(i=1; i<l->len; i++){
		if(l->n[i].data < l->n[i-1].data){
			temp = l->n[i].data;
			c1++;
			for(j=i-1; l->n[j].data > temp; j--){
				c2++;
				l->n[j+1].data = l->n[j].data;
			}
			l->n[j+1].data = temp;
		}
	}

	printf("Insert: %d次比较，%d次移动.\n", c1, c2);
	return OK;
}

int main(){
	SqList l;
	init(&l);
	print(l);
	
	insert(&l);
	print(l);
	return 0;
}
