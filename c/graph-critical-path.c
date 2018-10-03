#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW 0
#define VERTEX_MAX_NUM 20

typedef int Status;
typedef char VertexName;
typedef char VertexType;
typedef int ElemType;

typedef struct ArcNode{
    int adjvex;
    int weight;
    struct ArcNode *next;
}ArcNode, *ArcList;
typedef struct VNode{
    VertexName name;
    VertexType type; //始点:0 终点:1 其它:2
    ArcList arc;
}VNode, VList[VERTEX_MAX_NUM];
typedef struct{
    VList adj;
    int vernum,arcnum;
}LGraph;

//etv: 事件最早发生时间
//ltv: 事件最晚发生时间
//ete: 活动最早开始时间
//lte: 活动最晚发生时间
int *etv, *ltv, *ete, *lte;

//create activity on edge network
Status createAOE(LGraph *lg){
    lg->vernum = 6;
    lg->arcnum = 7;

    lg->adj[0].name = 'A';
    lg->adj[1].name = 'B';
    lg->adj[2].name = 'C';
    lg->adj[3].name = 'D';
    lg->adj[4].name = 'E';
    lg->adj[5].name = 'F';

    lg->adj[0].type = 0;
    lg->adj[1].type = 2;
    lg->adj[2].type = 2;
    lg->adj[3].type = 2;
    lg->adj[4].type = 2;
    lg->adj[5].type = 1;

    ArcNode *node00 = (ArcNode *)malloc(sizeof(ArcNode));
    node00->adjvex = 1;
    node00->weight = 3;
    ArcNode *node01 = (ArcNode *)malloc(sizeof(ArcNode));
    node01->adjvex = 2;
    node01->weight = 2;
    node00->next = node01;
    node01->next = NULL;
    lg->adj[0].arc = node00;

    ArcNode *node10 = (ArcNode *)malloc(sizeof(ArcNode));
    node10->adjvex = 3;
    node10->weight = 2;
    ArcNode *node11 = (ArcNode *)malloc(sizeof(ArcNode));
    node11->adjvex = 4;
    node11->weight = 1;
    node10->next = node11;
    node11->next = NULL;
    lg->adj[1].arc = node10;

    ArcNode *node20 = (ArcNode *)malloc(sizeof(ArcNode));
    node20->adjvex = 5;
    node20->weight = 4;
    node20->next = NULL;
    lg->adj[2].arc = node20;

    ArcNode *node30 = (ArcNode *)malloc(sizeof(ArcNode));
    node30->adjvex = 5;
    node30->weight = 5;
    node30->next = NULL;
    lg->adj[3].arc = node30;

    ArcNode *node40 = (ArcNode *)malloc(sizeof(ArcNode));
    node40->adjvex = 5;
    node40->weight = 3;
    node40->next = NULL;
    lg->adj[4].arc = node40;

    lg->adj[5].arc = NULL;

    return OK;
}

void printAOE(LGraph lg){
    printf("========== Activity On Edge Network: ==========\n");
    printf("vernum: %d\n", lg.vernum);
    printf("arcnum: %d\n", lg.arcnum);
    printf("vertex: ");
    for(int i=0; i<lg.vernum; i++){
        printf("%c ", lg.adj[i].name);
    }
    printf("\n");
    printf("adj list:\n");
    for(int i=0; i<lg.vernum; i++){
        printf("\t%d %c [ ", lg.adj[i].type, lg.adj[i].name);
        ArcNode *target = lg.adj[i].arc;
        while(target){
            printf("%c(%d), ", lg.adj[target->adjvex].name, target->weight);
            target = target->next;
        }
        printf("]\n");
    }
}

//criticla path
Status cp(LGraph lg){

}

int main(){
    LGraph lg;
    createAOE(&lg);
    printAOE(lg);
    
    return 0;
}
