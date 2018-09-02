#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int stacksize;
}SqStack;

Status initStack(SqStack *s){
    s->base = (ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
    if(!s->base) exit(0);

    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return OK;
}

Status push(SqStack *s, ElemType e){
    if(s->top-s->base>=s->stacksize){
        s->base = (ElemType *)realloc(s->base, (s->stacksize+INCREASE_SIZE)*sizeof(ElemType));

        if(!s->base) exit(0);
        s->top += *(s->base+s->stacksize);
        s->stacksize += INCREASE_SIZE;
    }
    *s->top++ = e;

    return OK;
}

Status pop(SqStack *s, ElemType *e){
    if(!s->base) return ERROR;

    e = s->top-1;
    s->top--;
    return OK;
}

int stackLength(SqStack s){
    return s.top-s.base;
}

Status randomData(SqStack *s){
    srand(time(0));
    for(int i=1; i<=6; i++){
        push(s, rand()%100);
    }
    return OK;
}

Status getTop(SqStack s, ElemType *e){
    if(!s.base||s.top==s.base) return ERROR;

    *e = *(s.top-1);
    return OK;

}

Status clearStack(SqStack *s){
    if(!s->base) return ERROR;

    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return OK;
}

Status destoryStack(SqStack *s){
    int len = s->stacksize;
    for(int i=0; i<len; i++){
        free(s->base);
        s->base++;
    }
    s->top = s->base = NULL;
    s->stacksize =0;
    
    return OK;
}

int main(){
    SqStack s;
    ElemType e;
    initStack(&s);
    
    e = 10;
    push(&s, e);
    randomData(&s);randomData(&s);randomData(&s);randomData(&s);
    
    int len = stackLength(s);
    printf("current stack size : %d\n", len);

    getTop(s, &e);
    printf("stack top : %d\n", e);

    pop(&s, &e);
    printf("pop stack : %d\n", e);
    len = stackLength(s);
    printf("current size : %d\n", len);

   // clearStack(&s);
   // printf("clear stack...\n");
   // len = stackLength(s);
   // printf("current size : %d\n", len);

    printf("destroy stack...\n");
    destoryStack(&s);
    len = stackLength(s);
    printf("current size: %d\n", len);
    

}
