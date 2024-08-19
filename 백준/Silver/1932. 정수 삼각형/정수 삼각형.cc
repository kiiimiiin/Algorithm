#include <iostream>
#include <algorithm>
using namespace std;
int d[502][502];
int n, x;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> x;
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + x; 
        }
    }
    
    cout << *max_element(d[n] + 1, d[n] + n + 1); 
}


/*
    d[i][j] : i번째 행에서 j열을 택했을 때까지의 최대값

    d[1][1] = 7
    
    d[2][1] = max(d[1][0] ,d[1][1] ) + num[i][j];
    d[2][2] = max(d[1][1] ,d[1][2] ) + num[i][j];
    
    d[i][j] = d[i-1][j-1] + d[i-1][j];
     
*/