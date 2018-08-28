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

int listInsert(SLList s, int i, ElemType e){
    if(i < 1 || i > MAXSIZE-1 || i > s[0].cur) return ERROR;
    
    int cursor = s[0].cur;
    s[0].cur = (cursor+1);
    s[cursor].data = e;

    if(!s[MAXSIZE-1].cur){
        s[cursor].cur = 0;
        s[MAXSIZE-1].cur = 1;
    }else{
        s[cursor].cur = (i+1);
    }
   
    if(i == 1){
        s[MAXSIZE-1].cur = cursor;
        s[cursor].cur = 1;
    }else{
        s[i-1].cur = cursor;
    }
    
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
    listInsert(s, 3, e);
    printf("after insert...\n");
    print(s);
    printf("generate random data...\n");
//    randomData(s);
//    print(s);
}
