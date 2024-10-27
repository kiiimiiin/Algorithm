#include <string>
#include <vector>
using namespace std;
bool vis[202] = {};

void dfs(int cur, vector<vector<int>>& computers){
    for(int j = 0; j < computers.size(); j++){
        if(vis[j]) continue;
        if(computers[cur][j]){
            vis[j] = true;
            dfs(j, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        answer++;
        vis[i] = true;
        dfs(i, computers);
    }
    
    return answer;
}