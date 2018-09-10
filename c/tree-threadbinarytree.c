#include <stdio.h>
#include <stdlib.h>

#define ERROR -Thread
#define OK Thread

typedef int Status;
typedef char ElemType;
typedef enum {Link, Thread} PointerTag; //Link:0 Thread: 1

typedef struct ThrNode{
    ElemType data;
    PointerTag ltag, rtag;
    struct ThrNode *lchild, *rchild;
}ThrNode, *ThrTree;

ThrTree pre;

Status createTree(ThrTree *t){
    char c;
    scanf("%c", &c);
    if(c == ' '){
        t = NULL;
    }else{
        *t = (ThrNode *)malloc(sizeof(ThrNode));
        (*t)->data = c;
        (*t)->ltag = (*t)->rtag = Link;
        createTree(&(*t)->lchild);
        createTree(&(*t)->rchild);
    }
}

//二叉树线索化
Status inThreading(ThrTree t){
    if(t){
        inThreading(t->lchild); //线索化左孩子
        if(!t->lchild){
            t->ltag = Thread;
            t->lchild = pre;
        }

        if(!t->rchild){
            pre->rtag = Thread;
            pre->rchild = t;
        }
        pre = t;
        inThreading(t->rchild); // 线索化右孩子
    }
}

//借助全局变量线索化
Status inOrderThread(ThrTree *p, ThrTree t){
    (*p) = (ThrNode *)malloc(sizeof(ThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!t){
        (*p)->lchild = *p;
    }else{
        (*p)->lchild = t;
        pre = (*p);
        inThreading(t);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

int main(){ 
    ThrTree p, t = NULL;
    printf("Create Tree(Pre):\n");
    createTree(&t);
    inOrderThread(&p, t);

    return 0;
}
