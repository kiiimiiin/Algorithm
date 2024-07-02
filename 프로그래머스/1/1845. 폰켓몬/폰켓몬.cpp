#include <vector>
#include <algorithm>
using namespace std;
int arr[2000002];

int solution(vector<int> nums)
{
    int answer = 0;
    int c_num = 0;
    
    for(auto e : nums){
        if(arr[e]) continue;
        arr[e]++;
        c_num++;
    }

    
    answer = min(c_num, (int)nums.size() / 2);
    
    
    return answer;
}

// 포켓몬 종류 수, 가져갈 포켓몬 수 중 최솟값이 
// 결국 선택할 수 있는 종류수의 최댓값