#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int ElemType;
//双亲表示法
typedef struct PTNode{
    ElemType data; //节点数据
    int parent;     //双亲位置域
}PTNode;

typedef struct{
    PTNode node[MAX_SIZE];
    int r, n; //根的位置和节点数
}PTree;

int main(){
    
    return 0;
}
