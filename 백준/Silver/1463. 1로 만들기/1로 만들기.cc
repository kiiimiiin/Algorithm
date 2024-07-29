#include <bits/stdc++.h>
using namespace std;
int x;
int dist[1000002];
const int MX  = 1000000;
queue<int> Q;

int main()
{
    fill(dist, dist + MX, -1); // 방문 이력 존재하지 않음
    cin >> x ; 
    dist[x] = 0;
    Q.push(x); // 정수 X에 대한 시작점
    while(dist[1] == -1) 
    {
        int cur = Q.front(); Q.pop();
        for( int nxt : {cur - 1 , (cur % 3 ? -1 : cur / 3) , (cur % 2 ? -1 : cur / 2 )})
        {
            if(nxt < 1 || dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[1];  
}