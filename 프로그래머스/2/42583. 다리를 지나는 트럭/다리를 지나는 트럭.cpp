#include <string>
#include <iostream>
#include <utility>
#include <deque> 
#include <vector>
#define W first
#define T second

using namespace std;

int getOnTruckWeight(deque<pair<int,int>>& bridge){
    int sum = 0;
    for(auto t : bridge){
        sum += t.W;
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_num = truck_weights.size(); 
    
    vector<int> passed_trucks;
    deque<pair<int,int>> trucks_on_bridge; // 트럭무게, 빠질시간
    
    int pop_time = -1;
    int waiting_idx = 0;
    
    while(passed_trucks.size() != truck_num){
        
        answer++;
        
       
        
        int waiting_truck = truck_weights[waiting_idx];
        
        if(!trucks_on_bridge.empty() && trucks_on_bridge.front().T == answer){
            passed_trucks.push_back(trucks_on_bridge.front().W);
            trucks_on_bridge.pop_front();
        }
        
        if(trucks_on_bridge.size() < bridge_length && 
           (getOnTruckWeight(trucks_on_bridge) + waiting_truck) <= weight){
            // 다리 위 트럭 수가 다리 길이보다 작고
            // 다리 위 트럭 무게와 건널 대기 트럭 무게합이 한도무게와 작거나 같을 때 트럭이 건넘
            
            pop_time = answer + bridge_length; 
            
            trucks_on_bridge.push_back({waiting_truck, pop_time});
            
            waiting_idx++;
            
            cout << "(" << waiting_truck << "," << pop_time << ")\n" ; 
            
        }
        
        
        
        
        
    }
    
    return answer;
}

