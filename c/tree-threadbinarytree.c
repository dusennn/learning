#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct ThrNode{
    ElemType data;
    int ltag, rtag;
    struct ThrNode *lchild, *rchild;
}ThrNode, *ThrTree;

Status createTree(ThrTree *t){
    char c;
    scanf("%c", &c);
    if(c == ' '){
        t = NULL;
    }else{
        *t = (ThrNode *)malloc(sizeof(ThrNode));
        (*t)->data = c;
        (*t)->ltag = (*t)->rtag = 0;
        createTree(&(*t)->lchild);
        createTree(&(*t)->rchild);
    }
}

void visit(ThrTree t, int layer){
    printf("DATA:%c, LAYER:%d\n", t->data, layer);
}

Status midPrint(ThrTree t, int layer){
    if(t){
        midPrint(t->lchild, layer+1);
        if(!t->lchild){
            t->lchild = t;
            t->ltag = 1;
        }
        visit(t, layer);
        midPrint(t->rchild, layer+1);
        if(!t->rchild){
            t->rchild = t;
            t->rtag = 1;
        }
    }
}

int main(){ 
    ThrTree t = NULL;
    int layer = 1;
    printf("Create Tree(Pre):\n");
    createTree(&t);
    
    printf("Print Tree(Mid):\n");
    midPrint(t, layer);

    printf("test:\n");
    printf("-%c- -%d-\n", t->lchild->lchild->data, t->lchild->ltag);
    return 0;
}
