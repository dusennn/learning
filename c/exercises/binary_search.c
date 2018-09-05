#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define ERROR -1
#define OK 1

typedef int Status;
typedef int ElemType;
typedef struct List{
    ElemType data[MAX_SIZE];
    int length;
}List;

Status initList(List *l){
    for(int i=0; i<50; i++){
        l->data[i] = i*3;
        l->length++;
    }
    return OK;
}

Status print(List l){
    for(int i=0; i<MAX_SIZE; i++){
        printf("%d -> %d\n", i, l.data[i]);
    }
    return OK;
}

//折半查找：迭代
Status binarySearchByIterator(List l, int num, int *point){
    int low, mid, high, temp;
    low = 0;
    high = MAX_SIZE - 1;
    mid = high / 2;
    
    if(num > l.data[high] || num < l.data[low]) return ERROR;
    if(num == l.data[high]){
        *point = high;
        return OK;
    }
    if(num == l.data[low]){
        *point = low;
        return OK;
    }

    while(1){
        temp = l.data[mid];
        printf("low:%d, mid:%d, high:%d, temp:%d\n", low, mid, high, temp);
        if(temp == num){
            *point = mid;
            return OK;
        }
        
        if(num < temp){
            high = mid;
            mid = high / 2;
        }
        
        if(num > temp){
            low = mid;
            mid = (high + low) / 2;
        }

        if(low == mid) return ERROR;
    }
}

//折半查找：递归
Status binarySearchByRecursion(List l){
   ElemType *low, *mid, *high;
}

int main(){
    List l;
    initList(&l);
    printf("Original list:\n");
    print(l);

    int num, point;
    printf("Input：");
    scanf("%d", &num);
    int status = binarySearchByIterator(l, num, &point);
    if(status == 1){
        printf("search success!\nnum:%d->point:%d\n", num, point);
    }else{
        printf("search error!\nnum:%d not exists!\n", num);
    }
}
