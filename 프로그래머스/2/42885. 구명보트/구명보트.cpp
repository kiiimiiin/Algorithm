#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    deque<int> dq(people.begin(), people.end());
    
    
    while(!dq.empty()){
        if (dq.size() >= 2 && dq.front() + dq.back() <= limit){
            dq.pop_front();
            dq.pop_back();
        } else
            dq.pop_back();
        answer++;
    }
    return answer;
}

/*
    가장 작은 무게 + 큰 무게
    -> 무게 제한 넘으면 큰무게만 구출
    -> 안 넘으면 둘다 구출
*/