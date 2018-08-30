#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct LNode{ 
    ElemType data;
    struct LNode *next;
}LNode, *CycleLinkList;

CycleLinkList initList(){
    CycleLinkList l = (LNode *)malloc(sizeof(LNode));

    if(!l) exit(0);

    l->next = l;
    return l;
}

void print(CycleLinkList l){
    LNode *head = l;
    CycleLinkList p = l->next;
    int count = 0;
    while(p!=head){
        printf("Point: %d, Data:%d \n", ++count, p->data);
        p = p->next;
    }
}

int createListByHead(CycleLinkList l){
    for(int i=0; i<3; i++){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = 10+i;
        n->next = l->next;
        l->next = n;
    }
    return OK;
}

int createListByTail(CycleLinkList l){
    LNode *head = l;
    while(head!=l->next){
        l=l->next;
    }
    for(int i=0; i<3; i++){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = 20+i;
        n->next = head;
        l->next = n;
        l = l->next;
    }
    return OK;
}

int listInsert(CycleLinkList l, int i, ElemType *e){
    if(!l||i<1) return ERROR;

    LNode *head, *tail;
    head = l;
    tail = l->next;
    int len = 0;
    while(tail!=head){
        tail = tail->next;
        len++;
    }

    if(i>len) return ERROR; //要插入位置超过表长

    LNode *temp = (LNode *)malloc(sizeof(LNode));
    temp->data = *e;
    if(i == 1){
       temp->next = head->next;
       tail->next = temp;
    }else{
        LNode *target = l;
        for(int j=1; j<i; j++){
            target = target->next;
        }
        temp->next = target->next;
        target->next = temp;
    }

    return OK;
}

int lengthList(CycleLinkList l){
    LNode *head, *target;
    head = l;
    target = l->next;
    int len=0;
    while(target!=head){
        target = target->next;
        len++;
    }
    return len;
}

int listDel(CycleLinkList l, int i, ElemType *e){
    int len = lengthList(l);
    if(!l||i<1||i>len) return ERROR;

    LNode *head, *target;
    head = l;
    target = l->next;

    if(i==1){
        *e = head->next->data;
        head->next = head->next->next;
    }else{
        for(int j=1; j<i-1; j++){
            target = target->next;
        }
        *e = target->next->data;
        target->next = target->next->next;
    }
    return OK;
}

int main(){
    CycleLinkList l = initList();
    ElemType e;
    //createListByHead(l);
    createListByTail(l);
    printf("before del:\n");
    print(l);
    printf("after del...\n");
    listDel(l, 1, &e);
    print(l);
    printf("deleted element: %d\n", e);
   // printf("before insert:\n");
   // print(l);
   // printf("after insert...\n");
   // e = 99;
   // listInsert(l, 3, &e);
   // print(l);
}


