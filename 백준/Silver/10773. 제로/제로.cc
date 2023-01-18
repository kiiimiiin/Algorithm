#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int k, num, size, sum = 0;
    
    stack<int> S;

    cin >> k;

    while(k--)
    {
        cin >> num;
        if(num == 0)
        {
            if(!S.empty()) S.pop(); 
        }
        else
        {
            S.push(num);
        }
    }
    
    size = S.size();
    while(size--)
    {
        sum += S.top();
        S.pop();
    }
    cout << sum << '\n';
}