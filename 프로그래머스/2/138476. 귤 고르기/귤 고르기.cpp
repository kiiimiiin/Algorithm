#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;
    priority_queue<int> pq; // 최대힙
    
    sort(tangerine.begin(), tangerine.end());
    for(int i = 0; i <  tangerine.size(); i++){
        cnt++;
        if(i == tangerine.size() - 1 || tangerine[i] != tangerine[i+1]){
            pq.push(cnt);
            cnt = 0;
        }
    }

    while(k > 0){
        k -= pq.top();
        pq.pop();
        answer++;
    }
    
    return answer;
}

/*
    갯수가 많은 순으로 담아야함
    
    종류별 갯수를 우선순위 큐에 담는다.

    1 2 2 3 3 4 5 5
    
    k = 6 ) 
    1 2 2 1 2 
    2 2 2 -> 3 종류 
    
    k = 4 ) 
    2 2 -> 2 종류
    
    1 1 1 1 2 2 2 3
    k = 2 ) 
    4 3 1 -> 1 종류
    
*/