#include <stdio.h>

int max(int num1, int num2){
    return (num1 >= num2) ? num1 : num2;
}

int main(){
    int num1, num2;
    printf("%s\n", "请输入一个数字:");
    scanf("%d", &num1);
    printf("%s\n", "请再输入一个数字:");
    scanf("%d", &num2);

    printf("%s：%d\n", "最大数：", max(num1, num2));

    return 0;
}