#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map <int,int> m;
    priority_queue<int> pq; // 최대힙
    
    for(auto x : tangerine)
        m[x]++;
    
    for(auto x : m){
        pq.push(x.second);
    }
    
    while(k > 0){
        k -= pq.top();
        pq.pop();
        answer++;
    }
    
    return answer;
}

/*
    1 3 2 5 4 5 2 3
    
    2 2 3 3 5 5 1 4
    
    2 2 2 1 1
    
    6 -2 -2 -2 => 3 카운트
    6 -2 -2 -1 -1 => 4 카운트
    
    
    2 3 5를 고르면 6개
    갯수가 많은 순으로 내림차순 ( 종류별 갯수에 대해 알아야함 -> 해시셋)

    O(n) + O(nlogn)
*/