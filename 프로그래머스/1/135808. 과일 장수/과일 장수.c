#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    int *ap = (int *)a;
    int *bp = (int *)b;
    
    return *bp - *ap; // dsc
}

int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    
    qsort(score, score_len, sizeof(int), compare);
    
    for(int i = 0; i < score_len; i += m){
        if(i + m - 1 >= score_len) break;
        answer += m * score[i + m - 1];
    }
    return answer;
}

/*
    큰 사과부터 m개씩 담는다.
    묶음 사과에서 가장 작은 점수 * m 씩 더해나감

*/