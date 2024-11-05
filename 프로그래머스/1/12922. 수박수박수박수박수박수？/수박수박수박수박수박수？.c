#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* soo = "수";
    char* bak = "박";
    size_t len = strlen(soo);
    
    char* answer = (char*)malloc(n * len);
    
    for(int i = 0 ; i < n; i++){
        strcpy(&answer[i*len], i % 2 == 0 ? soo : bak);
    }
    
    
    return answer;
}