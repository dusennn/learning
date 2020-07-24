#include <stdio.h>

/**
翻转单词顺序:
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，
标点符号和普通字母一样处理。例如输入字符串“I am a student.”, 则输出
“student. a am I”.
*/


void reverse(char *pStart, char *pEnd){
    /**
    pStart 开始指针
    pEnd 结束指针
    */  
    while(pStart < pEnd){
        char tmp = *pStart;
        *pStart = *pEnd;
        *pEnd = tmp;
    
        pStart++;
        pEnd--;
    }
}

int main(){
    char str[] = "I am a student.";
    
    char *pStart = str;
    char *pEnd = str;
    
    while(*pEnd != '\0'){
        pEnd++;
    }
    pEnd--;
    
    reverse(pStart, pEnd);   
    
    pStart = pEnd = str;
    while(*pEnd != '\0'){
        if(*pEnd == ' '){
            reverse(pStart, pEnd);
            pStart = pEnd = pEnd + 1;
        }else{
            pEnd ++;
        }
    }

    printf("%s \n", str);
    return 0;
}


