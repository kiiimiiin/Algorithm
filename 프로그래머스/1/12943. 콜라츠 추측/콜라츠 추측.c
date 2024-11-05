#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    long long tmp = num;
    
    for(int t = 0 ; t < 500; t++){
        if(tmp == 1){
            return t;
        }
        
        if(tmp % 2 == 0)
            tmp /= 2;
        else
            tmp = tmp * 3 + 1; 
    }
    
    return -1;
}