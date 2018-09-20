#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
#define VERTEX_MAX_NUM 20
#define INFINITY 2147483647 // max int
#define OVERFLOW 0

typedef char ElemType;
typedef char VType; //vertex type
typedef char VInfo; //vertex info
typedef int VRType; //vertex relation type
typedef int Status;

//UDG: undigrph DG:digraph UDN:undrect net DN:direct net
typedef enum {UDG, DG, UDN, DN} GraphKind;

typedef struct QueueNode{
    ElemType data;
    struct QueueNode *next;
}QueueNode, *QueuePre;
typedef struct {
    QueuePre front,rear;
}LQueue;

//VNode: vertex node
typedef struct VNode{
    VType name; // vertex name
    VInfo info; //vertex info
}VNode, *VList;
//VRNode: vertex relation node
typedef struct VRNode{
    VRType data; // 0 | 1 | weigth | ∞
    VNode *vertex;
    struct VRNode *next; 
}VRNode, *VRList;
typedef struct {
    VList vl[VERTEX_MAX_NUM];
    VRList vrl;
    int vernum,arcnum;
    GraphKind kind;
}LGrahp;

Status initQueue(LQueue *lq){
    lq->front = lq->rear = (QueueNode *)malloc(sizeof(QueueNode));
    if(!lq->front) exit(OVERFLOW);
    
    lq->front->next = NULL;
    return OK;
}

Status enQueue(LQueue *lq, ElemType e){
    QueueNode *qnode = (QueueNode *)malloc(sizeof(QueueNode));
    if(!qnode) exit(OVERFLOW);
    
    qnode->data = e;
    qnode->next = NULL;
    lq->rear->next = qnode;
    lq->rear = qnode;

    return OK;
}

Status deQueue(LQueue *lq, ElemType *e){
    if(!lq->rear) return ERROR;

    (*e) = lq->front->next->data;
    QueueNode *temp = lq->front->next;
    if(lq->front->next = lq->rear){
        lq->rear = lq->front;
    }else{
        lq->front = lq->front->next;
    }
    free(temp);

    return OK;
}

int main(){
    LQueue lq;
    initQueue(&lq);

    ElemType e;
    enQueue(&lq, 'A');
    enQueue(&lq, 'B');
    deQueue(&lq, &e);
    printf("deQueue:%c\n", e);
    deQueue(&lq, &e);
    printf("deQueue:%c\n", e);

}
