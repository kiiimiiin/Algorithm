#include <bits/stdc++.h>
using namespace std;

// 간이 연결리스트는 맨 앞이 더미 node이다. 
// |ABC 포인터가 더미노드를 가르킬때 커서가 맨앞에 있다고 생각하자
// 포인터가 어떤 원소를 가르킬 때 커서가 원소뒤에 있다고 생각한다
// AB|C 

const int MX = 1000005;
int pre[MX], nxt[MX]; //prev 변수명 x
char dat[MX]; 
int unused = 1;

void insert(int addr, char num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traversal(){
    int cur = nxt[0];
    while( cur != -1)
    {
        cout << dat[cur] ;
        cur = nxt[cur];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    fill(pre, pre+MX, -1); 
    fill(nxt, nxt+MX, -1);

    string s;
    int m;
    int cursor = 0;
    
    cin >> s;
    for(auto c : s )
    {
        insert(cursor, c);
        cursor = nxt[cursor];
    }

    cin >> m;
    while(m--)
    {
        char c;
        cin >> c;

        if(c == 'L')
        {
            if(pre[cursor] != -1)
            cursor = pre[cursor];
        }
        else if(c == 'D')
        {
            if(nxt[cursor] != -1)
            cursor = nxt[cursor];
        }
        else if(c == 'B')
        {
            if(pre[cursor] != -1)
            {   
                erase(cursor);
                cursor = pre[cursor];
            }
        }
        else
        {
            char init;
            cin >> init;
            insert(cursor, init);
            cursor = nxt[cursor];
        }
    }
    traversal();
}