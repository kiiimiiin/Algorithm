#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.

int compare(int* a, int* b){
    return *a - *b; // asc    
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    qsort(A, A_len, sizeof(int), compare);
    qsort(B, B_len, sizeof(int), compare);
    
    long long mn;

    for(int i = 0; i < A_len; i++){
        mn += A[i] * B[B_len - 1 - i];
    }

    return mn;
}

/*  
    1. 완탐: O(백만)
    2. sort후 큰값과 작은값을 곱함
    (sort는 )
*/