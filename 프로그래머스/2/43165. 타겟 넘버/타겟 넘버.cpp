#include <bits/stdc++.h>
using namespace std;
int answer;

void dfs(vector<int>& numbers, int target, int total, int k){
    if(k == numbers.size()){
        if(total == target)
            answer++;
        return;
    }
    
    dfs(numbers, target, total + numbers[k], k + 1);
    dfs(numbers, target, total - numbers[k], k + 1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    return answer;
}

/*
    N = 20 -> dfs 
    
    수의 끝까지 +, -를 나누며 dfs
*/