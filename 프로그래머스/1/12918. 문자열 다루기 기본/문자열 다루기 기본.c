#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    size_t len = strlen(s); // 문자열 길이를 구하기 위해 strlen 사용
    
    if(len == 4 || len == 6){
        for(int i = 0; i < len; i++){
            if(isalpha(s[i])){
                answer = false;
                break;    
            } 
        }
    } else
        answer = false;
    
    return answer;
}
