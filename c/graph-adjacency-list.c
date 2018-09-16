#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647 
#define OVERFLOW 0
#define ERROR -1
#define OK 1

typedef int Status;
typedef int VRType; // vertex relative type
typedef char VType; // vertex type
typedef enum {DG, DN, UDG, UDN} GraphKind;

struct VNode;

// vertex relative node
typedef struct VRNode{
    VRType data; //图：0 | 1 ; 网：权 | ∞
    struct VNode *vl; // 顶点之间的关联
    struct VRNode *next;
}VRNode, *VRList;

// vertex node
typedef struct VNode{
    VType data;
    VRList vrl; // 顶点向量的关联对象
    struct VNode *next;
}VNode, *VList;

typedef struct{
    VList vl; //顶点向量
    int vernum,arcnum; //顶点、弧的数量
    GraphKind kind; //图的类型
}LGraph;

// init list grahp
Status initLGraph(LGraph *lg){
    //init vertex list
    VNode *vnode = (VNode *)malloc(sizeof(VNode));
    if(!vnode) exit(OVERFLOW);
    vnode->next = NULL;

    //init vertex relative list
    VRNode *vrnode = (VRNode *)malloc(sizeof(VRNode));
    if(!vrnode) exit(OVERFLOW);
    vrnode->next = NULL;
    
    //类似于多对多的关联
    vrnode->vl = vnode;
    vnode->vrl = vrnode;
    lg->vl = vnode;

    //init other element
    lg->vernum = lg->arcnum = 0;

    return OK;
}

void printLGraph(LGraph lg){
    printf("\n---------------PRINT START---------------\n");
    printf("List Grahp ->\n");
    printf("vertex num: %d\n", lg.vernum);
    printf("arc num: %d\n", lg.arcnum);
    printf("kind: %d\n", lg.kind);
    printf("adjacency list:\n");
    VNode *vTarget = lg.vl;
    printf("test\n");
    while(vTarget){
        printf("Vertex: %c [ ", vTarget->data);
        VRNode *vrTarget = vTarget->vrl;
        while(vrTarget){
            printf("->%c(%d), ", vrTarget->vl->data, vrTarget->data);
            vrTarget = vrTarget->next;
        }
        printf("]\n");
        vTarget = vTarget->next;
    }
    printf("\n");
    printf("\n---------------PRINT END---------------\n");
}

//create digrahp
Status createDG(LGraph *lg){
    printf("\n---------------CREATE START---------------\n");
    printf("vertex num:\n");
    scanf("%d", &lg->vernum);
    getchar();
    printf("arc num:\n");
    scanf("%d", &lg->arcnum);
    getchar();

    //init vertex list
    printf("vertex:\n");
    VNode *first = lg->vl;
    for(int i=0; i<lg->vernum; i++){
        if(i==0){
            scanf("%c", &lg->vl->data);
            getchar();
        }else{
            VNode *vnode = (VNode *)malloc(sizeof(VNode));
            scanf("%c", &vnode->data);
            getchar();
            vnode->next = lg->vl->next;
            lg->vl->next = vnode;
            lg->vl = vnode;
        }
    }
    lg->vl = first;

    //init vertex relative list
    VNode *target1 = lg->vl;
    while(target1){
        VNode *target2 = lg->vl;
        while(target2){
            if(target1 == target2){
                target2 = target2->next;
                continue;
            }
            printf("向量%c是否指向向量%c?[1:是 0:否]:\n", target1->data, target2->data);
            char c;
            scanf("%c", &c);
            getchar();
            if(c == '1'){
                VNode *temp = (VNode *)malloc(sizeof(VNode));
                temp->data = target2->data;
                temp->next = NULL;
                if(!target1->vrl->next){
                    target1->vrl->data = 1;
                    target1->vrl->vl = temp; 
                }else{
                    VRNode *temp2 = (VRNode *)malloc(sizeof(VRNode));
                    temp2->data = 1;
                    temp2->vl = temp;
                    temp2->next = target1->vrl->next;
                    target1->vrl->next = temp2;
                    target1->vrl = temp2;
                }
            }
            target2 = target2->next;
        }
        target1 = target1->next;
    }
    printf("\n---------------START END---------------\n");
    
}

//create direct net
Status createDN(LGraph *lg){
    //TODO
}

//create undigrahp
Status createUDG(LGraph *lg){
    //TODO
}

//create undirect net
Status createUDN(LGraph *lg){
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
    initLGraph(&lg);
    createGraph(&lg);
    printLGraph(lg);

    return 0;
}
