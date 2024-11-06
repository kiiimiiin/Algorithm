#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    size_t len = strlen(s);
    
    for(int i = 0 ; i < len;){
        answer *= 10;
        if(isdigit(s[i])){
            answer += s[i] - '0';
            i++;
        }
        else if(isalpha(s[i])){
            if(s[i] == 'z'){
                answer += 0;
                i += 4;
            }else if(s[i] == 'o'){
                answer += 1;
                i += 3;
            }else if(s[i] == 't' && s[i+1] == 'w'){
                answer += 2;
                i += 3;
            }else if(s[i] == 't' && s[i+1] == 'h'){
                answer += 3;
                i += 5;
            }else if(s[i] == 'f' && s[i+1] == 'o'){
                answer += 4;
                i += 4;
            }else if(s[i] == 'f' && s[i+1] == 'i'){
                answer += 5;
                i += 4;
            }else if(s[i] == 's' && s[i+1] == 'i'){
                answer += 6;
                i += 3;
            }else if(s[i] == 's' && s[i+1] == 'e'){
                answer += 7;
                i += 5;
            }else if(s[i] == 'e'){
                answer += 8;
                i += 5;
            }else if(s[i] == 'n'){
                answer += 9;
                i += 4;
            }
        }
    }
    
    return answer;
}