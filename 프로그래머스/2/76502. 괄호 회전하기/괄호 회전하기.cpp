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
            if(c == '(' || c == '[' || c == '{')
                S.push(c);
            else {
                if(S.empty()) { flag = false; break;}
                
                if(IsTwin(S.top(), c)) S.pop();
                else { flag = false; break;}
            }
            
            if(!flag) break; 
        }
        
        if(!S.empty() && flag) flag = false;
        if(flag) answer++;
    }
    return answer;
}

/*
    열린괄호 push
    
    닫힌괄호가 나타날때 
        비어있으면 x
        짝이맞으면 pop
        짝이 안맞으면 x
    
    
    모든 처리를 하고 괄호가 남아있으면 X
*/