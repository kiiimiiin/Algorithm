#include <bits/stdc++.h>

using namespace std;

bool IsTwin(char t, char c){
    return (t == '[' && c == ']') || (t == '(' && c == ')') || (t == '{' && c == '}');
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    string temp = s;
    for(int i = 0; i < len; i++){
        string temp = s;
        stack<char> S;
        rotate(temp.begin(), temp.begin() + i, temp.end());
        
        bool flag = true;
        
        for(auto c : temp){
            if(S.empty()){
                if(c == ')' || c == ']' || c == '}')
                    flag = false; 
                else S.push(c);
            } else {
                if(c == ')' || c == ']' || c == '}'){
                    if(IsTwin(S.top(), c)) S.pop();
                    else flag = false; 
                }
                else S.push(c);
            }
            
            if(!flag) break; 
        }
        
        if(!S.empty() && flag) flag = false;
        if(flag) answer++;
        
    }
    return answer;
}

/*
    닫힌괄호가 먼저나타나면 X
    열린괄호 push
    
    닫힌괄호에 대해
        열린괄호와 짝이 맞으면 pop
        짝이 맞지 않으면 X
    열린괄호 push
    
    
    모든 처리를 하고 괄호가 남아있으면 X
*/