#include <stdio.h>
#include <stdlib.h>

#define InitSize 100
#define IncreaseSize 10

typedef int ElemType;

typedef struct {
    ElemType *node;
    int MaxSize,length;
}SqList;

void main(){
    SqList l;
    l.node = (ElemType*)malloc(sizeof(ElemType)*InitSize);

    printf("%d\n%d\n", l.length, l.MaxSize);
}
