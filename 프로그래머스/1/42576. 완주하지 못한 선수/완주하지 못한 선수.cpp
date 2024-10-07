#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m; 
    
    for(auto s : completion)
        m[s]++;
    
    for(auto s : participant){
        if(m.find(s) != m.end()){
            m[s]--;
            if(m[s] == 0)
                m.erase(s);
        } else {
            answer = s;
            break;
        }
    }

    return answer;
}