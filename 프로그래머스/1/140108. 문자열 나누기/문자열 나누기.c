#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int sameCnt = 0;
    int otherCnt = 0;
    char top;
    
    
    size_t len = strlen(s);
    
    for(int i = 0 ; i < len; i++){
        if(i == 0 || sameCnt == otherCnt && sameCnt > 0){
            top = s[i];
            sameCnt++;
            answer++;
            continue;
        }
        
        if(top != s[i])
            otherCnt++;
        else
            sameCnt++;
    }
        
    return answer;
}