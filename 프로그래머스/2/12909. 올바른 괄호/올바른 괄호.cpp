#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(auto c : s){
        if(c == '(') st.push(c);
        else{
            if(!st.empty()) st.pop();
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
    열린괄호 stack
    닫힌괄호 - 열린괄호 존재시 pop
          -열린괄호 없으면 x

    괄호남으면 x
*/