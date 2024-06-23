#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
    int cur_weight = 0;
    int time = 0;
    queue<int> wq; // 대기 큐 (무게)
    queue<pair<int,int>> rq; // 건너는 큐 (무게, 다리 건널 시간)
    
    for(auto t : truck_weights){
        wq.push(t);
    }
    
    while(!wq.empty() || !rq.empty()){
        time++; 
        
        if(!rq.empty() && rq.front().second == time){ // 1. 트럭이 다리를 건넘
            cur_weight -= rq.front().first;
            rq.pop();
        }
        
        // 2. 트럭이 다리를 진입
        if(rq.size() >= bridge_length ) continue;
        if(wq.empty() || cur_weight + wq.front() > weight) continue;
           
        cur_weight += wq.front();
        rq.push({wq.front(), time + bridge_length});
        wq.pop();    
        
    }
    
    return time;
}