#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

void main (){
    SqList s;
    s.data[0] = 100;
    s.length = 1;

    printf("%d\n", s.data[0]);
}
