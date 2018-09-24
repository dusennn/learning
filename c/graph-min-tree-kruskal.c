#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1
#define MAX_VERTEX_NUM 20
#define INFINITY 65535

typedef int Status;
typedef int ArcType;
typedef char VertexType;

typedef struct ArcCell{
    ArcType data;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//边集数组
typedef struct{
    int begin,end,weight;
}Edges[MAX_VERTEX_NUM * MAX_VERTEX_NUM];
// 连通图
typedef struct {
    VertexType vertex[MAX_VERTEX_NUM];
    AdjMatrix adj;
    int vernum, arcnum;
}MGraph;

Status createGraph(MGraph *mg){
    mg->vernum = 5;
    mg->arcnum = 7;
    mg->vertex[0] = 'A'; 
    mg->vertex[1] = 'B'; 
    mg->vertex[2] = 'C'; 
    mg->vertex[3] = 'D'; 
    mg->vertex[4] = 'E'; 

    mg->adj[0][0].data = INFINITY;
    mg->adj[0][1].data = 3;
    mg->adj[0][2].data = 7;
    mg->adj[0][3].data = INFINITY;
    mg->adj[0][4].data = INFINITY;

    mg->adj[1][0].data = 3;
    mg->adj[1][1].data = INFINITY;
    mg->adj[1][2].data = 9;
    mg->adj[1][3].data = 5;
    mg->adj[1][4].data = 2;

    mg->adj[2][0].data = 7; 
    mg->adj[2][1].data = 9;
    mg->adj[2][2].data = INFINITY;
    mg->adj[2][3].data = INFINITY;
    mg->adj[2][4].data = 6;

    mg->adj[3][0].data = INFINITY; 
    mg->adj[3][1].data = 5;
    mg->adj[3][2].data = INFINITY;
    mg->adj[3][3].data = INFINITY;
    mg->adj[3][4].data = 6;

    mg->adj[4][0].data = INFINITY;
    mg->adj[4][1].data = 2;
    mg->adj[4][2].data = 3;
    mg->adj[4][3].data = 6; 
    mg->adj[4][4].data = INFINITY;

    return OK;
}

void printGraph(MGraph mg){
    printf("Metrix Graph:\n");
    printf("vernum: %d\n", mg.vernum);
    printf("varcnum: %d\n", mg.arcnum);
    printf("metrix:\n");

    for(int i=0; i<mg.vernum; i++){
        for(int j=0; j<mg.vernum; j++){
            if(mg.adj[i][j].data == INFINITY){
                printf("∞ ");
            }else{
                printf("%d ", mg.adj[i][j]);
            }
        }
        printf("\n");
    }
}

Status createEdges(MGraph mg, Edges eg){
    int index = 0;
    for(int i=0; i<mg.vernum; i++){
        for(int j=i+1; j<mg.vernum; j++){
            int weight = mg.adj[i][j].data;
            if(weight != INFINITY){
                eg[index].begin = i;
                eg[index].end = j;
                eg[index].weight = weight;
                index++;
            }
        }
    }
}

Status sortedEdges(Edges eg, int len){
    int begin, end, weight;
    for(int i=0; i<len; i++){
        for(int j=i; j<len; j++){
            if(eg[i].weight > eg[j].weight){
                begin = eg[i].begin;
                end = eg[i].end;
                weight = eg[i].weight;
                eg[i].begin = eg[j].begin;
                eg[i].end = eg[j].end;
                eg[i].weight = eg[j].weight;
                eg[j].begin = begin;
                eg[j].end = end;
                eg[j].weight = weight;
            }
        }
    }

    return OK;
}

Status printEdges(Edges eg, int len){
    printf("========== Edges: ==========\n");
    for(int i=0; i<len; i++){
        printf("Index:%d, Begin:%d, End:%d, Weight:%d\n", i, eg[i].begin, eg[i].end, eg[i].weight);
    }
}

//克鲁斯卡尔算法
Status kurskal(MGraph mg){
    
    return OK;
}

int main(){
    MGraph mg;
    createGraph(&mg);
    printGraph(mg);
    Edges eg;
    createEdges(mg, eg);
    printEdges(eg, mg.arcnum);
    sortedEdges(eg, mg.arcnum);
    printEdges(eg, mg.arcnum);

    printf("========= Kruskal =========\n");

    return 0;
}
