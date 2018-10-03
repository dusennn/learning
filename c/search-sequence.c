#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1

typedef int Status;

//「数组下标从1开始」

//data: 数据集
//len: 数据长度
//key: 关键字
Status sqSearch(int *data, int len, int key){
    for(int i=1; i<len; i++){
        if(data[i] == key) return OK;
    }
    return ERROR;
}

Status sqSearch2(int *data, int len, int key){
    int n = len;
    data[0] = key;
    while(data[n] != key){
        n--;
    }
    return n;
}

int main(){
    int *data;
    data = (int *)malloc(10 * sizeof(int));
    srand(time(0));
    for(int i=1; i<=9; i++){
        data[i] = rand() % 20; 
    }

    Status s = sqSearch(data, 9, 3);
    printf("Status: %d\n", s);

    s = sqSearch2(data, 9, 3);
    printf("Status: %d\n", s);
}
