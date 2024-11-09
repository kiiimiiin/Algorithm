#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    long long d[2002];
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i-1] + d[i-2])%1234567;
    answer = d[n];
    return answer;
}

/*
    dp[i] = i번째 칸 도달 방법수
    dp[i] = dp[i - 1] + dp[i - 2];
    
    dp[1] = 1
    dp[2] = 2
*/