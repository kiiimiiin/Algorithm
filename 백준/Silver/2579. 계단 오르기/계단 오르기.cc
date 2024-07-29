#include <iostream>
#include <algorithm>
using namespace std;
int d[302][3];
int step[302]; 
int n, t; 

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n; 
    
    for(int i = 1; i <= n; i++){
        cin >> step[i];
    }
    

    d[1][1] = step[1]; 
    
    for(int i = 2; i <= n; i++){
        
        d[i][2] = d[i-1][1] + step[i]; 
        d[i][1] = max(d[i-2][1], d[i-2][2]) + step[i];
    
    }
    
    cout << max(d[n][1], d[n][2]);
    
}