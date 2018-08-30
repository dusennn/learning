#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct LNode{ 
    ElemType data;
    struct LNode *next;
}LNode, *CycleLinkList;

CycleLinkList initList(){
    CycleLinkList l = (LNode *)malloc(sizeof(LNode));

    if(!l) exit(0);

    l->next = l;
    return l;
}

void print(CycleLinkList l){
    LNode *head = l;
    CycleLinkList p = l->next;
    int count = 0;
    while(p!=head){
        printf("Point: %d, Data:%d \n", ++count, p->data);
        p = p->next;
    }
}

int createListByTail(CycleLinkList l, int length){
    LNode *head = l;
    while(head!=l->next){
        l=l->next;
    }
    for(int i=1; i<=length; i++){
        LNode *n = (LNode *)malloc(sizeof(LNode));
        n->data = i;
        n->next = head;
        l->next = n;
        l = l->next;
    }
    return OK;
}

int lengthList(CycleLinkList l){
    LNode *head, *target;
    head = l;
    target = l->next;
    int len=0;
    while(target!=head){
        target = target->next;
        len++;
    }
    return len;
}

int listDel(CycleLinkList l, int i, ElemType *e){
    int len = lengthList(l);
    if(!l||i<1||i>len) return ERROR;

    LNode *head, *target;
    head = l;
    target = l->next;

    if(i==1){
        *e = head->next->data;
        head->next = head->next->next;
    }else{
        for(int j=1; j<i-1; j++){
            target = target->next;
        }
        *e = target->next->data;
        target->next = target->next->next;
    }
    return OK;
}

/*约瑟夫问题：
 *据说著名犹太历史学家 Josephus有过以下的故事：
 在罗马人占领乔塔帕特后，39 个犹太人与Josephus及他的朋友躲到一个洞中，
 39个犹太人决定宁愿死也不要被敌人抓到，于是决定了一个自杀方式，41个人
 排成一个圆圈，由第1个人开始报数，每报数到第3人该人就必须自杀，然后再
 由下一个重新报数，直到所有人都自杀身亡为止。然而Josephus 和他的朋友
 并不想遵从 问题是，给定了和，一开始要站在什么地方才能避免被处决？
 Josephus要他的朋友先假装遵从，他将朋友与自己安排在第16个与第31个位置，
 于是逃过了这场死亡游戏.
*/
void josephus(CycleLinkList l, int num){
    int count = 1;
    int flag = lengthList(l)%num;
    while(l){
        if(count==flag+1){
            if(!l->next->data){
                l = l->next;
            }
            printf("%d->", l->next->data);
            l->next = l->next->next;
            count = 1;
        }
        count++;
        l = l->next;
        if(lengthList(l)==flag){
            printf("\n幸存者：%d, %d\n", l->data, l->next->data);
            return;
        }
    } 
} 

/*
 *算法2：编号为1~N的N个人按顺时针方向围坐一圈，每人持有
 一个密码(正整数，可以自由输入) ，开始人选一个正整数作
 为报数上限值M，从第一个人按顺时针方向自1开始顺序报数，
 报道M时停止报数。报M的人出列，将他的密码作为新的M值，
 从他顺时针方向上的下一个人开始从1报数，一如此下去，
 直至所有人全部出列为止。
*/
void method2(){

}

int main(){
    CycleLinkList l = initList();
    createListByTail(l, 41);
    print(l);
    printf("GAME STARTING...\n");
    josephus(l, 3);
    printf("GAME OVER.\n");
}
