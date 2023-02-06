#include <bits/stdc++.h>
using namespace std;
int cnt, n; 

void func(int tot) // 합이 n이 될 때 cnt올림
{
    if(tot >= n)
    {
        if(tot == n) cnt++;
        return ;
    }
    func(tot+1);
    func(tot+2);
    func(tot+3);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        func(0);
        cout << cnt << '\n';
        cnt = 0;
    }
}