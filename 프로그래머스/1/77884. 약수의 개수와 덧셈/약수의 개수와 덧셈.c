#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getCnt(int n){
    
    int ret = 1;
    
    if(n == 1)
        return ret;
    
    for(int i = 1; i <= n / 2; i++){
        if( n % i == 0) ret++; 
    }
    
    return ret;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++){
        int cnt = getCnt(i);
        if(cnt % 2 == 0) answer += i;
        else answer -= i;
    }
    

    return answer;
}