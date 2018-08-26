#include <stdio.h>

#define true 1
#define false 0
#define MaxSize 50

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;

int ListLength(SqList L)
{
    return L.length;
}

int GetElem(SqList L, int i, ElemType *e)
{
    if(i < 1 || i > L.length)
        return false;
    
    *e = L.data[i];
    return true;
}

int LocateElem(SqList L, ElemType e){
    if(!L.data || !e)
        return false;

    for(int i=1; i<=L.length; i++){
        if(e == L.data[i]){
            return i;
        }
    }

    return false;
}

int LocateElem2(SqList *L, ElemType e){
    if(!L->data || !e)
        return false;

    for(int i=1; i<=L->length; i++){
        if(e == L->data[i]){
            return i;
        }
    }

    return false;
}

int ListInsert(SqList *L, int i, ElemType e){
    if(!L || i > L->length+1 || i < 1){
        return false;
    }

    for(int j=L->length; j >= i; j--){
        L->data[j+1] = L->data[j];
    }
    L->data[i] = e;
    L->length++;
    return true;
}

int ListDelete(SqList *L, int i, ElemType *e){
    if(!L || i > L->length || i < 1){
        return false;
    }

    *e = L->data[i];

    for(i=i+1; i<=L->length; i++){
        L->data[i-1]=L->data[i];    
    }
    L->length--;

    return true;
}

void print(SqList s){
    for(int i=1; i<=s.length; ++i){
        printf("%d\t%d\n", i, s.data[i]);
    }
}

void ListUnion(SqList *La, SqList Lb){
    //列表合并：把所有在Lb中而不在La中的元素插入到La
    for(int i=1; i<=Lb.length; i++){
        if(!LocateElem2(La, Lb.data[i])){
            La->data[La->length+1] = Lb.data[i];
            La->length++;
        }
    }
}

int main()
{
    SqList L;
    L.data[1] = 12;
    L.data[2] = 23;
    L.data[3] = 11;
    L.length = 3;
    SqList Lb;
    Lb.data[1] = 12;
    Lb.data[2] = 23;
    Lb.data[3] = 131;
    Lb.data[4] = 22;
    Lb.length = 4;


    //int len = ListLength(L);
    //printf("%d\n", len);

    ElemType e;
    //int flag = GetElem(L, 2, &e);
    //printf("%d\n", e);
    
    //e = 111;
    //int locate = LocateElem(L, e);
    //printf("%d\n", locate);

    //printf("insert before...\n");
    //print(L);
    //printf("insert after...\n");
    //e = 100;
    //ListInsert(&L, 4, e);
    //print(L);
    
    //printf("list union before...\n");
    //print(L);
    //printf("list union after...\n");
    //ListUnion(&L, Lb);
    //print(L);

    printf("list del before...\n");
    print(L);
    printf("list del after...\n");
    ListDelete(&L, 4, &e);
    printf("deleted element: %d\n", e);
    print(L);
}
