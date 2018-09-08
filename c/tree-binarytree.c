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
    lchild->lchild = lchild->rchild = NULL;
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
    if(!t) return ERROR;
}

//中序遍历
Status midPrint(BiTree t){
    if(!t) return ERROR;
}

//后序遍历
Status subPrint(BiTree t){
    if(!t) return ERROR;
}

int main(){
    BiTree t = initTree();
    createTree(t);
    return 0;
}
