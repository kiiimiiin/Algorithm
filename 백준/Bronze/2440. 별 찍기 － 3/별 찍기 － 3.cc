#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, i;
    cin >> n; // n번 반복

    while(n)
    {
        i = n;
        while(i--) cout << '*';
        cout << '\n';
        n--;
    }   
}