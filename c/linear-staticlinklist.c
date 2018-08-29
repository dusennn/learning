#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 10

typedef int ElemType;

typedef struct SLList{
    ElemType data;
    int cur;
}Component, SLList[MAXSIZE];

void initList(SLList s){

    for(int i=0; i<MAXSIZE; i++){
        s[i].cur = i+1;
        s[i].data = 0;
    }
    s[MAXSIZE-1].cur = 0;
}

void print(SLList s){
    for(int i=0; i<MAXSIZE; i++){
        printf("Point: %d, Data: %d, Cursor: %d\n", i, !s[i].data?0:s[i].data, s[i].cur);
    }
}

void randomData(SLList s){
    srand(time(0));
    int i;
    for(i=1; i<=3; i++){
        s[i].data = rand()%100+1;
        s[i].cur = i+1;
        s[0].cur = i+1;
        s[MAXSIZE-1].cur = 1;
    }
    s[i-1].cur = 0;
}

//获取空闲分量的游标
int malloc_sll(SLList s){
    int cursor = s[0].cur;
    if(cursor)
        s[0].cur = s[cursor].cur;
    
    return cursor;
}

int listInsert(SLList s, int i, ElemType e){
    if(i<1 || i>MAXSIZE-1 || !s[MAXSIZE-1].cur) return ERROR;
    
    /*寻找要插入位置的前一个元素。
    *通过链表最后一个元素的指针得到第一个元素的位置，
    *然后循环i-1次，得到要插入元素的前一个元素的游标。*/
    int pre = s[MAXSIZE-1].cur;
    for(int j=0; j<i-1; j++){
        pre = s[pre].cur;
    }
    
    int cursor = malloc_sll(s);
    s[cursor].data = e;
    s[cursor].cur = i;
    s[pre].cur = cursor;

    return OK;
}

int getElem(SLList s, int i, ElemType *e){
    int len = MAXSIZE-1;
    if(i<1||i>len||!s[len].cur) return ERROR;

    int cursor = s[len].cur;
    for(int j=0; j<i-1; j++){
        cursor = s[cursor].cur;
    }
    if(cursor!=i) return ERROR;

    *e = s[cursor].data;
    return OK;
}

int listDel(SLList s, int i, ElemType *e){
    int len = MAXSIZE-1;
    if(i<1||i>len||!s[len].cur) return ERROR;
    
    //获取待删除元素的前一个元素的游标。
    int cursor = s[len].cur;
    for(int j=1; j<i-1; j++){
        cursor = s[cursor].cur;
    }
    if(s[cursor].cur!=i) return ERROR;
    
    //首先把待删除元素的游标指向列表第一个空元素，
    //然后把列表第0个位置的游标指向待删除元素的位置，
    //最后把该元素删除，再把待删除元素的前一个元素游标指向待删除元素的后一个元素位置。 
    int ncur = s[cursor].cur;
    s[cursor].cur = s[s[cursor].cur].cur;
    *e = s[ncur].data;
    s[ncur].cur = s[0].cur;
    s[ncur].data = 0;
    s[0].cur = i;
    
    return OK;

}

int main(){
    SLList s;
    initList(s);
    randomData(s);
    printf("before del...\n");
    print(s);
    ElemType e;
    listDel(s, 2, &e);
    printf("after del...\n");
    print(s);
    printf("Point %d: %d\n", 2, e);
   // print(s);
   // ElemType e;
   // getElem(s, 2, &e);
   // printf("Point %d: %d\n", 2, e);
   // printf("before insert...\n");
   // print(s);
   // ElemType e;
   // e = 10;
   // listInsert(s, 1, e);
   // printf("after insert...\n");
   // print(s);
}
