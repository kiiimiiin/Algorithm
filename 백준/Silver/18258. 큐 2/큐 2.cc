#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<int> Q;
    int n, x; 
    string init; 

    cin >> n;
    while(n--)
    {
        cin >> init;
        if(init == "push")
        {
            cin >> x;
            Q.push(x);  
        }
        else if(init == "pop")
        {
            if(Q.empty()) cout << -1 << '\n';
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(init == "size") cout << Q.size() << '\n';
        else if(init == "empty") cout <<(int)Q.empty()<< '\n';
        else if(init == "front")
        {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.front() << '\n';
        }
        else//back
        {
            if(Q.empty()) cout << -1 << '\n';
            else cout << Q.back() << '\n';
        }
    } // O(N)
}