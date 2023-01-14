#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) // n번출력
    {
        for(int j = 0; j < n - i; j++) cout << ' ';
        int k = 2*i - 1;
        while(k--) cout << '*';
        cout << '\n';
    }
}