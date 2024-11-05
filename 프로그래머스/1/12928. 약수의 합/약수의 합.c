#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getAns(int n){
    int ret = n;
    for(int i = 1; i <= n / 2; i++){
       if(n % i == 0) 
           ret += i;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    answer = getAns(n); 
    return answer;
}