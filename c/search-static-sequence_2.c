#include <stdio.h>
#include <stdlib.h>

#define ERORR 0
#define OK 1
#define MAX_SIZE 20

typedef int Status;

typedef struct Student{
    int number;
    char name;
    int score;
}Student, Students[MAX_SIZE];
typedef struct {
    Students s;
}Tables;

Status init(Tables *t){
    t->s[1].number = 1024;
    t->s[1].name = 'A';
    t->s[1].score = 100;

    t->s[2].number = 1026;
    t->s[2].name = 'B';
    t->s[2].score = 80;

    t->s[3].number = 1028;
    t->s[3].name = 'C';
    t->s[3].score = 90;

    t->s[4].number = 1030;
    t->s[4].name = 'D';
    t->s[4].score = 79;

    return OK;
}

void print(Tables t, int len){
    printf("学号\t 姓名\t 成绩\n");
    for(int i=1; i<len; i++){
        printf("%4d\t%4c\t%4d\n", t.s[i].number, t.s[i].name, t.s[i].score);
    }
}

int search(Tables *t, int len, int number){
    int i = len;
    t->s[0].number = number;
    while(t->s[i].number != number){
        i--;
    }
    return i;
}

int main(){
    Tables t;
    init(&t);
    print(t, 5);

    int number;
    printf("请输入学号：");
    scanf("%d", &number);
    getchar();
    int index = search(&t, 5, number);
    if(index != 0){
        printf("Search success!\n");
        printf("Students: [number:%d, name:%c, score:%d]\n", t.s[index].number, t.s[index].name, t.s[index].score);
    }else{
        printf("Search fail!\n");
    }
    return 0;
}
