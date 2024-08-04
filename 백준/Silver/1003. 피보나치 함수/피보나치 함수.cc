#include <bits/stdc++.h>
using namespace std;
int dp[45][2]; // fibo(i)에 대한 fibo(0), fibo(1) 함수의 호출횟수
int n,t;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    dp[0][0] = 1; dp[0][1] = 0; 
		dp[1][0] = 0; dp[1][1] = 1;
    
    for(int i = 2 ; i <= 40; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];        
    }
    while(t--)
    {
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }    
}