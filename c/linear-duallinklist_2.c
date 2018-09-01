#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char ElemType;
typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DualList;

DualList initList(){
    DualList l = (DualNode *)malloc(sizeof(DualNode));
    if(!l) exit(0);

    l->prior = l;
    l->next = l;
    return l;
}

void print(DualList l){
    if(!l) exit(0);

    DualNode *head, *target;
    head = l;
    target = l->next;
    int count=1;
    while(head!=target->next){
        printf("%d -> %c\n", count, target->data);
        target = target->next;
        count++;
    }
}

int lengthList(DualList l){
    if(!l||l==l->next) return -1;

    DualNode *head, *target;
    head = l;
    target = l->next;
    int count=0;
    while(head!=target){
        count++;
        target = target->next;
    }

    return count;
}

/* pratice one:
要求实现用户输入一个数使得26个字母的排列顺序发生变化，
例如用户输入3，输出结果：
- DEFGHIJLMNOPQRSTUVWXYZABC
同时支持负数，例如用户输入-3，输出结果：
- XYZABCDEFGHIJLMNOPQRSTUVW
*/
void pratice1(){
    DualList l = initList();
    if(!l) exit(0);

    DualNode *target = l;
    for(int i=0; i<26; i++){
        DualNode *temp = (DualNode *)malloc(sizeof(DualNode));
        temp->data = 'A'+i;
        temp->next = target;
        temp->prior = target->prior;
        target->prior->next = temp;
        target->prior = temp;
    }
    l = l->prior;
    l->next = target->next;
    target->next->prior = l;
    l = l->next;
    target = l;

    printf("请输入一个数字：");
    int num;
    scanf("%d", &num);
    printf("\n");
    for(int i=0; i<(num<0?-num:num); i++){
        target = num<0?target->prior:target->next;
    }
    DualNode *this = target;
    do{
        printf("%c", target->data);
        target = target->next;
    }while(this!=target);
    printf("\n");

}

int main(){
    pratice1();

    return 0;
}
