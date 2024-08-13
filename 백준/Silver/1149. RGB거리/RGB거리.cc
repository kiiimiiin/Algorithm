#include <iostream>
#include <algorithm>
using namespace std;
int c[1002][3];
int d[1002][3];
int n;

int main(void){
    cin >> n; 
    for(int i = 1 ; i <= n; i++){
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    
    d[1][0] = c[1][0];
    d[1][1] = c[1][1];
    d[1][2] = c[1][2];
    
    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + c[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + c[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + c[i][2];
    }
    
    cout << min({d[n][0], d[n][1], d[n][2]});
}


/*
    d[i][j] : i번째 집을 j로 칠했을 때 최소 비용
    d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0]
*/