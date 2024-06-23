#include <algorithm>
#include <utility>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int,int>> q; // 프로세스 우선순위, location
    
    for(int i = 0 ; i < priorities.size() ; i++){
        q.push_back({priorities[i] ,i });
    }
    
    int answer = 0; 
    while(1){
        
        int mx_pri = (*max_element(q.begin(), q.end())).first;
        
        
        
        if( q.front().first < mx_pri){ // 1. 대기중 프로세스보다 큰 우선순위 존재
            q.push_back(q.front());
            q.pop_front(); 
        }
        else{ // 2. 존재 x -> 프로세스 실행
            answer++;
            if( q.front().second == location ){
                return answer;
            }
            q.pop_front();
        }
    }
    
    return answer;
}