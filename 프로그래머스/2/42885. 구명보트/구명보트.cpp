#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end()); 
    
    int idx = 0; // 다음에 태우고자하는 최소인덱스
    
    while(idx < people.size() ){
        if(people.back() + people[idx] <= limit){
            people.pop_back();
            idx++;
            answer++;
        }else{
            people.pop_back();
            answer++;
        }
    }    
    return answer;
}

/*
    오름차순 sort
    *** 보트는 최대 2명씩 밖에 탈 수 없다!!!
    
    -최대 + 최소가 limit내이면 보트에 2명태운다
    -limit을 넘어가면 최대 하나만 태운다

*/