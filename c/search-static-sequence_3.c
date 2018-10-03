#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int Status;

Status binarySearch(int *list, int len, int key){
    int low, mid, high;
    low = 0;
    high = len-1;
    if(key < list[low] || key > list[high]) return ERROR;

    mid = high/2;
    while(1){
        if(key == list[mid]) return OK;
        if(low == (high - 1)) return ERROR;        

        if(key < list[mid]){
            high = mid;
            mid = high / 2;
            continue;
        }

        if(key > list[mid]){
            low = mid;
            mid = (high + low + 1) / 2;
            continue;
        }
    }
}

int main(){
    int list[10] = {1, 3, 22, 35, 34, 122, 524, 664, 867, 945};
    Status s = binarySearch(list, 10, 122);
    printf("Status: %d \n", s);
    return 0;
}
