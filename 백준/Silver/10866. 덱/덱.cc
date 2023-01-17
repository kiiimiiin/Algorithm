#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, num;
    string init;

    deque<int> D;

    cin >> n;
    while(n--)
    {
        cin >> init;
        if(init == "push_front")
        {
            cin >> num;
            D.push_front(num);
        } 
        else if(init == "push_back")
        {
            cin >> num;
            D.push_back(num);
        }
        else if(init == "pop_front")
        {
            if(D.empty()) cout << -1 << '\n';
            else
            {
                cout << D.front() << '\n';
                D.pop_front();
            }
        }
        else if(init == "pop_back")
        {
            if(D.empty()) cout << -1 << '\n';
            else
            {
                cout << D.back() << '\n';
                D.pop_back();
            }
        }
        else if(init == "size") cout << D.size() << '\n';
        else if(init == "empty") cout << (int)D.empty() << '\n';
        else if(init == "front")
        {
            if(D.empty()) cout << -1 << '\n';
            else cout << D.front() << '\n';
        }
        else // back
        {
            if(D.empty()) cout << -1 << '\n';
            else cout << D.back() << '\n';
        }
    }//O(N)
}