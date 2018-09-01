#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DualList;

DualList initList(){
    DualList l = (DualNode *)malloc(sizeof(DualNode));
    if(!l) exit(0);

    l->prior = l;
    l->next = l;
    return l;
}

void randomData(DualList l){
    if(!l) exit(0);

    DualNode *target = l;
    for(int i=1; i<=6; i++){
        DualNode *temp = (DualNode *)malloc(sizeof(DualNode));
        temp->data = i*2;
        temp->prior = target;
        temp->next = target->next;
        target->next = temp;
        target = target->next;
    }
}

void print(DualList l){
    if(!l) exit(0);

    DualNode *head, *target;
    head = l;
    target = l->next;
    int count=1;
    while(head!=target){
        printf("%d -> %d\n", count, target->data);
        target = target->next;
        count++;
    }
}

int lengthList(DualList l){
    if(!l||l==l->next) return -1;

    DualNode *head, *target;
    head = l;
    target = l->next;
    int count=0;
    while(head!=target){
        count++;
        target = target->next;
    }

    return count;
}

int listInsert(DualList l, int point, ElemType *e){
    if(!l||point<1||point>lengthList(l)) return -1;

    DualNode *target = l;
    for(int i=1; i<=point; i++){
        target = target->next;
    }
    if(!target) return -1;

    DualNode *temp = (DualNode *)malloc(sizeof(DualNode));
    temp->data = *e;
    temp->next = target;
    temp->prior = target->prior;
    target->prior->next = temp;
    target->prior = temp;

    return 1;
}

void main(){
    DualList l = initList();
    ElemType e;
    randomData(l);

    printf("before insert:\n");
    print(l);
    e = 99;
    listInsert(l, 2, &e);
    printf("after insert...\n");
    print(l);
}
