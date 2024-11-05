#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp; 

    return ;
}

long long solution(int a, int b) {
    long long answer = 0;
    // b is greater than a 
    
    if(a > b) swap(&a, &b);
    
    for(int i = a; i <= b; i++)
        answer += i;

    return answer;
}