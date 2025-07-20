#include <string>
#include <vector>
using namespace std;


void dfs(int k, int sum, int target, int& answer, vector<int>& numbers){
    if(k == numbers.size()){
        if(sum == target)
            answer++;
        return ;
    }
    
    dfs(k + 1, sum + numbers[k], target,  answer, numbers);
    dfs(k + 1, sum - numbers[k], target, answer, numbers);
    
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0,  0, target, answer, numbers);
    return answer;
}