#include <bits/stdc++.h> 
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> st;
    
    for(auto c : s){
        if(!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    
    if(st.empty()) 
        answer = 1;
    return answer;
}

