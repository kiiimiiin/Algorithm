#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getMin(int a, int b){
    return a > b ? b : a;
}

char* solution(const char* X, const char* Y) {
    
    size_t xlen = strlen(X);
    size_t ylen = strlen(Y);
    int xCnt[10] = {};
    int yCnt[10] = {};
    int sameCnt = 0;
    
    for(int i = 0; i < xlen; i++)
        xCnt[X[i] - '0']++;
    
    for(int i = 0; i < ylen; i++)
        yCnt[Y[i] - '0']++;  
    
    
    for(int i = 0; i <= 9; i++){
        if(xCnt[i] && yCnt[i]){
            sameCnt += getMin(xCnt[i], yCnt[i]);
        }
    }
    
    char* answer;
    
    if(sameCnt == 0){
        answer = (char*)malloc(3);
        answer[0] = '-';
        answer[1] = '1';
        answer[2] = '\0';
    }else{
        answer = (char*)malloc(sameCnt + 1);
        int idx = 0;
        for(int j = 9; j >= 0; j--){
            if(xCnt[j] && yCnt[j]){
            int tmp = getMin(xCnt[j], yCnt[j]);
            while(tmp--)
                answer[idx++] = j + '0';
            }
        }
        
        if(answer[0] == '0')
            answer[1] = '\0';
        else
            answer[sameCnt] = '\0';
    }  
    
    return answer;
}

/*
    X의 수에대한 cnt
    Y의 수에대한 cnt
    
    0부터 9에대해 x cnt == y cnt면 해당 수는 cnt만큼 짝궁에 활용가능
    
    최대 짝수 3백만
*/