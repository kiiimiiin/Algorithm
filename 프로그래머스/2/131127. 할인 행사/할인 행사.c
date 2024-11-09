#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// want_len은 배열 want의 길이입니다.
// number_len은 배열 number의 길이입니다.
// discount_len은 배열 discount의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int answer = 0;
    
    for(int i = 0 ; i <= discount_len - 10; i++){
        int tmp[10];
        for(int j = 0; j < number_len; j++)
            tmp[j] = number[j];
        
        int cnt = 0;
        for(int j = i ; j < i + 10; j++){
            for(int k = 0; k < want_len; k++){
                if(strcmp(discount[j], want[k]) == 0 && tmp[k]){
                    tmp[k]--;
                    cnt++;
                }      
            }
        }
        if(cnt == 10) answer++;
    }
    return answer;
}

/*

    discount 순회하며 want에 있는지 찾음
    want에 있으면 number값 감소 없으면 break;
    10000000
*/