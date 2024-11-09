#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

const int MX = 1000005;
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

    
bool solution(const char* s) {
    bool answer = true;
    size_t len = strlen(s);
    for(int i = 0 ; i < len; i++){
        if(s[i] == '(')
            push('(');
        else{
            if(!IsEmpty())
                pop();
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(!IsEmpty())
        answer = false;
    
    return answer;
}

/*
    열린괄호는 push
    닫힌괄호
        -스택존재시 pop
        -스택존재x false
    문자열 순회끝나고
    스택존재시 false
    
*/