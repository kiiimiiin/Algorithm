#include <bits/stdc++.h>
using namespace std;
// 1. 정수갯수 N (1~100)
// 2. 정수 입력 (-100~100)
// 3. v 찾아서 갯수 출력

int positive[101], negative[101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a, v;
    
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a >= 0) positive[a]++;
        else negative[-a]++;
    } // O(N)

    cin >> v;
    if( v >= 0) cout << positive[v];
    else cout << negative[-v];
}