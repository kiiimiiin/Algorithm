#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = health;
    int t = 0;
    int gage = 0;
    int attackIdx = 0;
    
    while(attackIdx != attacks_rows){
        t++;
        gage++;
        if(t == attacks[attackIdx][0]){ // 1.몬스터 공격
            answer -= attacks[attackIdx++][1];
            gage = 0;
            if(answer <= 0){
                answer = -1;
                break;
            }
            continue;
        }
        
        answer += bandage[1];
        if(gage >= bandage[0]){
            answer += bandage[2];
            gage = 0;
        }
            
        if(answer >= health) answer = health;
        
    }
    
    
    return answer;
    
}

/*
    t가 1초씩 증가
    1. 몬스터가 공격가능 하면 bandage 초기화
        1.1 체력이 0이하되면 종료
    2. bandage 1초씩증가하며 초당 체력 증가
        2.1 bandage가 시전시간에 달하면 추가회복
*/