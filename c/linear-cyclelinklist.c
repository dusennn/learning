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

//rear
CycleLinkList initListByRear(){
    CycleLinkList l = (LNode *)malloc(sizeof(LNode));
    if(!l) exit(0);

    l->next = l;
    l = l->next;
    return l;
}

void randomData(CycleLinkList l, int key){
    srand(time(0));
    LNode *rear = l;
    for(int i=0; i<5; i++){
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->data = key*(rand()%10);
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}

void printByRear(CycleLinkList l){
    LNode *rear, *target;
    rear = l;
    target = l->next;
    int count = 1;
    while(rear!=target){
        printf("Point:%d, Data:%d\n", count, target->data);
        count++;
        target = target->next;
    }
}

//链表合并，借助循环链表rear表示法
int merge(){
    CycleLinkList la, lb;
    la = initListByRear();
    lb = initListByRear();
    randomData(la, 1);
    randomData(lb, 2);

    printf("List la:\n");
    printByRear(la);
    printf("List lb:\n");
    printByRear(lb);

    CycleLinkList lc;
    lc = la->next;
    la->next = lb->next->next;
    free(lb->next);
    lb->next = lc;
    
    printf("after merge.\n");
    printByRear(lb);
}

//判断列表是否是循环表
int validLoop(CycleLinkList l){
    LNode *this = l;
    while(1){
        if(!l) return 1;

        if(this==l->next) return 2;

        l = l->next;
    }
}

//判断链表中是否有环 (prepare)
void validLoopPrepared(){
    CycleLinkList iLoop, nLoop;//iLoop: is loop; nLoop: not loop;
    //create
    iLoop = (LNode *)malloc(sizeof(LNode));
    if(!iLoop) exit(0);
    iLoop->next = iLoop;
    iLoop = iLoop->next;
    nLoop = (LNode *)malloc(sizeof(LNode));
    if(!nLoop) exit(0);
    nLoop->next = NULL;

    LNode *itarget, *ntarget;
    itarget = iLoop;
    ntarget = nLoop;
    //add element
    for(int i=1; i<6; i++){
        LNode *temp = (LNode *)malloc(sizeof(LNode));
        temp->data = i;
        temp->next = itarget->next;
        itarget->next = temp;
        itarget = itarget->next;

        LNode *temp2 = (LNode *)malloc(sizeof(LNode));
        temp2->data = i*2;
        temp2->next = ntarget->next;
        ntarget->next = temp2;
    }

    //print
    int count = 1;
    LNode *rear = iLoop;
    while(rear!=iLoop->next){
        printf("%d -> %d\n", count, iLoop->data);
        iLoop = iLoop->next;
        count++;
    }
    count = 1;
    while(nLoop){
        printf("%d -> %d\n", count, nLoop->data);
        nLoop = nLoop->next;
        count++;
    }

    //调用方法
    int isLoop = validLoop(iLoop);
    printf("%d\n", isLoop);
}

int main(){
    validLoopPrepared();
   // merge();
   // CycleLinkList l = initList();
   // ElemType e;
   // //createListByHead(l);
   // createListByTail(l);
   // printf("before del:\n");
   // print(l);
   // printf("after del...\n");
   // listDel(l, 1, &e);
   // print(l);
   // printf("deleted element: %d\n", e);
   // printf("before insert:\n");
   // print(l);
   // printf("after insert...\n");
   // e = 99;
   // listInsert(l, 3, &e);
   // print(l);
}
