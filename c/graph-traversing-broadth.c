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

//VRNode: vertex relation node
typedef struct VRNode{
    int adjvex; //该弧所指向的顶点的位置
    VRType data; // 0 | 1 | weigth | ∞
    struct VRNode *next; 
}VRNode, *VRList;
//VNode: vertex node
typedef struct VNode{
    VType name; // vertex name
    VRList vrl;
}VNode, *VList;

typedef struct {
    VNode *vertex[VERTEX_MAX_NUM];
    VList vl;
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
        scanf("%c", lg->vertex[i]);
    }
    char c;
    for(int i=0; i<lg->vernum; i++){
        for(int j=0; j<lg->vernum; j++){
            if(i == j) continue;
            printf("%c connection %c?[Y/N]\n", lg->vertex[i]->name, lg->vertex[j]->name);
            scanf("%c", &c);
            if(c == 'Y' || c == 'y'){
                if(!lg->vl){
                    VNode *vnode = (VNode *)malloc(sizeof(VNode));
                    vnode->name = lg->vertex[i]->name;
                    VRNode *vrnode = (VRNode *)malloc(sizeof(VRNode));
                    vrnode->adjvex = j;
                    vrnode->data = 1;
                    vrnode->next = NULL;

                    vnode->vrl = vrnode;
                    lg->vl = vnode;
                }else{
                    
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

    ElemType e;
    enQueue(&lq, 'A');
    enQueue(&lq, 'B');
    deQueue(&lq, &e);
    printf("deQueue:%c\n", e);
    deQueue(&lq, &e);
    printf("deQueue:%c\n", e);

    LGraph lg;
    createGraph(&lg);

}
