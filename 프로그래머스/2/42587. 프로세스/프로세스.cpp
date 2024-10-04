#include <bits/stdc++.h>
#define IDX second
#define PR first
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    deque<pair<int,int>> dq; 
    for(int i = 0; i < priorities.size(); i++)
        dq.push_back({priorities[i], i});
    
    while(!dq.empty()){
        auto process = dq.front();
        auto mxProcess = *max_element(dq.begin(), dq.end());
        if(process.PR < mxProcess.PR){
            dq.push_back(process);
            dq.pop_front();
        }else {
            answer++;
            if(process.IDX == location) break;
            dq.pop_front();
        }
          
    }
    
    return answer;
    
}

/*
    priority 길이만큼 순회
    front보다 큰 우선순위 존재 -> back으로
    없으면 -> pop
    
    100 * 100
    
    2 1 3 2
    A B C D
    
    B C D A
    C D A B
    D A B | C
    A B | D
    B | A 
    | B
    
    
*/