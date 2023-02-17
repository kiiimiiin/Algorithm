#include <bits/stdc++.h>
using namespace std;
int arr[10];
int n, m;

void backTracking(int idx) // 현재 수열의 길이
{
    if(idx == m)
    {
        for(int i = 0; i < m ; i++)
            cout << arr[i] << ' '; 
        cout << '\n';
        return ;
    }
    
    for(int i = 1; i <= n; i++)
    {
        arr[idx] = i;
        backTracking(idx + 1);
    }
}
int main()
{
    cin >> n >> m;
    backTracking(0);
}