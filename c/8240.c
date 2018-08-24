#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 0
#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList InitList(){
    LinkList L = (LNode *)malloc(sizeof(LNode));
    
    if(!L) exit(OVERFLOW);
    
    L->next =NULL;

    return L;
}

int ListInsert(LinkList l, int i, ElemType e){
    int j = 0;
    LinkList p = l;
    if(!p||j>=i) return ERROR;
    while(p && j < i - 1){
        p = p->next;
        j++;
    }
        
    if(!p || j > i ) return ERROR;
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->data = e;
    n->next = p->next;
    p->next = n;
    return OK;

}

void print(LinkList l){
    int j = 1;
    LinkList p = l->next;
    while(p){
        printf("%d  -> %d\n", j, p->data);
        p = p->next;
        j++;
    }
}

void main(){ 
    LinkList L = InitList();
    
    LNode *N;
    N = (LNode *)malloc(sizeof(LNode));
    N->data = 2;
    N->next =L->next;
    L->next = N;
    LNode *n2;
    n2 = (LNode *)malloc(sizeof(LNode));
    n2->data = 5;
    n2->next =L->next->next;
    L->next->next = n2;
    
    printf("before insert...\n");
    print(L);
    printf("after insert...\n");
    ListInsert(L, 0, 100);
    print(L);
    
}
