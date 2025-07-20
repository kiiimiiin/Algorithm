#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int idx = 0; // 대기 트럭 인덱스
    int total_weight = 0; // 현재 무게
    deque<pair<int,int>> bridge;
    
    while(idx != truck_weights.size()){
        answer++;
        
        for(int i = 0 ; i < bridge.size(); i++)
            bridge[i].second--;
        
        if(!bridge.empty() && bridge.front().second == 0){
            total_weight -= bridge.front().first;
            
            bridge.pop_front();
        }
            
        
        if( total_weight + truck_weights[idx] <= weight && bridge.size() < bridge_length){
            total_weight += truck_weights[idx];
            bridge.push_back({truck_weights[idx], bridge_length});
            cout << truck_weights[idx] << ',' << idx << ' ';
            idx++;
        } 
        

        
    }
    
    if(!bridge.empty()) answer += bridge.back().second;
    
    return answer;
    
}

// bridge_length 만큼의 시간 계산
// weight 제한

// 1 : 7 2
// 2 : 7 1 
// 

