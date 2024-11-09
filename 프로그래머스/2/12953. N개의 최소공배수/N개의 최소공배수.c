#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getGcd(int a, int b){
    if(a%b == 0) return b;
    return getGcd(b, a%b);
}

int getLcm(int a, int b){
    return ( a * b ) / getGcd(a, b);
}
int solution(int arr[], size_t arr_len) {
    int answer = arr[0];

    for(int i = 1; i < arr_len; i++)
        answer = getLcm(answer, arr[i]);
    
    return answer;
}

/*
    gcd(a,b)
    a를b로 나누었을때 나누어 떨어지면 b
    아니면 b, a % b를 인자로 반복

*/