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

typedef struct ArcNode{
    int adjvex; //该弧所指向的顶点的位置
    VRType data; // 0 | 1 | weigth | ∞
    struct ArcNode *next; 
}ArcNode, *ArcList;

//VNode: vertex node
typedef struct VNode{
    VType name; // vertex name
    ArcList arc;
}VNode, AdjList[VERTEX_MAX_NUM];

typedef struct {
    AdjList adj;
    int vernum,arcnum;
    GraphKind kind;
}LGraph;

Status createGraph(LGraph *lg){
    printf("vernum:\n");
    scanf("%d", &lg->vernum);
    getchar();
    if(lg->vernum > VERTEX_MAX_NUM) return ERROR;
    printf("arcnum:\n");
    scanf("%d", &lg->arcnum);
    getchar();

    printf("vertex:\n");
    for(int i=0; i<lg->vernum; i++){
        scanf("%c", &lg->adj[i].name);
        getchar();
    }

    char c;
    for(int i=0; i<lg->vernum; i++){
        for(int j=0; j<lg->vernum; j++){
            if(i == j) continue;
            printf("%c connection %c?[Y/N]\n", lg->adj[i].name, lg->adj[j].name);
            scanf("%c", &c);
            getchar();
            if(c == 'Y' || c == 'y'){
                ArcNode *anode = (ArcNode *)malloc(sizeof(ArcNode));
                anode->adjvex = j;
                anode->data = 1;
                anode->next = NULL;
                if(!lg->adj[i].arc){
                    lg->adj[i].arc = anode;
                }else{
                    ArcNode *target = lg->adj[i].arc;
                    while(target->next){
                        target = target->next;
                    }
                    target->next = anode;
                }
            }
        }
    }   
}

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
    LGraph lg;
    createGraph(&lg);
}
