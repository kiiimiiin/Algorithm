#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long answer = 0;
    
    for(long long i = 1; i <= n; i++){
        if(i * i == n){
            answer = ( i + 1 ) * ( i + 1 );
            break;
        }
        if(i * i > n) {
            answer = -1;
            break;
        }
    }
    return answer;
}