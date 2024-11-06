#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(5000 * sizeof(int));
    bool vis[202] = {};
    int idx = 0;
    
    for(int i = 0 ; i < numbers_len; i++){
        for(int j = i + 1; j < numbers_len; j++){
            if(vis[numbers[i] + numbers[j]]) continue;
            vis[numbers[i] + numbers[j]] = true;
            printf("%d ", numbers[i] + numbers[j]);
            answer[idx++] = numbers[i] + numbers[j];
        }
    }
    
    for(int i = 0; i < idx; i++){
        for(int j = i + 1; j < idx; j++){
            if( answer[i] > answer[j]){
                int tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }
    
    return answer;
}

/*
    전부다 리스트에 넣고 sort
    vis의 인덱스 정보는 200까지여야함 0~100까지 두 수의 합이므로
    ans인덱스 정보는 100C2의 합 
*/