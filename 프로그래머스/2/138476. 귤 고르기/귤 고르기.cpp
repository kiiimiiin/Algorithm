#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int mx = *max_element(tangerine.begin(), tangerine.end());
    vector<int> v(mx + 1, 0);
    for(auto x : tangerine)
        v[x]++;
    
    sort(v.begin(), v.end(), greater<int>());
    
    
    for(auto cnt : v){
        if(cnt == 0) continue;
        k -= cnt;
        answer++;
        if( k <= 0 ) break;
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