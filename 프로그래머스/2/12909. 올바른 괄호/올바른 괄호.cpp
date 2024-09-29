#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(auto c : s){
        if(c == '(') st.push(c);
        else {
            if(st.empty()){
                answer = false;
                break;
            }
            else
                st.pop();
        }
    }
    
    if(!st.empty()) answer = false;
    
    return answer;
}

/*
    열린괄호 푸쉬
    닫힌괄호 ->
    열린괄호 없으면 x
    열린괄호 있으면 pop
    
    괄호남아있으면 x
*/