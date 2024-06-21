#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s) {
    ios::sync_with_stdio(0), cin.tie(0);
    bool answer = true;
    
    stack<char> S; // 열린 괄호를 가진 stack
    
    for(auto c : s){
        if(c == '('){
            S.push(c);
        }
        else{
            if(S.empty()){
                answer = false;
                break;
            }
            else{
                S.pop();
            }
        }
    }
    
    if(!S.empty()) answer = false;
    
    return answer;
}