#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    
    for(int cse = 0 ; cse < ( 1 << n); cse++){
        int brute = cse;
        int val = 0;
        for(int i = 0 ; i < n; i++){
            if(brute % 2)
                val += numbers[i];
            else
                val -= numbers[i];
            brute /= 2;
        }
        
        if(val == target)
            answer++;
    }
    
    return answer;
}

/*
    진법경우
    숫자개수 n개
    2^n 개의 전체 경우
*/