#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> S; // 인덱스
    
    for(int i = 0; i < prices.size(); i++){
        
        while(!S.empty() && prices[S.top()] > prices[i]){
            answer[S.top()] = i - S.top();
            S.pop();
        }
        
        answer[i] = ( prices.size() - 1) - i; 
        S.push(i);
        
    }
    
    return answer;
}