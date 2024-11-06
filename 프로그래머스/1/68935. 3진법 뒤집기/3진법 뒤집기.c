#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    long long val = 0;
    while(n){
        val *= 10;
        val += n % 3;
        n /= 3;
    }
    
    
    int coef = 1;
    while(val){
        answer += coef * (val % 10);
        printf("%d ", answer);
        val /= 10;
        coef *= 3;
    }
    
    return answer;
}

/*
    3 | 45 .. 0
    3 | 15 .. 0
    3 | 5 .. 2
        1 

*/