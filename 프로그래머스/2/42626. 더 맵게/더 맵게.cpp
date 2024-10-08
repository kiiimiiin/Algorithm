#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    bool flag = false;
    
    while(1) {
        if(pq.top() >= K){
            flag = true;
            break;
        }
        
        if(pq.size() < 2)
            break;
        
        int val = pq.top();
        pq.pop();
        val += 2 * pq.top();
        pq.pop();
        pq.push(val);
        answer++; 
    }
    
    return (flag ? answer : -1 );
}

/*
     모든 음식의 스코빌 지수가 K 이상 -> 가장 작은 음식도 K이상이여야함
     
     최소힙)
     
     힙의 사이즈가 2 이상인동안 
     
     힙의 탑이 k보다 크면 break
     힙의 탑이 k보다 작으면 섞기 진행

*/