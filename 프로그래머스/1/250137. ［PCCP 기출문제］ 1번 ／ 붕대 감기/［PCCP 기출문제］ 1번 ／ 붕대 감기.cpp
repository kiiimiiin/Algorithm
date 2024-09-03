#include <string>
#include <vector>
#include <iostream>
using namespace std;
int attack[1002];
int rt, t, x, y, dt;



int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    
    // init
    int rt = 0; int dt = 0;
    int t = bandage[0]; int x = bandage[1]; int y = bandage[2];
    
    
    for(auto v : attacks){
        attack[v[0]] = v[1];
    }
            
    // action
    
    for(int rt = 1; rt <= attacks[attacks.size()-1][0]; rt++){
       
        if(attack[rt]){ // 몬스터에게 공격
            answer -= attack[rt];
            dt = 0;
            if(answer <= 0) return -1;
            continue;
        }
        
        dt++;
        answer = answer + x <= health ? answer + x : health;
        
        if(dt == t){ // 붕대감기 성공
            answer = answer + y <= health ? answer + y : health;
            dt = 0;
        }
    }
    
    return answer;
}

/*
    붕대감기 : 
    t초동안 1초에 x만큼 체력회복
    -> 감는데 성공하면 ? y만큼 더 회복
    -> 감는데 실패하면 (몬스터에게 공격) ? 다시 붕대감기를 사용해 0으로 초기화
        - 정해진 피해량만큼 줄어듬
        - 체력 0 이하일 시 죽음 :: -1 return
        
    모든 공격이 끝난 후 체력 return

*/