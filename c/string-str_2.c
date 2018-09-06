#include <stdio.h>

int length(char *str){
    int i = 0;
    while(str[i++] != '\0');

    return i-1;
}

void bf(){
    char *str1 = "helloworld!";
    char *str2 = "wor";
    int len1, len2, flag;
    len1 = length(str1);
    len2 = length(str2);
    flag = 0;
    for(int i=0; i<len1; i++){
        if(str1[i] == str2[0]){
            for(int j=1; j<len2; j++){
                if(str1[i+j] == str2[j]){
                    flag = 1;
                }else{
                    flag = 0;
                }
            }
        }
    }

    if(flag == 1){
        printf("str1 include str2.\n");
    }else{
        printf("str1 exclude str2.\n");
    }
}
int main(){
    bf();
}
