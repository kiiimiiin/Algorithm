#include <string>
#include <stack>
#include <iostream> 
using namespace std;

int main(void){
    
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, ans = 0; 
    string s;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        stack<char> S;
        cin >> s;
        
        for(auto c : s){
            if(S.empty()){ // 첫 문자
                S.push(c);
            }
            else{
                if(S.top() != c) S.push(c);
                else S.pop();
            }
        }
        
        if(S.empty()) ans++; 
    }
    
    cout << ans; 
}