#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int passed = 0;
    int n = truck_weights.size();
    int weight_on_bridge = 0;
    deque<int> dq(truck_weights.begin(), truck_weights.end()); // 대기 트럭
    queue<pair<int,int>> q; // 다리를 건너는 트럭 (무게, 시간)
    
    while(passed != n){
        answer++; 
        
        if(!q.empty() && answer == q.front().second){
            weight_on_bridge -= q.front().first;
            q.pop();
            passed++;
        }
        
        if(!dq.empty()){
            int nxt_weight = dq.front();
            if(q.size() + 1 <= bridge_length && weight_on_bridge + nxt_weight <= weight){
                q.push(make_pair(nxt_weight, answer + bridge_length));
                weight_on_bridge += nxt_weight;
                dq.pop_front();
            }    
        }
        
            
    }
    return answer;
}

/*
   다리에 트럭이 다 건널 시간이라면 다리에서 트럭을 뺀다.
   
   다리무게가 견딜수 있으면, 대기트럭에서 다리로 트럭을 옮긴다.
            견딜 수 없으면, 옮기지 않는다.
    
    트럭을 다리에 옮길때 트럭이 빠지는 시간을 고려해서 같이 넣는다. (무게, 시간)
    
    

*/