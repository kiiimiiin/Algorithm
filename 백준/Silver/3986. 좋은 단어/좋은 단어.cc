#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    int ans = 0;
    
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        string s;
        stack<char> S;
        cin >> s;
        
        for(auto c : s){
            if( !S.empty() && S.top() == c ){
                S.pop();
            }
            else{
                S.push(c);
            }
        }
        
        if(S.empty()) ans++;
    }
    
    cout << ans;
    
    return 0;
}