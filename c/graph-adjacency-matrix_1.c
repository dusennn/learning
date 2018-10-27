#include <stdio.h>

#define MAX_VERTEX_NUM 20

typedef char VertexType;
typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
}MGraph;

void init(MGraph *g){
	g->vexnum = 4;
	g->arcnum = 4;
	g->vexs[0] = 'A'; 
	g->vexs[1] = 'B';
	g->vexs[2] = 'C';
	g->vexs[3] = 'D';
	for(int i=0; i<g->vexnum; i++){
		for(int j=0; j<g->vexnum; j++){
			g->arcs[i][j] = 0;
		}
	}
	g->arcs[0][1] = g->arcs[0][2] = g->arcs[0][3] = g->arcs[1][3] = g->arcs[2][3] = 1;
}

void print(MGraph g){
	printf("===========MGraph:===========\n");
	for(int i=0; i<g.vexnum; i++){
		for(int j=0; j<g.vexnum; j++){
			printf("%d\t", g.arcs[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//判断图G中是否含有一个漏（即入度为n-1,出度为0的顶点）
int isLeak(MGraph *g){
	int out = 0;
	int in = 0;
	for(int i=0; i<g->vexnum; i++){
		for(int j=0; j<g->vexnum; j++){
			out += g->arcs[i][j];
		}
		if(out == 0){
			for(int m=0; m<g->vexnum; m++){
				in += g->arcs[m][i];
			}
			if(in == (g->vexnum-1)){
				return 1;
			}
			in = 0;
		}
		out = 0;
	}
	return 0;
}

int main(){
	MGraph g;
	init(&g);
	print(g);
	
	int result = isLeak(&g);
	printf("Result:%d\n", result);
}
