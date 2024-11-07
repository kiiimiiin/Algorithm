#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getCnt(int num){
    int ret = 1;
    for(int i = 1; i <= num /2; i++){
        if(num % i == 0) ret++;
    }
    return ret;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++){
        int cnt = getCnt(i);
        if(cnt > limit) answer+= power;
        else answer += cnt;
    }
    return answer;
}

/*

    100000
    * 50000
    
    d[i] : i의 약수의 개수
    d[1] = 1
    d[2] = 2
    d[3] = 2
    d[i ]
*/