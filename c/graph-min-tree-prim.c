#include <stdio.h>

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
// 连通图
typedef struct {
    VertexType vertex[MAX_VERTEX_NUM];
    AdjMatrix adj;
    int vernum, arcnum;
}MGraph;

Status createGraph(MGraph *mg){
    mg->vernum = 4;
    mg->arcnum = 5;
    mg->vertex[0] = 'A'; 
    mg->vertex[1] = 'B'; 
    mg->vertex[2] = 'C'; 
    mg->vertex[3] = 'D'; 

    mg->adj[0][0].data = INFINITY;
    mg->adj[0][1].data = 7;
    mg->adj[0][2].data = 2;
    mg->adj[0][3].data = INFINITY;

    mg->adj[1][0].data = 7;
    mg->adj[1][1].data = INFINITY;
    mg->adj[1][2].data = 3;
    mg->adj[1][3].data = INFINITY;

    mg->adj[2][0].data = 2;
    mg->adj[2][1].data = 3;
    mg->adj[2][2].data = INFINITY;
    mg->adj[2][3].data = 9;

    mg->adj[3][0].data = INFINITY;
    mg->adj[3][1].data = 4;
    mg->adj[3][2].data = 9;
    mg->adj[3][3].data = INFINITY;

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

Status prim(MGraph mg){
    if(!mg.vernum) return ERROR;

    int visited[mg.vernum];
    for(int i=0; i<mg.vernum; i++){
        visited[i] = FALSE;
    }

    visited[0] = TRUE;
    printf("Start: %c", mg.vertex[0]);

    for(int i=0; i<mg.vernum; i++){

        int min = INFINITY;
        int index = 0;
        for(int j=0; j<mg.vernum; j++){
            if(min > mg.adj[i][j].data && !visited[j]){
                min = mg.adj[i][j].data;
                index = j;
            }
        }
        
        if(min == INFINITY && index == 0) return OK;

        visited[index] = TRUE;
        printf("->(%d)%c", min, mg.vertex[index]);
        i = index;
    }
    printf("\n");

    return OK;
}

int main(){
    MGraph mg;
    createGraph(&mg);
    printGraph(mg);
    
    printf("========= PRIM =========\n");
    prim(mg);

    return 0;
}
