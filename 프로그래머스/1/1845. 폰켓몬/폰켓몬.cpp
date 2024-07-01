#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> s;
    for(auto e : nums){
        s.insert(e);
    }
    
    answer = min(s.size() , nums.size()/ 2);
    return answer;
}

// 포켓몬 종류 수, 가져갈 포켓몬 수 중 최솟값이 
// 결국 선택할 수 있는 종류수의 최댓값