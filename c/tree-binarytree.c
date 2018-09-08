#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -1
#define OK 1

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
    if(!t) return ERROR;
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
    return 0;
}
