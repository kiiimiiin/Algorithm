#include <bits/stdc++.h>
#define MOD 1234567
using namespace std;
long long d[2002];

long long solution(int n) {
    long long answer = 0;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i-1] + d[i-2]) % MOD;
    
    answer = d[n];
    
    return answer;
}

/*
    d[i] : i번째칸을 도달하는데 방법수
    d[i] = d[i-1] + d[i-2];
    
    d[1] = 1
    d[2] = 2
    d[3] = d[1] + d[2] ... 

*/