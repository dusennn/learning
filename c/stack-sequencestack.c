#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT_SIZE 10
#define MAX_SIZE 100
#define ERROR -1
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct SqStack{
    ElemType *top;
    ElemType *base;
    int stacksize;
}SqStack;

Status initStack(SqStack *s){
    s = (SqStack *)malloc(INIT_SIZE*sizeof(ElemType));
    if(s->base) exit(0);

    s->top = s->base;
    s->stacksize = 0;
    return OK;
}

int main(){
    SqStack s;
    initStack(&s);
    printf("%d\n", s.stacksize);
    return 0;
}
