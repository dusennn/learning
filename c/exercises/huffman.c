#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128
#define ERROR -1
#define OK 1

typedef int Status;

//huffman tree node
typedef struct HTNode{
    char data;
    int weight;
    struct HuffmanNode *lchild, *rchild;
}HTNode, *HTree;

//huffman list node
typedef struct HLNode{
    HTree tnode;
    int length;
    struct HLNode *next;
}HLNode, *HList;

//word frequency statistic
int* wf(char *c){
    int i;
    int *word = (int *)malloc(sizeof(int)*128);
    if(!word) exit(0);

    for(i=0; i<=128; i++){
        word[i] = 0;
    }
    i = 0;
    while(c[i]!='\0'){
        word[c[i]]++;
        i++;
    }
    return word;
}

void printWFTable(int *word){
    for(int i=0; i<=128; i++){
        if(word[i]){
            printf("Char:%c -> Count:%d\n", (char)i, word[i]);
        }
    }
}

//构建一个集合，存放二叉树，按照词频从低到高排列
HList buildTreeList(int *word){
    HList hl = (HLNode *)malloc(sizeof(HLNode));
    if(!hl) exit(0);
    hl->tnode = NULL;
    hl->next = NULL;
    hl->length = 0;

    for(int i=0; i<=128; i++){
        if(word[i]){
            HTree tn = (HTNode *)malloc(sizeof(HTNode));
            tn->lchild = tn->rchild = NULL;
            tn->data = (char)i;
            tn->weight = word[i];

            if(hl->length == 0){
                hl->tnode = tn;
                hl->tnode->weight = word[i];
            }
            else{
                // 寻找合适位置用于插入节点
                HLNode *temp = (HLNode *)malloc(sizeof(HLNode));
                temp->tnode = tn;
                if(hl->tnode->weight >= word[i]){
                    temp->next = hl;
                    hl = temp;
                }else{
                    HLNode *first = hl;
                    while(hl->next){
                        if( hl->next->tnode->weight < word[i]){
                            hl = hl->next;
                        }else{
                            break;
                        }
                    }
                    temp->next = hl->next;
                    hl->next = temp;
                    hl = first;
                }
            }
            hl->length++;
        }
    }
    return hl;
}

void printTreeList(HList hl){
    HLNode *target = hl;
    int count = 0;
    while(target){
        printf("Point:%d, TreeNode:%c\n", count, target->tnode->data);
        target = target->next;
        count++;
    }
}

//构建Huffman树
Status buildHuffmanTree(HList hl, int *word){
    while(hl->next){
        HTNode *newTree = (HTNode *)malloc(sizeof(HTNode));
        if(!newTree) exit(0);

        
    }
    return OK;
}

int main(){
    // 词频统计
    int *word;
    char *c = "wwwwwwwwwww Nobody want to be someone else...";
    word = wf(c);
    printWFTable(word);

    //构建二叉树集合
    HList hl;
    hl = buildTreeList(word);
    printTreeList(hl);

    //构建Huffman树
//    buildHuffmanTree(hl, word);

    return 0;
}
