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

int ListInsert(LinkList l, int i, ElemType e){
    int j = 0;
    LinkList p = l;
    if(!l&&j>=i) return ERROR;
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

void generateTestData(LinkList l){
    srand(time(0));
    for(int i=1; i<5; i++){
        ListInsert(l, 1, rand()%100+1);
    }
}

int getElem(LinkList l, int i, ElemType *e){
    if(!l->next || i < 1) return ERROR;
    int count = 1;
    LNode *n = l;
    while(n->next){
        if(count == i){
            *e = n->next->data;
            return OK;
        }
        count++;
        n = n->next;
    }

    if(!e) return ERROR;
}

int listDel(LinkList l, int i, ElemType *e){
    if(!l || i < 1) return ERROR;

    LinkList p = l;
    int count = 1;
    while(p->next){
        if(count == i){
            *e = p->next->data; 
            p->next = p->next->next;  
            return OK;
        }
        count++;
        p = p->next;
    }

    if(!e) return ERROR;

}

int mergeList(LinkList la, LinkList lb, LinkList lc){
    while(la->next){
        lc->next = la->next;
        lc = la->next;
        la = la->next;
    }
    lc->next = lb->next?lb->next:NULL;
}

//头插法创建列表
void createListHeard(LinkList l){
    srand(time(0));
    int count = 0;
    while(count <5){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = rand() % 100 + 1;
        n->next = l->next;
        l->next = n;
        count++;
    }
}

//尾插法
void createListTail(LinkList l){
    LinkList p = l;
    srand(time(0));
    int count = 0;
    while(count < 5){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = rand()%100+1;
        l->next = n;
        l=n;
        count++;
    }
    l->next=NULL;
}

int listEmpty(LinkList l){
    LinkList p = l;
    while(p){
        p = l->next;
        l->next=NULL;
        l = p;
    }
}

void main(){ 
    LinkList L = InitList();
    generateTestData(L);
    printf("before list empty...\n");
    print(L);
    listEmpty(L);
    printf("after list empty...\n");
    print(L);
    // createListTail(L);
    // print(L);
    // createListHeard(L);
    // print(L);
    //  LNode *N;
    //  N = (LNode *)malloc(sizeof(LNode));
    //  N->data = 2;
    //  N->next =L->next;
    //  L->next = N;
    //  generateTestData(L);
    //  print(L);
    /*
       printf("before insert...\n");
       print(L);
       printf("after insert...\n");
       ListInsert(L, 1, 105);
       print(L);
       */

    //    ElemType e;
    //    int status = getElem(L, 3, &e);
    //    if(!status){
    //        printf("getting error!\n");
    //    }else{
    //        printf("getting success!\n");
    //        printf("Point %d : %d \n", 3, e);
    //    }


    // ElemType e; 
    // int status = listDel(L, 3, &e);
    // if(!status){
    //     printf("del error!\n");
    // }else{
    //     printf("del success!\n");
    //     printf("Point %d : %d \n", 3, e);
    //     printf("del after...\n");
    //     print(L);
    // }

  //  LinkList la = InitList();
  //  LinkList lb = InitList();
  //  LinkList lc = InitList();

  //  ListInsert(la, 1, 10);
  //  ListInsert(la, 2, 13);
  //  ListInsert(lb, 1, 4);
  //  ListInsert(lb, 2, 5);
  //  ListInsert(lb, 3, 17);
  //  ListInsert(lb, 4, 19);
  //  printf("after merge list...\n");
  //  print(la);
  //  print(lb);
  //  mergeList(la, lb, lc);
  //  printf("before merge list:\n");
  //  print(lc);
}
