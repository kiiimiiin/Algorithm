#include <iostream>
#include <stack>
using namespace std; 

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    int pos = 1;
    string s;
    stack<int> S;
    int n; 
    cin >> n;
    
    for(int i = 0 ; i < n; i++){
        int num; 
        
        cin >> num;
        
        while(pos <= num){
            S.push(pos++);
            s += "+\n";
        }
        if(num == S.top()){
            S.pop();
            s += "-\n";
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    
    cout << s;
    return 0;
}