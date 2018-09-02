#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    *e = *(s->top);
    s->top--;
    return OK;
}

Status clearStack(SqStack *s){
    if(!s->base) return ERROR;

    s->top = s->base;
    s->stacksize = INIT_SIZE;
    return OK;
}

/*
   算法4：
   利用栈的特点，把一个二进制数转换成十进制数。
   转换公式：XnXn-1...X3X2X1 = X1*2^0+X2*2^1+X3*2^2+...+Xn*X^n-1
   注：一个二进制数要转换成对应的十进制数，也就是从最低位起用第一位去乘以
   对应位的积，也就是说用第n位去乘以2^(n-1)，然后全部加起来。
   例如：1001 = 1*2^0 + 0*2^1 + 0*2^2 + 1*2^3 = 9 
   */
void binary2decimal(){
    //init
    SqStack s;
    initStack(&s);

    //input
    printf("请输入一个二进制数（回车键退出）：\n");
    char c;
    while(1){
        c = getchar();
        if(c=='\n') break;
        if(c<'0' || c>'1'){
            printf("你太皮了。。🤠\n");
            return;
        }

        //push
        push(&s, atoi(&c));
    }

    //convert
    int result = 0;
    for(int i=0; i<=s.top-s.base; i++){
        ElemType e;
        pop(&s, &e);
        result += (e * pow(2, i));
    }

    printf("\n新十进制数：%d\n", result);

    //clear
    clearStack(&s);
}

int main(){
    binary2decimal();
}
