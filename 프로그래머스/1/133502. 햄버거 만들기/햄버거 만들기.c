#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MX = 1000005;
int stack[MX];
int pos = 0;

void push(int x){
    stack[pos++] = x;
}

void pop(){
    pos--;
}

int top(){
    return stack[pos - 1];
}

bool isEmpty(){
    return pos == 0;
}

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int step = 0;
    
    for(int i = 0; i < ingredient_len; i++){
        push(ingredient[i]);
        
        if(top() == 1 && pos - 4 >= 0){
            if(stack[pos-4] == 1 && stack[pos-3] == 2 && stack[pos-2] == 3){
                pop();
                pop();
                pop();
                pop();
                answer++;
            }
        }
    }
    return answer;
}