#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    size_t len = 1;
    for(int i = 1; i < food_len; i++){
        food[i] /= 2; // 1 1 2 3
        len += 2 * food[i];
    }
    
    char* answer = (char*)malloc(len + 1);
    
    int idx = 1;
    for(int i = 0; i < len / 2; ){
        while(food[idx] && idx < food_len){
            answer[i] = answer[len-1 - i] = idx + '0';
            food[idx]--;
            i++;
        }
        idx++;
    }
    answer[len/2] = '0';
    answer[len] = '\0';
    
    
    return answer;
}