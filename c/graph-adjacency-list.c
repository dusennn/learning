#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647 
#define ERROR -1
#define OK 1

typedef int Status;
typedef int VRType; // vertex relative type
typedef char VType; // vertex type
typedef enum {DG, DN, UDG, UDN} AdjType;

// vertex relative node
typedef struct VRNode{
    VRType data; //图：0 | 1 ; 网：权 | ∞
    struct VRNode *next;
}VRNode, *AdjList;

// vertex node
typedef struct VNode{
    VType data;
    struct VNode *next;
}VNode, *VList;

typedef struct{
    VList vl; //顶点元素
    AdjList vrl; //邻接表
    int vernum,arcnum; //顶点、弧的数量
    AdjType type;
}LGrahp;

//create digrahp
Status createDG(LGrahp *lg){
    //TODO
}

//create direct net
Status createDN(LGrahp *lg){
    //TODO
}

//create undigrahp
Status createUDG(LGrahp *lg){
    //TODO
}

//create undirect net
Status createUDN(LGrahp *lg){
    //TODO
}

Status createGraph(LGraph *lg){
    printf("Choise Graph kind:\n1.Digraph\n2.Direct net\n3.Undigraph\n4.Undirect net\n");
    scanf("%d", &lg->kind);
    getchar();//接收多余字符
    if(lg->kind == 1){
        createDG(lg);
    }else if(lg->kind == 2){
        createDN(lg);
    }else if(lg->kind == 3){
        createUDG(lg);
    }else if(lg->kind == 4){
        createUDN(lg);
    }else{
        return ERROR;
    }
}

int main(){
    LGraph lg;
    createGraph(lg);

    return 0;
}
