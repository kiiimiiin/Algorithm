#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool vis[202] = {};
    queue<int> q;
    
    
    for(int i = 0 ; i <  computers.size(); i++){
        if(vis[i]) continue;
        answer++;
        q.push(i);
        vis[i] = true;
        
        while(!q.empty()){
            int idx = q.front(); q.pop();
            for(int j = 0 ; j < computers[idx].size(); j++){
                if(vis[j] || computers[idx][j] == 0) continue;
                vis[j] = true;
                q.push(j);        
            }   
        }   
    }
    
    return answer;
}

// a-b-c a-c 정보교환 o 