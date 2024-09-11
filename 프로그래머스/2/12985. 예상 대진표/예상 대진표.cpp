#include <iostream>
using namespace std;

bool IsFighted(int a, int b){
    return (a / 2 + a % 2) == (b / 2 + b % 2); 
}

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(!IsFighted(a, b)){
        answer++;
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
    }

    return answer;
}

/*
    1024 * 1024
    
    A : 4 -> 2 -> 1
    
    B : 7 -> 4 -> 2 
    
    x / 2  + x % 2 가 다음라운드 번호
    
    3 4 이런 경우가 싸움
    
    4 5 이런 경우는 싸우는게 아님
*/