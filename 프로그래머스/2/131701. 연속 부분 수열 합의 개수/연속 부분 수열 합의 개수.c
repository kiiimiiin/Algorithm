#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
const int MX = 1000002;
bool vis[MX];

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    
    for(int i = 0; i < elements_len; i++){
        int sum = 0;
        for(int j = i; j < i + elements_len; j++){
            sum += elements[j % elements_len];
            if(!vis[sum]){
                vis[sum] = true;
                answer++;
            }
        }
    }
    

    return answer;
}