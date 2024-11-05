#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getPosSum(int x){
    int ret = 0;
    
    while(x){
        ret += x % 10;
        x /= 10;
    }
    
    return ret;
}

bool solution(int x) {
    bool answer = false;

    int posSum = getPosSum(x);
    
    if(x % posSum == 0)
        answer = true;
    
    return answer;
}