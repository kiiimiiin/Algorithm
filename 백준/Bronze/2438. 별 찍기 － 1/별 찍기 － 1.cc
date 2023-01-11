#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, j;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        j = i;
        while(j--) cout<< '*';
        cout << '\n';
    }
}