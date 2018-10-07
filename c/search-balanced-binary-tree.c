#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0

typedef int Status;
typedef int ElemType;

typedef struct TNode{
	ElemType data;
	int bf; // balanced factor
	struct TNode *lchild, *rchild;
}TNode, *BanTree;

Status init(BanTree *bt){
	(*bt) = (TNode *)malloc(sizeof(TNode));
	if(!(*bt)) exit(OVERFLOW);

	(*bt)->lchild = (*bt)->rchild = NULL;
	return OK;
}

Status insert(BanTree bt, ElemType data){
	if(bt && !bt->data){
		bt->data = data;
		bt->bf = 0;
		return OK;
	}

	if(bt->data == data){
		return OK;
	}else if(bt->data > data){
		if(!bt->lchild){
			TNode *node = (TNode *)malloc(sizeof(TNode));
			node->data = data;
			node->bf = 0;
			node->lchild = node->rchild = NULL;
			bt->lchild = node;
			return OK;
		}else{
			insert(bt->lchild, data);
		}
	}else if(bt->data < data){
		if(!bt->rchild){
			TNode *node = (TNode *)malloc(sizeof(TNode));
			node->data = data;
			node->bf = 0;
			node->lchild = node->rchild = NULL;
			bt->rchild = node;
			return OK;
		}else{
			insert(bt->rchild, data);
		}
	}
}

Status create(BanTree bt){
	int len = 5;
	int data[6] = {len, 13, 24, 37, 90, 53};
	for(int i=1; i<=len; i++){
		insert(bt, data[i]);
	}
	return OK;
}

Status midTraversal(BanTree bt){
	if(bt){
		midTraversal(bt->lchild);
		printf("%d->", bt->data);
		midTraversal(bt->rchild);
	}
	return OK;
}

void print(BanTree bt){
	printf("========== MID ==========\n");
	midTraversal(bt);
	printf("\n");
}

int main(){
	BanTree bt;
	init(&bt);
	create(bt);
	print(bt);

	return 0;
}
