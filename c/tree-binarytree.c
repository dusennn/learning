#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//先序方式
Status createTreeByPre(BiTree *t){
    char c;
    scanf("%c", &c);
    if(c == ' '){
        t = NULL;
    }else{
        *t = (BiTNode *)malloc(sizeof(BiTNode));
        (*t)->data = c;
        createTreeByPre(&(*t)->lchild);
        createTreeByPre(&(*t)->rchild);
    }
}

Status visit(BiTree t, int layer){
    printf("DATA: %c, LAYER: %d\n", t->data, layer);
}

//先序遍历
Status prePrint(BiTree t, int layer){
    if(t){
        visit(t, layer);
        prePrint(t->lchild, layer+1);
        prePrint(t->rchild, layer+1);
    } 
} 

//中序遍历
Status midPrint(BiTree t, int layer){
    if(t){
        midPrint(t->lchild, layer+1);
        visit(t, layer);
        midPrint(t->rchild, layer+1);
    }
}

//后序遍历
Status subPrint(BiTree t, int layer){
    if(t){
        subPrint(t->lchild, layer+1);
        subPrint(t->rchild, layer+1);
        visit(t, layer);
    }
}

int main(){
    BiTree t = NULL;
    int layer = 1;

    printf("Create Tree(Pre):\n");
    createTreeByPre(&t);

    printf("\nPrint Tree(Pre):\n");
    prePrint(t, layer);

    printf("\nPrint Tree(Mid):\n");
    midPrint(t, layer);

    printf("\nPrint Tree(Sub):\n");
    subPrint(t, layer);
    return 0;
}
