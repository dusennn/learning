#include <stdio.h>

int main(){
    int num;
    printf("%s\n", "请输入一个数字：");
    scanf("%d", &num);
    (num % 2 == 0) ? printf("%d 对二取模等于零\n", num) : printf("%d 对二取模不等于零\n", num);

    return 0;
}