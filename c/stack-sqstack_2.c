#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 20
#define INCREASE_SIZE 10
#define MAX_SIZE 100
#define ERROR -1
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct SqStack{
    ElemType *top;
    ElemType *base;
    int stackSize;
}SqStack;

Status initStack(SqStack *s){
    s->base = (ElemType *)malloc(INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);

    s->top = s->base;
    s->stackSize = INIT_SIZE;

    return OK;
}

Status push(SqStack *s, ElemType e){
    if(s->top - s->base >= s->stackSize){
        s->base = (ElemType *)realloc(s->base, (INCREASE_SIZE + s->stackSize)*sizeof(ElemType));
        if(!s->base) exit(0);

        s->top = s->base + s->stackSize;
        s->stackSize += INCREASE_SIZE;
    }
    *s->top++ = e;
    return OK;
}

Status pop(SqStack *s, ElemType *e){
    if(s->top == s->base) return ERROR;

    *e = *--s->top;
    return OK;
}

int length(SqStack s){
    return (s.top-s.base);
}


int main(){
    SqStack s;
    initStack(&s);

}
