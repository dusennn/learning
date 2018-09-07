#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int ElemType;
typedef struct CTNode{
    ElemType data;
    struct CTNode *next;
}*ChildPtr;

typedef struct CTBox{
    ElemType data;
    int parent;
    ChildPtr firstChild; //第一个孩子
}CTBox;

typedef struct{
    CTBox nodes[MAX_SIZE];
    int r,n; //根的位置和节点数
}CTree;

int main(){
    
    return 0;
}
