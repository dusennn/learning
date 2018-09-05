#include <stdio.h>

//阶乘
int jiecheng(int num){
    return num<=1?num:num*jiecheng(num-1);
}

// 斐波那契数列
int fib(int n){ 
    return n<2?n:fib(n-1)+fib(n-2);
}

int fib2(){
    int num = 40;
    for(int i=0; i<40; i++){
        printf("%d ", fib(i));
    }
    printf("\n");
}

int fib1(){
    int arr[40];

    arr[0] = 0;
    arr[1] = 1;
    printf("%d %d ", arr[0], arr[1]);
    for(int i=2; i<40; i++){
        arr[i] = arr[i-1] + arr[i-2];
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int num, result;

    num = 4;
    result = jiecheng(num);
    printf("%d -> %d\n", num, result);
   // printf("迭代：\n");
   // fib1();
   // printf("递归：\n");
   // fib2();
}
