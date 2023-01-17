#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head, tail = 0;

void push(int num)
{
    dat[tail++] = num;
}

void pop()
{
    head++;
}

int front()
{
    return dat[head]; 
}

int back()
{
    return dat[tail - 1];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, num;
    string init;

    cin >> n;
    while(n--)
    {
        cin >> init;

        if(init == "push")
        {
            cin >> num;
            push(num);
        }
        else if(init == "pop")
        {
            if(tail - head == 0) cout << -1 << '\n';
            else 
            {
                cout << front() <<'\n';
                pop();
            }
        }
        else if(init == "size") cout << tail - head << '\n';
        else if(init == "empty")
        {
            if(tail - head == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(init == "front")
        {
            if(tail - head == 0) cout << -1 << '\n';
            else cout << front() << '\n';
        }
        else if(init == "back")
        {
            if(tail - head == 0) cout << -1 << '\n';
            else cout << back() << '\n';
        }
    } // O(N)
}
