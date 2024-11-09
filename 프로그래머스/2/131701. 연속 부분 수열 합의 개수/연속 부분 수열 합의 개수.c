#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
const int MX = 1000002;
bool vis[MX];

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    
    for(int len = 0; len < elements_len; len++){
        for(int j = 0; j < elements_len; j++){
            int sum = 0;
            for(int k = j ; k <= j + len; k++)
                sum += elements[k % elements_len];
            
            if(!vis[sum]){
                vis[sum] = true;
                answer++;
            }
        }
    }
    

    return answer;
}