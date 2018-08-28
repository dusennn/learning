#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct SLList{
    ElemType data;
    int cur;
}Component, SLList[MAXSIZE];

void initList(SLList s){

    for(int i=0; i<MAXSIZE; i++){
        s[i].cur = i+1;
    }
    s[MAXSIZE-1].cur = 0;
}

void print(SLList s){
    for(int i=0; i<MAXSIZE; i++){
        printf("Point: %d, Data: %d, Cursor: %d\n", i, s[i].data, s[i].cur);
    }
}

void randomData(SLList s){
    srand(time(0));
    for(int i=1; i<6; i++){
        s[i].data = rand()%100+1;
        s[i].cur = i+1;
        s[0].cur = i+1;
        s[MAXSIZE-1].cur = 1;
    }
}

int listInsert(SLList *s, int i, ElemType *e){
    Component c = s[s[MAXSIZE-1].cur];
    while(c){
        if(c.data){
            c = s[c.cur];
       }else{
            s[0].cur = c.cur;
            break;
        }
    }

    s[s[0].cur].data = e;
    s[s[0].cur].cur = ;
    s[c.cur].cur = s[0].cur;


}

int main(){
    SLList s;
    initList(s);

//    printf("generate random data...\n");
//    randomData(s);
//    print(s);
}
