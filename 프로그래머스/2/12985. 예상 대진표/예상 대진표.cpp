#include <bits/stdc++.h>
using namespace std;


bool IsFighting(int a, int b){
    return (a % 2 + a / 2 ) == ( b % 2 + b / 2); 
}

int solution(int n, int a, int b)
{
    int answer = 1;

    while(!IsFighting(a, b)){
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
    }
    return answer;
}

/*
    4 -> 2 -> 1
    7 -> 4 -> 2 
    
    4 -> 2 -> 1 -> 0
    15 -> 8 -> 4 -> 2 
    

    a, b가 서로 붙는것은 1,2 3,4 5,6 처럼 같은 영역에 포함되어야함 6,7도 안됨
    즉 다음처리가 같은 번호로 수렴해야됨 3,4 -> 2 / 5,6 -> 3

*/