#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int answer = 0;
    size_t t_len = strlen(t);
    size_t p_len = strlen(p);
    long long target = atoll(p);    


    
    for(int i = 0; i <= t_len - p_len; i++){
        long long sub = 0;
        for( int j = i; j < i + p_len; j++){
            sub *= 10;
            sub += t[j] - '0';
        }
        
        if( sub <= target){
            answer++;
        }
            
    }
    
    return answer;
}