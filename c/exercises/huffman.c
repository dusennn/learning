#include <stdio.h>

#define ERROR -1
#define OK 1

typedef int Status;

typedef struct{
    char word;
    int count;
}Words;

Words arr[26];

//rwf: relative word frequency
Status rwf(char *c){
    int i, j; 
    while(c[i]!='\0'){
        j = c[i] - 65; // ASCII：A->65
        if(!arr[j].word){
            arr[j].word = c[i];
            arr[j].count = 1;
        }else{
            arr[j].count++;
        }
        i++;
    }
    return OK;
}

void print(){
    int i = 0;
    while(arr[i].word){
        printf("Word:%c, Count:%d\n", arr[i].word, arr[i].count);
        i++;
    }
}

int main(){
    char *c = "ABCADE"; 
    rwf(c);

    print();
}
