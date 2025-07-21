#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool IsOneDifferent(string str1, string str2){
    int diffCnt = 0 ;
    for(int i = 0 ; i < str1.length(); i++)
        if( str1[i] != str2[i] )
            diffCnt++;
    
    return diffCnt == 1 ;     
}

void dfs(string str, string target, int cnt, int& answer,vector<string>& words, bool vis[]){
    if(str == target){
        answer = min(cnt, answer);
        // cout << str << ' ';
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        if(vis[i] || !IsOneDifferent(str, words[i])) continue;
        // cout << cnt << ' '; 
        vis[i] = true;
        dfs(words[i], target, cnt + 1, answer, words, vis);
        vis[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0x7f7f7f7f;
    bool vis[52] = {};
    dfs(begin, target, 0, answer , words, vis);
    
    return answer == 0x7f7f7f7f ? 0 : answer;
}

/* 
    현재 단어와 하나 다르면 dfs
    target 단어와 같게 되면 단계수 반환 (answer은 최소로 추적)
*/