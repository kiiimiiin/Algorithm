#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> S; // {주식가격, 인덱스}
    S.push({-1, -1});
    
    for(int i = 0; i < prices.size(); i++){
        
        while(S.top().first > prices[i]){
            answer[S.top().second] = i - S.top().second;
            S.pop();
        }
        
        answer[i] = ( prices.size() - 1) - i; 
        S.push({prices[i], i});
        
    }
    
    return answer;
}