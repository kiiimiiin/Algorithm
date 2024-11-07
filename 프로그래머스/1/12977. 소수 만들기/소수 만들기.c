#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool IsPrime(int num){
    for(int i = 2; i <= num - 1; i++){
        if(num % i == 0) return false;
    }
    
    return true;
}
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    
    for(int i = 0 ; i < nums_len; i++){
        for(int j = i + 1; j < nums_len; j++){
            for(int k = j + 1; k < nums_len; k++){
                if(IsPrime(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }
    
    return answer;
}