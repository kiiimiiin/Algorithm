#include <string>
#include <vector>

using namespace std;

void dfs(int k, int val, vector<int>& numbers, int& target, int& answer ){
    if(k == numbers.size()){
        if(val == target)
            answer++;
        return ;
    }
    
    dfs(k + 1, val + numbers[k], numbers, target, answer);
    dfs(k + 1, val - numbers[k], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 0, numbers, target, answer);
    
    return answer;
}

/*
    dfs
*/