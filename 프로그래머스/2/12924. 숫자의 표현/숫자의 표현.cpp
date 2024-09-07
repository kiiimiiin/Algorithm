#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i = 1; i <= (n / 2 + 1) ; i++){
        int sum = 0;
        for(int j = i; j <= (n / 2 + 1); j++){
            sum += j;
            if(sum == n){
                answer++;
                break;
            }
            else if( sum > n) break;
        }
    }
    
    return n >= 3 ? answer : 1;
}


/*
    연속합을 차례로 구함
    n과 동일하면 cnt
    n을 넘어가면 x

*/