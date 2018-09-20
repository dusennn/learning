#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 20
#define ERROR -1
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef int VRType;
typedef char VType;
typedef struct AdjMatNode{
    VRType data;
}AdjMatNode, AdjMat[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
typedef struct {
    VType data[MAX_VERTEX_SIZE];
    AdjMat adj;
    int vernum,arcnum;
}MGraph;

void printMatrix(MGraph g){
    printf("\nGraph Matrix:\n");
    for(int i=0; i<g.vernum; i++){
        for(int j=0; j<g.vernum; j++){
            printf("%d  ", g.adj[i][j].data);
        }
        printf("\n");
    }
}

//this is undigraph
Status createMGraph(MGraph *g){
    printf("Please input:\n");
    printf("VerNum:");
    scanf("%d", &g->vernum);
    getchar();
    if(g->vernum > MAX_VERTEX_SIZE) return ERROR;
    printf("ArcNum:");
    scanf("%d", &g->arcnum);
    getchar();

    printf("Vertex:\n");
    for(int i=0; i<g->vernum; i++){
        scanf("%c", &g->data[i]);
        getchar();
    }
    
    printf("Vertex relation:\n");
    for(int i=0; i<g->vernum; i++){
        for(int j=0; j<g->vernum; j++){
            if(i == j){
                g->adj[i][j].data = 0;
                continue;
            }
            printf("%c connection %c ?[1:Yes 0:No]\n", g->data[i], g->data[j]);
            scanf("%d", &g->adj[i][j].data);
            getchar();
        }
    }
    return OK;
}

//depth_first search
Status depthFristSearch(MGraph g){
    int visited[g.vernum];
    for(int i=0; i<g.vernum; i++){
        visited[i] = FALSE;
    }
    visited[0] = TRUE; //begian point
    printf("%c->", g.data[0]);
    int i,j;
    i = 0;
    while(i<g.vernum){
        j = 0;
        while(j<g.vernum){
            if(g.adj[i][j].data && !visited[j]){
                visited[j] = TRUE;
                printf("%c->", g.data[j]);
                break;
            }
            if(j == g.vernum-1){
                printf("%c->", g.data[i-1]);
                i-=2;
                break;
            }
            j++;
        }
        i++;
        int flag = 1;
        for(int n=0; n<g.vernum; n++){
            if(!visited[n]) flag = 0;
        }
        if(flag) break;

    }
    printf("\n");
    return OK;
}

int main(){
    MGraph g;
    createMGraph(&g);
    printMatrix(g);
    
    depthFristSearch(g);
    return 0;
}
