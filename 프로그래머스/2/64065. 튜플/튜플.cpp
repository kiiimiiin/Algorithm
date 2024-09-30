#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_set<int> set;
    vector<vector<int>> tups;
    vector<int> tup;
    
    bool flag = false;
    string tmp = "";
    for(int i = 1; i < s.length() - 1; i++){
        if(flag){
            if(isdigit(s[i])){
                tmp.push_back(s[i]);
            } else if(s[i] == ','){
                tup.push_back(stoi(tmp));
                tmp = "";
            } else if(s[i] == '}'){
                tup.push_back(stoi(tmp));
                tups.push_back(tup);
                tmp = "";
                tup.clear();
                flag = false;
            }
            continue;
        }
        
        if(s[i] == '{')
            flag = true;
    }
    
    sort(tups.begin(), tups.end(), cmp);
    set.insert(tups[0][0]); 
    answer.push_back(tups[0][0]); 
    for(int i = 1; i < tups.size(); i++){
        for(int j = 0 ; j < tups[i].size(); j++){
            if(set.find(tups[i][j]) == set.end()){
                set.insert(tups[i][j]);
                answer.push_back(tups[i][j]);
                break;
            }
        }
    }

    
    return answer;
}

/*
    숫자만나면 tmp에추가
    , 만나면 tmp를 tup에추가
    } 만나면 tups에 tup 추가
*/