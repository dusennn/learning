#include <stdio.h>
#include <limits.h>


int main(){
    printf("char 存储大小：%lu \n", sizeof(char));
    printf("unsigned char 存储大小：%lu \n", sizeof(unsigned char));
    printf("signed char 存储大小：%lu \n", sizeof(signed char));
    printf("int 存储大小：%lu \n", sizeof(int));

    return 0;
}