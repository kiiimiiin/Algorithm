#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int mn = *min_element(arr.begin(), arr.end());
    
    for(int n : arr){
        if(n == mn) continue;
        answer.push_back(n);
    }
    
    return answer.empty() ? vector<int>(1,-1) : answer;
}