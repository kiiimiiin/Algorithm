#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n ; i++)
    {
        for( int j = 0; j < n - i; j++) cout << ' ';
        for( int k = 0; k < 2*i - 1; k++) cout << '*';
        cout << '\n';
    } // 1 ~ 5
    for(int i = n -1 ; i > 0 ; i--) // 4 3 2 1
    {
        for( int j = 0; j < n - i; j++) cout << ' ';
        for( int k = 0; k < 2*i - 1; k++) cout << '*';
        cout << '\n';
    } // 6 ~ 9
}