#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int n : arr){
        if(n % divisor == 0) answer.push_back(n);
    }
    
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    
    return answer;
}