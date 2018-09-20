#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePrt;

typedef struct{
    QueuePrt front, rear;
}LinkQueue;

Status initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePrt)malloc(sizeof(ElemType));
    if(!q->front) exit(0);

    q->front->next = NULL;

    return OK;
}

int queueLength(LinkQueue q){
    int len=0;
    QueuePrt target = q.front->next;
    while(target){
        len++;
        target = target->next;
    }
    return len;
}

//insert
Status enQueue(LinkQueue *q, ElemType e){
    QNode *n = (QNode *)malloc(sizeof(QNode));
    if(!n) exit(0);

    n->data = e;
    n->next = NULL;
    q->rear->next = n;
    q->rear = n;

    return OK;
}

//delete
Status deQueue(LinkQueue *q, ElemType *e){
    if(!q->front) return ERROR;

    QNode *target = q->front->next;
    int len = queueLength(*q);
    if(len == 1){
        q->rear = q->front;
        q->front->next = NULL;
        free(target);
    }else{
        *e = target->data;
        q->front->next = target->next;
        free(target);
    }
    return OK;   
}

Status destoryQueue(LinkQueue *q){
    QNode *target = q->front;
    while(q->front){
        q->front = target->next;
        free(target);
    }
    q->rear = q->front = NULL;
    return OK;
}

int main(){
    LinkQueue q;
    ElemType e;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 99);
    enQueue(&q, 9);
    int len = queueLength(q);
    printf("len:%d\n", len);

    deQueue(&q, &e);
    len = queueLength(q);
    printf("del:%d\n", e);
    printf("len:%d\n", len);
    
    //destoryQueue(&q);
    //len = queueLength(q);
    //printf("len:%d\n", len);

}
