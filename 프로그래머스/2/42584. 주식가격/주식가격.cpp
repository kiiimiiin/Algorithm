#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
      
    
    for(int i = 0; i < prices.size(); i++){
        
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
        answer[i] = prices.size() - 1 - i;
    }
    
    return answer;
}

/*
    스택에서 현재값이 top prices보다 떨어지는 순간
    그전의 인덱스들에 대해 현재값보다 작은경우, 떨어지도록
    
    그렇지 않으면 끝까지 안떨어지는것
*/