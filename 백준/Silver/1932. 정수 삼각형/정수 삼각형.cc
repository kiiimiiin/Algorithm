#include <bits/stdc++.h>
using namespace std;
int arr[502][502]; // 위에서 부터 내려오는 층수, 해당 층에 대한 원소의 인덱스
int dp[502][502]; // 위에서 i-1번째 층 까지의 최대합 , j는 i번쨰 층에 대한 원소 인덱스
int n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1 ; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1; i < n ; i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
        dp[i][i] = dp[i-1][i-1] + arr[i][i];
        if( i >= 2)
            for(int j = 1; j <= i-1 ; j++ )
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
    }

    cout << *max_element(dp[n-1], dp[n-1] + n);
}