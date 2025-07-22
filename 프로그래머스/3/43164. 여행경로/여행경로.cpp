#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool vis[10002];

bool dfs(string str, int k, vector<string>& answer, vector<vector<string>> tickets){
    if(k == tickets.size()) return true;   
    
    for(int i = 0 ; i < tickets.size(); i++){
        if(vis[i] || tickets[i][0] != str) continue;
        vis[i] = true;
        answer.push_back(tickets[i][1]);
        if(dfs(tickets[i][1], k + 1, answer,  tickets)) return true;
        answer.pop_back();
        vis[i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    dfs( "ICN" , 0, answer, tickets);
    return answer;
}