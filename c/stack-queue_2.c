#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;
typedef char ElemType;

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePre;

typedef struct{
    QueuePre front, rear;
}LinkQueue;

Status initQueue(LinkQueue *q){
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    if(!q->front) exit(0);

    q->front->next = NULL;
    return OK;
}

int queueLength(LinkQueue q){
    QNode *target = q.front->next;
    int len = 0;
    while(target){
        len++;
        target = target->next;
    }
    return len;
}

Status enQueue(LinkQueue *q, ElemType e){
   QNode *temp = (QNode *)malloc(sizeof(QNode));
   if(!temp) exit(0);

   temp->data = e;
   temp->next = NULL;
   q->rear->next = temp;
   q->rear = temp;

   return OK;
}

Status deQueue(LinkQueue *q, ElemType *e){
    if(!q->front) return ERROR;
   
    QNode *target = q->front->next;
    int len = queueLength(*q);
    if(len==1){
        *e = target->data;
        q->front = q->rear;
        q->front->next = NULL;
        free(target);
    }else{
        *e = target->data;
        q->front->next = target->next;
        free(target);
    }

    return OK;
}

//input -> output
void pratice(){
    LinkQueue q;
    ElemType e;
    initQueue(&q);

    printf("请输入：");
    char c;
    while(c != '\n'){
        c = getchar();
        enQueue(&q, c);
    }
    int len = queueLength(q);
    for(int i=0; i<len; i++){
        deQueue(&q, &c);
        printf("%c", c);
    }
}

int main(){
    pratice();
}
