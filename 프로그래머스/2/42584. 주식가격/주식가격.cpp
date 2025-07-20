#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    for(int i = 0 ; i < prices.size(); i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
        answer[i] = prices.size() - 1 - i;
    }

    return answer;
}

// stack에 idx를 넣다가 top이 이전보다 가격이 떨어지는 경우 시간 수정
// 기존에는 시간을 단순히 계산