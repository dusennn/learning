#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OK 1

typedef int Status;

//Global variable
int *word;

//word frequency statistic
Status wf(char *c){
    int i;
    word = (int *)malloc(sizeof(int)*128);
    for(i=0; i<=128; i++){
        word[i] = 0;
    }
    i = 0;
    while(c[i]!='\0'){
        word[c[i]]++;
        i++;
    }
    return OK;
}

void printWFTable(){
    for(int i=0; i<=128; i++){
        if(word[i]){
            printf("Char:%c -> Count:%d\n", (char)i, word[i]);
        }
    }
}

int main(){
    char *c = "Nobody want to be someone else...";
    wf(c);

    printWFTable();
    return 0;
}
