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
    5 / 2 -> 2, 1
    2 / 2 -> 1, 0
    1 / 2 -> 0, 1

    6 / 2 -> 3, 0
    3 / 2 -> 1, 1
    1 / 2 -> 0, 1
*/