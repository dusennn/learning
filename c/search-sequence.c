#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1

typedef int Status;

//data: 数据集
//len: 数据长度
//key: 关键字
Status sqSearch(int *data, int len, int key){
    for(int i=0; i<len; i++){
        if(data[i] == key) return OK;
    }
    return ERROR;
}

int main(){
    int *data;
    data = (int *)malloc(10 * sizeof(int));
    srand(time(0));
    for(int i=0; i<10; i++){
        data[i] = rand() % 100; 
    }
    Status s = sqSearch(data, 8, 3);
    printf("Status: %d\n", s);
}
