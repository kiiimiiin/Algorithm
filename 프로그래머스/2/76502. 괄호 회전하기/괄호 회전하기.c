#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MX = 1004;
int pos = 0; 
char stack[MX];

void push(char c){
    stack[pos++] = c;
}

void pop(){
    pos--;
}

char top(){
    return stack[pos - 1];
}

bool IsEmpty(){
    return pos <= 0;
}

int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    char* tmp = (char *)malloc(len + 1);
    int cnt = len;
    strcpy(tmp, s);
    
    while(cnt--){
        while(!IsEmpty())
                pop();
        
        // 1. rotate
        char first = tmp[0];
        bool notflag = false;
        for(int i = 1 ; i < len; i++)
            tmp[i-1] = tmp[i];
        tmp[len - 1] = first;
        
        // 2. find correct string
        for(int i = 0 ; i < len; i++){
            
            if( tmp[i] == '[' || tmp[i] == '(' || tmp[i] == '{')
                push(tmp[i]);
            else{
                if(IsEmpty()){
                    notflag = true;
                    break;
                }
                if(tmp[i] == ']' && top() == '[' || tmp[i] == '}' && top() == '{' 
                   || tmp[i] == ')' && top() == '('){
                    pop();
                } else {
                    notflag = true;
                    break;      
                }
            }
        }

        if(!IsEmpty())
            notflag = true;
        
        if(!notflag)
            answer++;
    }
    

    
    return answer;
}