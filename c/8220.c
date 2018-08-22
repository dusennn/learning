#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

void print(SqList s){
    for(int i=1; i<=s.length; ++i){
        printf("%d\t%d\n", i, s.data[i]);
    }
}

ElemType get(SqList *s, int point){
    return !s ? -1 : point < 0 ? -1 : (s -> length) < point ? -1 : s -> data[point];
} 

int insert(SqList *s, int point, ElemType e){
    if(point == 0 || point > s->length){
        return -1;
    }
    ElemType temp = s -> data[point];
    s -> data[point] = e;
    for(int i = s->length + 1; i > point; i--){
        s -> data[i] = s -> data[i-1];
    }
    s -> data[point+1] = temp;
    s -> length++;
    
    return 1;
}

int edit(SqList *s, int point, ElemType e){
    if(!s || point < 1 || point > s->length){
        return -1;
    }
    s->data[point] = e;
    return 1;
}

int delete(SqList *s, int point, ElemType *e){
    if(s != NULL && point > 0 && point <= (s -> length)){
        e = &s -> data[point];
        for (int i=point; i<s->length; i++){
            s -> data[i] = s -> data[i+1];
        }
        s -> length--;
        return 1;
    }
    return -1;
}

int main(){
    SqList s;
    ElemType e;
    s.data[0] = 0;
    s.data[1] = 3;
    s.data[2] = 2;
    s.data[3] = 7;

    s.length = 3;
    
    //int temp = get(&s, 23);
    //printf("%d\n", temp);
    print(s);
    //printf("excute delete。。。\n");
    //delete(&s, 1, &e);

    //printf("excute insert。。。\n");
    //e = 9;
    //insert(&s, 1, e);
    
    printf("excute edit。。。\n");
    e = 10;
    edit(&s, 3, e);
    print(s);
    return 0;
}
    
