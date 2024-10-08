#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, int vis[200], vector<vector<int>>& computers, int n){
    for(int idx = 0; idx < n; idx++){
        if(vis[idx]) continue;
        if(computers[cur][idx]){
            vis[idx] = 1;
            dfs(idx, vis, computers, n); 
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int vis[200] = {}; 

    for(int idx = 0; idx < n; idx++){
        if(vis[idx]) continue;
        vis[idx] = 1;
        
        dfs(idx, vis, computers, n);    
        answer++;
    }
    
    return answer;
}

/*  
    각 컴퓨터 순회, 
    인덱스 0순회 : 1, 2 -> 1이랑 연결 vis
    1 순회 : 연결된 것 없음 vis
    --> 네트워크 처리
    
    1은 vis처리되어 넘김 
    
    2순회 : 연결된 것 없음 vis
    --> 네트워크 처리

*/