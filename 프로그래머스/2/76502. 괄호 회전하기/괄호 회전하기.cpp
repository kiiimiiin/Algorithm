#include <bits/stdc++.h>

using namespace std;

bool IsTwin(char t, char c){
    return t == '(' && c == ')' || t == '[' && c == ']' || t == '{' && c == '}' ;
}

bool IsCorrect(string s, int len){
    stack<char> st;
    for(auto c : s){
        if(c == '[' || c == '(' || c == '{')
            st.push(c);
        else{
            if(st.empty()) return false;
            if(!IsTwin(st.top(), c)) return false;
            else st.pop();
        }
    }
    
    if(!st.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    int len = s.length(); 
    
    for(int i = 0 ; i < len; i++){
        rotate(s.begin(), s.begin() + 1, s.end());
        if(IsCorrect(s, len)) answer++;
    }
    
    return answer;
}

/*
    1칸씩 rotate하며 괄호 check
    
    stack
    열린괄호를 처리
    1. 닫힌괄호 없을때 열린괄호 -> X
    2. 닫힌괄호와 열린괄호가 다른짝 -> X
    3. 닫힌괄호와 열린괄호가 같은짝 -> O
    
    닫힌괄호가 남아있음

*/