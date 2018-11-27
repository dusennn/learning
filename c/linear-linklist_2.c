#include <stdio.h>
#include <stdlib.h>

/*
	北京工业大学 考研2015-5.2
*/

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//n 为数组的大小
void CreateLinkList(int A[], int n, LinkList *L){
	for(int i=0; i<n; i++){
		LNode *node = (LNode *)malloc(sizeof(LNode));
		node->data = A[i];

		if(A[i] < (*L)->data){
			node->next = (*L);
			(*L) = node;
		}else{
			LNode *target = (*L);
			while(target->next && target->next->data < A[i]){
				target = target->next;
			}
			node->next = target->next;
			target->next = node;
		}
	}

}

void print(LinkList L){
	LNode *target = L;
	while(target){
		printf("%d\t", target->data);
		target = target->next;
	}
	printf("\n");
}

int main(){
	LinkList L = (LNode*)malloc(sizeof(LNode));

	int A[] = {12, 2, 4, 6, 34, 32, 56, 33};
	CreateLinkList(A, 8, &L);
	
	print(L);
}
