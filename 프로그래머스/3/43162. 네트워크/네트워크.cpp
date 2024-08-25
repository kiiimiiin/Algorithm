#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> vis(n);
    queue<int> q;
   
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            answer++;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(int j = 0 ; j < n; j++){
                    if(!vis[j] && computers[cur][j]){
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
        }
    }    
    return answer;
}


/*

컴퓨터를 차례로 방문
연결되어 있는 컴퓨터 bfs
방문한 컴퓨터면 pass

*/