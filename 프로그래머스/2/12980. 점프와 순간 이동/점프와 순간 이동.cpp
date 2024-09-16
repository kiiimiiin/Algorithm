#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n){
        if(n % 2) ans++;
        n /= 2;
    }
    return ans;
}

/*
    5에대해
    5는 2 * 2 + 1 해야함
    2는 1 * 2 해야함
    1는 + 1 해야함
    
    6에 대해
    6는 3 * 2 
    3는 1 * 2 + 1
    1는 + 1 
    
    n이 2로 나누어떨어지면 +0
    나누어떨어지지 않으면 +1
    

*/