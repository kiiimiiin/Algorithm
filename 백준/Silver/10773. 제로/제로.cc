#include <iostream>
#include <stack>
using namespace std;


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> s; 
    int k;
    int sum = 0; 
    
    cin >> k; 
    
    for(int i = 0;  i < k; i++){
        int n;
        
        cin >> n;
        
        if(n != 0){
            s.push(n);
        } else {
            s.pop(); 
        }
    }
    
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    
    cout << sum; 
    
}