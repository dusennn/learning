#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define TRUE 1
#define FALSE 0
#define LH 1 //左高 
#define EH 0 //等高
#define RH -1 //右高

typedef int Status;
typedef int ElemType;

typedef struct TNode{
	ElemType data;
	int bf; // balanced factor
	struct TNode *lchild, *rchild;
}TNode, *BanTree;

void R_Rotate(BanTree *bt){
	TNode *lchild = (*bt)->lchild;
	(*bt)->lchild = lchild->rchild;
	lchild->rchild = (*bt);
	(*bt) = lchild;
}

void L_Rotate(BanTree *bt){
	TNode *rchild = (*bt)->rchild;
	(*bt)->rchild = rchild->lchild;
	rchild->lchild = (*bt);
	(*bt) = rchild;
}

void leftBalanced(BanTree *bt){
	TNode *lchild, *lrchild;
	lchild = (*bt)->lchild;
	lrchild = NULL;
	switch(lchild->bf){
		case LH:
			(*bt)->bf = lchild->bf = EH;
			R_Rotate(bt);
			break;
		case RH:
			lrchild = lchild->rchild;
			switch(lrchild->bf){
				case LH:
					(*bt)->bf = RH;
					lchild->bf = EH;
					break;
				case EH:
					(*bt)->bf = lchild->bf = EH;
					break;
				case RH:
					(*bt)->bf = EH;
					lchild->bf = LH;
					break;
			}//switch(lrchild->bf)
			lrchild->bf = EH;
			L_Rotate(&(*bt)->lchild);
			R_Rotate(bt);
			break;
	}//switch(lchild->bf)
}//leftBalanced

void rightBalanced(BanTree *bt){
	TNode *rchild, *rlchild;
	rchild = (*bt)->rchild;
	rlchild = NULL;
	switch(rchild->bf){
		case LH:
			rlchild = rchild->lchild;
			switch(rlchild->bf){
				case LH:
					(*bt)->bf = LH;
					rchild->bf = EH;
					break;
				case EH:
					(*bt)->bf = rchild->bf = EH;
					break;
				case RH:
					(*bt)->bf = EH;
					rchild->bf = LH;
					break;
			}//switch(rlchild->bf)
			rlchild->bf = EH;
			R_Rotate(&(*bt)->rchild);
			L_Rotate(bt);
			break;
		case RH:
			(*bt)->bf = rchild->bf = EH;
			L_Rotate(bt);
			break;
	}//switch(rchild->bf)
}//rightBalanced

Status insert(BanTree *bt, int *taller, ElemType e){
	if(!(*bt)){
		(*bt) = (TNode *)malloc(sizeof(TNode));
		(*bt)->data = e;
		(*bt)->lchild = (*bt)->rchild = NULL;
		(*bt)->bf = EH;
		*taller = TRUE;
		return OK;
	}

	if(e == (*bt)->data){
		*taller = FALSE;
		return FALSE;
	}
	if(e < (*bt)->data){
		//数没有长高，无需下一步
		if(!insert(&(*bt)->lchild, taller, e)) return FALSE;
		
		switch((*bt)->bf){
			case LH:
				leftBalanced(bt); //左平衡处理
				*taller = FALSE;
				break;
			case EH:
				(*bt)->bf = LH;
				*taller = TRUE;
				break;
			case RH:
				(*bt)->bf = EH;
				*taller = FALSE;
				break;
		}//switch((*bt)->bf)
	}else{
		if(!insert(&(*bt)->rchild, taller, e)) return FALSE;

		switch((*bt)->bf){
			case LH:
				(*bt)->bf = EH;
				*taller = FALSE;
				break;
			case EH:
				(*bt)->bf = RH;
				*taller = TRUE;
				break;
			case RH:
				rightBalanced(bt);
				*taller = FALSE;
				break;
		}//switch((*bt)->bf)

	}//else
}

Status create(BanTree *bt, int *taller){
	int len = 5;
	int data[6] = {len, 13, 24, 37, 90, 53};
	for(int i=1; i<=len; i++){
		insert(bt, taller, data[i]);
	}
	return OK;
}

Status midTraversal(BanTree bt){
	if(bt){
		midTraversal(bt->lchild);
		printf("%d(%d)->", bt->data, bt->bf);
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
	BanTree bt = NULL;
	int *taller;
	create(&bt, taller);
	print(bt);

	return 0;
}
