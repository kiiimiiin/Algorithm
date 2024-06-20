#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    
    while(1){
        stack<char> S; 
        string flag = "yes";
        
        getline(cin, s);
        if(s == ".") break;
        
        for(auto c : s){
            if(c == '(' || c == '['){ // 여는 괄호 -> 스택 추가
                S.push(c);
            }
            else if(c == ')' || c == ']'){ // 닫힌 괄호
                   if(S.empty()){ // 앞이 비어있음 -> fail
                        flag = "no";
                        break;   
                   }
                   
                   if(S.top() == '(' && c == ')' ||
                    S.top() == '[' && c == ']' ){
                        S.pop(); // 짝을 찾으면 pop   
                   }
                   else{ // 짝과 다름 -> fail
                       flag = "no";
                       break;   
                   }
            }
        }
        
        
        if(!S.empty()) // 스택에 열린괄호 존재 -> fail 
            flag = "no";
        
        cout << flag << '\n';
    }
    
}