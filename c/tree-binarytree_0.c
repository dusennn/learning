#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Boolean;
typedef int Status;
typedef char ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree initTree(){
    BiTNode *t = (BiTNode *)malloc(sizeof(BiTNode));
    if(!t) exit(0);

    t->lchild = t->rchild = NULL;
    
    return t;
}

Status createTree(BiTree t){
    t->data = 'A';
    BiTNode *lchild, *rchild;
    lchild = (BiTNode *)malloc(sizeof(BiTNode));
    if(!lchild) exit(0);

    lchild->data = 'B';
    BiTNode *lchild2, *rchild2;
    lchild2 = (BiTNode *)malloc(sizeof(BiTNode));
    lchild2->data = 'D';
    rchild2 = (BiTNode *)malloc(sizeof(BiTNode));
    rchild2->data = 'E';
    lchild->lchild = lchild2;
    lchild->rchild = rchild2;
    t->lchild = lchild;

    rchild = (BiTNode *)malloc(sizeof(BiTNode));
    if(!rchild) exit(0);

    rchild->data = 'C';
    rchild->lchild = rchild->rchild = NULL;
    t->rchild = rchild;

    return OK;
}

//先序遍历
Status prePrint(BiTree t){
    if(t){
        printf("%c ", t->data);
        prePrint(t->lchild);
        prePrint(t->rchild);
        if(!t->lchild && !t->rchild) return OK;
    }
}

//中序遍历
Status midPrint(BiTree t){
    if(t){
        if(t->lchild){
            midPrint(t->lchild);
        }
        printf("%c ", t->data);
        if(t->rchild){
            midPrint(t->rchild);
        }
        if(!t->lchild && !t->rchild) return OK;
    }
}

//后序遍历
Status subPrint(BiTree t){
    if(t){
        if(t->lchild){
            subPrint(t->lchild);
            if(t->rchild){
                subPrint(t->rchild);
            }
        }
        printf("%c ", t->data);
        if(!t->lchild && !t->rchild) return OK;
    }
}

// count high
int high(BiTree tree){
	if(tree){
		int lhigh, rhigh;
		lhigh = high(tree->lchild) + 1;
		rhigh = high(tree->rchild) + 1;
		return lhigh > rhigh ? lhigh:rhigh; 
	}
}

void convert(BiTree *t, char arr[], int index, int len){
	if(index < len){
		(*t) = (BiTNode *)malloc(sizeof(BiTNode));
		(*t)->data = arr[index];
		convert(&((*t)->lchild), arr, 2 * index + 1, len);
		convert(&((*t)->rchild), arr ,2 * index + 2, len);
	}
}

//顺序存储 to 链式存储
Status conversion(BiTree *t, char arr[], int len){
	convert(t ,arr, 0, len);	
	return OK;
}

//计算树的高度
int layer(BiTree t){
	int i, j;
	if(t){
		i = layer(t->rchild) + 1;
		j = layer(t->lchild) + 1;
		return i > j ? i : j;
	}
	return 0;
}

int main(){
    BiTree t = initTree();
    createTree(t);
    printf("先序遍历: \n");
    prePrint(t);
    printf("\n");

    printf("中序遍历: \n");
    midPrint(t);
    printf("\n");
    
    printf("后序遍历: \n");
    subPrint(t);
    printf("\n");

	printf("Tree High: %d \n", high(t));
	
	printf("conversion:\n");
	BiTree t2 = NULL;
	char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	conversion(&t2, arr, 6);
	midPrint(t2);
	printf("\n");

	printf("layer:\n");
	int l = layer(t);
	printf("%d\n", l);
}
