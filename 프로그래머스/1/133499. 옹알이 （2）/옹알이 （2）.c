#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool IsPossible(const char* s){
    size_t len = strlen(s);
    char top = ' ';
    for(int i = 0 ; i < len;){
        if(s[i] == 'a' && top != 'a'){
            if(i + 2 < len && s[i+1] == 'y' && s[i+2] =='a'){
                i += 3;
                top = 'a';
                continue;
            }
        }
        else if(s[i] == 'y' && top != 'y'){
            if( i + 1 < len && s[i+1] == 'e' ){
                i += 2;
                top = 'y';
                continue;
            }
        }
        else if(s[i] == 'w' && top != 'w'){
            if( i + 2 < len && s[i+1] == 'o' && s[i+2] =='o' ){
                i += 3;
                top = 'w';
                continue;
            }
        }
        else if(s[i] == 'm' && top != 'm'){
            if(i + 1 < len && s[i+1] == 'a' ){
                i += 2;
                top = 'm';
                continue;
            }
        }
        return false;
    }
    return true;
}

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    
    for(int i = 0; i < babbling_len; i++){
        if(IsPossible(babbling[i]))
            answer++;
    }
    
    return answer;
}