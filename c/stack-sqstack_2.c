#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 20
#define INCREASE_SIZE 10
#define MAX_SIZE 100
#define ERROR -1
#define OK 1

typedef int Status;
typedef char ElemType;
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

int customPow(int num, int n){
    if(!num) return 0;
    if(!n) return 1;
    int result = 1;
    for(int i=1; i<=n; i++){
        result *=num;
    }
    return result;
}

/*
算法4：
利用栈的特点，把一个二进制数转换成十进制数。
转换公式：XnXn-1...X3X2X1 = X1*2^0+X2*2^1+X3*2^2+...+Xn*X^n-1
注：一个二进制数要转换成对应的十进制数，也就是从最低位起用第一位去乘以
对应位的积，也就是说用第n位去乘以2^(n-1)，然后全部加起来。
例如：1001 = 1*2^0 + 0*2^1 + 0*2^2 + 1*2^3 = 9 
*/
void binaryToDecimal(){
    SqStack s;
    initStack(&s);

    printf("二进制数：");
    char c = getchar();
    while(c != '\n'){
        push(&s, c);
        c = getchar();
    }
     
    ElemType e;
    int result, len;
    len = length(s);
    result = 0;
    for(int i=0; i<len; i++){
        pop(&s, &e);
        result += (e-48) * customPow(2, i); 
    }
    printf("十进制数：%d\n", result);
    
}

//逆波兰表达式
void pratice(){    
    SqStack s;
    initStack(&s);

    char c[10], temp;
    while(temp!='\n'){
        temp = getchar();
        printf("%c\n", temp);
    }
}

int main(){
    binaryToDecimal();
}
