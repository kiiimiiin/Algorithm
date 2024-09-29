#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.top() < K){
        if(pq.size() == 1){
            answer = -1;
            break;
        }
        
        int newVal = pq.top();
        pq.pop();
        newVal += pq.top() * 2;
        pq.pop();
        pq.push(newVal);
        answer++;
    }
    
    return answer;
}

/*
    최소힙의 top값이 k이상이면 break
    하나 남으면서 k보다 작으면 -1이며 break
    최소힙에서 2개씩 섞으며 push
*/