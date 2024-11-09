#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc( (right - left + 1) * sizeof(int));
    int idx = 0;
    for(long long pos = left; pos <= right; pos++){
        int r = pos / n;
        int c = pos % n;
        int val = r + 1;
        if(c > r) val += c - r;
        answer[idx++] = val;   
    }
    
    return answer;
}

/*
    123 012
    223 345
    333 678 
    
    r = pos / n 
    c = pos % n
    ex) pos = 2
    r = 0 c = 2 -> 3
    r = 0 c = 1 -> 2
    r = 0 c = 0 -> 1
    
    pos = 5
    r = 1 c = 2 -> 3 
    r = 1 c = 1 -> 2
    r = 1 c = 0 -> 2
    
    012345678
    123223333
    
*/