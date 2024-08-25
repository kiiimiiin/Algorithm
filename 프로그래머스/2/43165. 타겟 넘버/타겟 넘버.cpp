#include <string>
#include <vector>
using namespace std;
int answer;
bool vis[22];

void dfs(vector<int>& numbers, int target, int sum, int k){
    if(k == numbers.size()){
        if(sum == target) answer++;
        return ;
    }
    
    dfs(numbers, target, sum + numbers[k], k + 1);
    dfs(numbers, target, sum - numbers[k], k + 1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}