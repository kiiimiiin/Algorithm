#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s, const char* skip, int index) {
    size_t len = strlen(s);
    size_t skip_len = strlen(skip);
    char* answer = (char*)malloc(len + 1);
    char* alpha  = (char*)malloc(27);
    bool skipped[150] = {};
    strcpy(answer, s);
    
    for(int  i = 0 ; i < skip_len; i++)
        skipped[skip[i]] = true;
    
    int idx = 0;
    for(int i = 0 ; i < 26; i++){
        if(skipped['a' + i]) continue;
        alpha[idx] = 'a' + i;
        idx++;
    }
    alpha[idx] = '\0';

    
    for(int i = 0 ; i < len; i++){
        int st;
        
        for(st = 0; st < idx; st++){
            if(alpha[st] == answer[i])
                break;
        }
        
        answer[i] = alpha[(st+index)%idx];
    }
     
    return answer;

}

// 알파벳개수 26개


/*
    제외된 알파벳 리스트를 구하고 해당 리스트를 기준으로 index 넘기기
*/