#include <bits/stdc++.h>
using namespace std;
int dp[1002][3]; // 집의 갯수, 색에 대한 정보 r,g,b 
int n;
int r[1002], g[1002], b[1002];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
    }
    
    dp[1][0] = r[1]; dp[1][1] = g[1]; dp[1][2] = b[1];
    for(int i = 2 ; i <= n ; i++)
    {
        dp[i][0] = min(dp[i-1][1] , dp[i-1][2] ) + r[i]; // i번쨰에 red를 골랐을 경우에 대한 최소
        dp[i][1] = min(dp[i-1][2] , dp[i-1][0] ) + g[i]; // green
        dp[i][2] = min(dp[i-1][0], dp[i-1][1] ) + b[i]; // blue 
    } // i번째의 r,g,b를 골랐을 떄의 각각에 대한 최솟값이 구해짐
    
    cout << *min_element(dp[n], dp[n] + 3);
    // 그 중에서 최소가 비용에 대한 최소다 
}