#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> s;
    string cw = "";
    int i;
    
    for(i = 0 ; i < words.size(); i++){
        if(i > 0){
            if(cw[cw.length() - 1] != words[i][0])
                break;
            if(s.find(words[i]) != s.end())
                break;
        }
        cw = words[i];
        s.insert(words[i]);
    }
    
    if(i == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        int num = i % n + 1;
        int turn = i / n + 1; 
        answer.push_back(num);
        answer.push_back(turn);    
    }
    
    return answer;
}

/*
    ret : 탈락하는 사람 번호, 차례 / 없으면 0, 0
*/