#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MX  = 100002;
int pos = 0;
int stack[MX];

void push(int x){
    stack[pos++] = x;
}

void pop(){
    pos--;
}

int top(){
    return stack[pos-1];
}

bool IsEmpty(){
    return pos <= 0;
}



// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(prices_len * sizeof(int));
    
    for(int i = 0; i < prices_len; i++){
        answer[i] = prices_len - 1 - i;
        
        while(!IsEmpty() && prices[top()] > prices[i]){
            answer[top()] = i - top();
            pop();
        }
        
        push(i);
    }
    return answer;
}

/*
    인덱스를 스택으로
    top 인덱스의 가격보다 cur의 가격이 낮으면 top이 cur보다 커질때까지 pop
    
*/