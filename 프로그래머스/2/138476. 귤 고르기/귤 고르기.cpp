#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> m;
    priority_queue<int> pq;
    
    for(auto x : tangerine)
        m[x]++;
    for(auto e : m)
        pq.push(e.second);
    
    while(!pq.empty()){
        answer++;
        k -= pq.top();
        pq.pop();
        if(k <= 0) break;
    }
    return answer;
}

/*
    1 2 3 4 5
    1 2 2 1 2
    
    6개 택 -> 해당 종류 갯수가 가장 큰 원소부터
*/