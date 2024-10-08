#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(auto c : s){
        if(c == '(')
            st.push(c);
        
        else{
            if(!st.empty())
                st.pop();
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(!st.empty()) answer = false;
    return answer;
}

/* 
    열린괄호 - push
    닫힌괄호 - 열린괄호 있으면 pop
            - 열린괄호 없으면 x
    
    스택에 열린괄호 남아있으면 x
*/