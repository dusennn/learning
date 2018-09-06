#include <stdio.h>

//将 n 个盘子从 x 借助 y 移动到 z
void move(int n, char x, char y, char z){
    if(n == 1){
        printf("%c-->%c\n", x, z);
    }else
        //将 n-1 个盘子从 x 借助 z 移动到 y 上
        move(n-1, x, z, y);
        //将 第 n 个盘子从 x 移动到 z 上
        printf("%c-->%c\n", x, z);
        //将 n-1 个盘子从 y 借助 x 移动到 z 上
        move(n-1, y, x, z);
    }
}

int main(){
    printf("请输入汉诺塔层数：");
    int n;
    scanf("%d", &n);
    printf("移动顺序是：\n");
    move(n, 'X', 'Y', 'Z');
}
