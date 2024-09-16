#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i = 1; i <= n / 2; i++){
        int sum = i;
        for(int j = i + 1; j < n; j++){
            sum += j;
            if(sum > n) break;
            if(sum == n) { answer++; break;}
        }
    }
    return answer;
}

/*
    1부터
    
    15 / 2 + 1 = 8 까지
    
    16 / 2 = 8 까지
    
    1부터 8까지 순회하며 연속합이 15일때마다 cnt 

*/