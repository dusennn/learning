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
    for(int j=1; j<i-1; j++){
        pre = s[pre].cur;
    }
    
    int cursor = malloc_sll(s);
    s[cursor].data = e;
    s[cursor].cur = i;
    s[pre].cur = cursor;

    return OK;
}

int main(){
    SLList s;
    initList(s);
    randomData(s);

    printf("before insert...\n");
    print(s);
    ElemType e;
    e = 10;
    listInsert(s, 1, e);
    printf("after insert...\n");
    print(s);
}
