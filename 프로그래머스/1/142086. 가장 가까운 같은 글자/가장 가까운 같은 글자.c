#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    
    int* answer = (int*)malloc(10002 * sizeof(int));
    int vis[32];
    memset(vis, -1, sizeof(vis));
    size_t len = strlen(s);
    
    for(int i = 0 ; i < len; i++){
        if(vis[s[i] - 'a'] == -1)
            answer[i] = -1;
        else
            answer[i] = i - vis[s[i] - 'a'];

        vis[s[i] - 'a'] = i;
    }
    
    return answer;
}

/*
    a~z : 0~30
*/