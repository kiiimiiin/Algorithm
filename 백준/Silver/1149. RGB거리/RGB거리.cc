#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[1002][3];
int cost[1002][3];

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];
    
    for(int i = 1; i <= n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[i][2];
    }
    
    cout << min({d[n][0],d[n][1],d[n][2]});
}

/*

    d[i][j] : i번째 집까지 칠하는 비용의 최솟값, 단 j는 칠한 색깔
    
    d[k][0] = min(d[k-1][1], d[k-1][2]) + cost[k][0]

*/