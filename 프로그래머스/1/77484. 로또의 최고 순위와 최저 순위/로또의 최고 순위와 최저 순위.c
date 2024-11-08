#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = (int*)malloc(2 * sizeof(int));
    bool winByNum[46] = {};
    int mxCnt = 0;
    int mnCnt = 0;
    
    for(int i = 0 ; i < win_nums_len; i++){
        winByNum[win_nums[i]] = true;
    }
    
    for(int i = 0 ; i < lottos_len; i++){
        if(lottos[i] != 0){
            if(winByNum[lottos[i]]){
                mxCnt++;
                mnCnt++;
            }    
        } else{
            mxCnt++;
        }
    }
    
    answer[0] = 7 - mxCnt <= 5 ? 7 - mxCnt : 6 ;
    answer[1] = 7 - mnCnt <= 5 ? 7 - mnCnt : 6;
    
    return answer;
}

/*
    6개 번호중 알아볼수없는 번호, 실제 번호 / 당첨번호와 일치하는 횟수 구하기
    
    가능한 최고 순위 최소순위 반환
*/