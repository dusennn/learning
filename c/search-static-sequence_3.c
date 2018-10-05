#include <stdio.h>

#define ERROR 0
#define OK 1

typedef int Status;

Status binarySearch(int *list, int len, int key){
    int low, mid, high;
    low = 1;
    high = len;
    
    while(low <= high){
        mid = (low + high) / 2;

        if(list[mid] == key){
            return OK;
        }else if(list[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }

    }
    return ERROR;

}

int main(){
    //研究算法时，为了便于理解，下标默认1开始。
    int len = 10;
    int list[11] = {0, 1, 3, 4, 8, 9, 12, 15, 19, 23, 29};
    int key = 4;

    Status s;
    s = binarySearch(list, len, key);
    printf("Status:%d\n", s);
    return 0;
}
