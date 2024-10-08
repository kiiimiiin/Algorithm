#include <bits/stdc++.h>
#define PRIORITY first
#define LOCATION second

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> dq;
    priority_queue<int> pq(priorities.begin(), priorities.end());
    
    for(int idx = 0; idx < priorities.size(); idx++){
        dq.push_back(make_pair(priorities[idx], idx));
    }
    
    while(!dq.empty()){
        auto process = dq.front();
        auto mx = pq.top();
    
        if(process.PRIORITY < mx){
            dq.pop_front();
            dq.push_back(process);
        } else {
            dq.pop_front();
            pq.pop();
            answer++;
            if(process.LOCATION == location)
                break; 
        }
    }
    
    return answer;
}

/*
    덱의 맨앞원소보다 큰 우선순위가 있는 지 확인 있으면 다시 뒤로 넣음
    없으면 해당 원소를 뺌, 이 때 원소가 기존 몇번 인덱스인지 알아야함.
    인덱스가 location과 동일하면 종료
    
    dq
    
    pr : 2 1 3 2
    idx: 0 1 2 3
         a b c d
         
         b c d a
         c d a b
         d a b | c
         a b | c d
         b | c d a
         c d a b
         

    
*/