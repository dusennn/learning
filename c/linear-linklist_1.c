#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void print(LinkList l){
    int j = 1;
    LinkList p = l->next;
    while(p){
        printf("Point: %d, Data: %d\n", j, p->data);
        p = p->next;
        j++;
    }
}

void generateTestData(LinkList l){
    srand(time(0));
    for(int i=1; i<10; i++){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = rand()%1000;
        n->next = l->next;
        l->next = n;
    }
    printf("generate success...\n");
    print(l);
}

//算法：快速查找任意长度单链表的中间节点(利用快慢指针原理)
void searchMid(LinkList l, LNode *mid){
    LNode *fast, *slow;
    slow = l;
    fast = l;
    while(fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    mid->next = slow;
}

void main(){ 
    LinkList L = InitList();
    generateTestData(L);

    LNode *mid = (LNode *)malloc(sizeof(LNode));
    searchMid(L, mid);
    printf("Mid Node: %d\n", mid->next->data);
}
