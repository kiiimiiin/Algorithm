#include <bits/stdc++.h>
using namespace std;

// 4 3 2 1
// 2 4 3 | 1 
// 4 2 | 1 3
// 4 | 1 3 2

// 1 2 3 4 
// 3 4 2 
// 2 4
// 4


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    queue<int> Q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) Q.push(i);

    while(Q.size() != 1)
    {
       Q.pop();
       Q.push(Q.front());
       Q.pop();
    }
    cout << Q.front(); 
}