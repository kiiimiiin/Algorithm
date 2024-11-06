#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long sum = 0;
    for(int i = 1; i <= count; i++){
        sum += i * price;
    }
    
    answer = money >= sum ? 0 : sum - money;
    
    
    return answer;
}