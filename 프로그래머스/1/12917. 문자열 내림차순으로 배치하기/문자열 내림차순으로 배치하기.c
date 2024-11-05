#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


char* solution(const char* s) {

    size_t len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);
    
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(answer[i] < answer[j]){
                char tmp = answer[i];
                answer[i] = answer[j];
                answer[j] = tmp;
            }
        }
    }
    return answer;
}