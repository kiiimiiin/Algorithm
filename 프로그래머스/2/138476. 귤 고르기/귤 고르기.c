#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(int*a, int*b){
    return *b - *a;
}
// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int category_cnt[100002];
    
    qsort(tangerine, tangerine_len, sizeof(int), compare);
    
    int idx = 0;
    int top;
    for(int i = 0; i < tangerine_len; i++){
        if(i == 0){
            top = tangerine[i];
            category_cnt[idx] = 1;
            continue;
        }
        if(top == tangerine[i]){
            category_cnt[idx]++;
        }else{
            top = tangerine[i];
            category_cnt[++idx] = 1;
        }
    }
    
    qsort(category_cnt, idx + 1, sizeof(int), compare);
    
    for(int i = 0 ; i <= idx; i++){
        if(k <= 0) break;
        k -= category_cnt[i];
        answer++;
    }
    
    
    return answer;
}

/*
    갯수가 많은 종류수에 대해서 k에서 빼야함

*/