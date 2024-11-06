#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);
    
    int idx = 0;
    for(int i = 0 ; i < len; i++){
        if(answer[i] == ' '){
            idx = 0;
            continue;
        }
        
        answer[i] = idx % 2 == 0 ? toupper(answer[i]) : tolower(answer[i]);
        idx++;
        
    } 
    
    
    return answer;
}