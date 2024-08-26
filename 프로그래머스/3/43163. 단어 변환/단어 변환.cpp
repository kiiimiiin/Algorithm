#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool IsOneDifferent(string s1, string s2){
    int cnt = 0;
    for(int i = 0 ; i < s1.length(); i++){
        if(s1[i] != s2[i]) cnt++;
    }
    
    if(cnt == 1) return true;
    return false; 
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    int tIdx = -1;
    vector<int> vis(n);
    queue<pair<string, int>> q;
    
    for(int i = 0; i < n; i++){
        if(target == words[i]){
            tIdx = i;
            break;
        }
    }
    
    if(tIdx == -1) return 0;
    
    q.push({begin, 0});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        string curs = cur.first;
        int level = cur.second;
        
        if(curs == target && vis[tIdx]){
            answer = level;
            break;
        }
        
        for(int i = 0 ; i < n; i++){ // 하나만 다르면 q넣고 방문처리
            if(vis[i]) continue;
            if(IsOneDifferent(curs, words[i])){
                q.push({words[i], level + 1});
                vis[i] = true;
            }
        }
    }
    return answer;
}


/*
    글자수가 한글자 씩 다른경우에 bfs를 진행한다.
    가장 먼저 target을 방문했을 때 bfs를 그만둔다.
*/